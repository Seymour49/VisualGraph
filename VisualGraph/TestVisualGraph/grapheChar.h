#ifndef GRAPHEMAT_H
#define GRAPHEMAT_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <boost/iterator/iterator_concepts.hpp>

using namespace std;
/*
 * Classe représentant un graphe sous forme de matrice.
 * On considère le graphe comme un vecteur de sommet, 
 * chaque sommet étant représenté par un identifiant
 * et un vecteur de booleen de taille NbSommet.
 * 
 */

class GrapheChar{
private:
  int NbSommets;
  char ** Matrice;
  
public:
  /*
   * Constructeurs et Destructeur
   */
  GrapheChar():NbSommets(0){}
  GrapheChar(int x){
    NbSommets = x;
    allocMatrice();
    initMatrice();
  }
  GrapheChar(const GrapheChar& g):NbSommets(g.NbSommets){
      allocMatrice();
      for(int i=0; i< NbSommets;++i){
	  for(int j = 0; j < NbSommets; ++j)
	      Matrice[i][j] = g.Matrice[i][j];
      }
      
      
  }
  
  ~GrapheChar(){
      for(int i=0; i< NbSommets; ++i)
	delete[] Matrice[i];
      
      delete []Matrice;
  }

  /*
   * Accesseurs et Mutateurs
   * 
   */
  void deleteSommet(int pos){
    for(int i=0; i< NbSommets; ++i){
      
      Matrice[pos][i] = '0';     
    }
  }
  char** getMatrice(){ return Matrice; };
  int getNbSommet(){ return NbSommets;};
  int getNbVoisins(int pos){
      int res = 0;
      for(int i =0; i< NbSommets; ++i){
	  if(Matrice[pos][i] == '1' ){
	      ++res;
	  }	
      }
      return res;
  }
  /*
   * Display functions
   * 
   */
  ostream& print(ostream& out){
	out << "Graphe : " << endl;
	
	for(int i = 0; i < NbSommets ; ++ i){
	    out << "Sommet " << i << " : ";
	    for(int j = 0; j < NbSommets ; ++j){
		out << Matrice[i][j] ;
	    }
	    
	    out << endl;	  
	}
	return out;
    }
    
    
    friend ostream& operator<<(ostream& out, GrapheChar& r){
	return r.print(out);
    }
  
    /*
     * Allocation et Initialisation
     * 
     */
    
    void allocMatrice(){
      /* Allocation dynamique */
	Matrice = new char* [NbSommets];
	for(int i=0; i < NbSommets; ++i){
	    Matrice[i] = new char[NbSommets];	  
	}
    }
    
    void initMatrice(){
      /* Initialisation */
	for(int i=0; i< NbSommets; ++i){
	    for(int j=0; j< NbSommets; ++j){
		Matrice[i][j] = '0';
	    }	  
	}      
    }
    
    /*
    * Fonctions de compositions  
    * 
    */
    void initline(int pos){
	for(int i=0; i<NbSommets; ++i){
	    Matrice[pos][i] = '0';	  
	}
      
    }
    
    void setline(int pos, char* val){
	Matrice[pos] = val;      
    }
    
    /* Cette fonction retourne un graphe correspondant au graphe
    * induit par les voisins du sommet passé en paramètre.
    * @param int @return GrapheChar* 
    * 
    */
    GrapheChar* voisins(int pos){
      GrapheChar* res = new GrapheChar(getNbVoisins(pos));
      
      for(int i=0; i < res->NbSommets; ++i){
	  // Si Matrice[pos][i] == '1'  le sommet appartient au voisins de pos 
	  if( Matrice[pos][i] == '1' ){
	      char *tmp = Matrice[i];
	      res->setline(i,tmp);
	  }else{
	      res->initline(i);
	  }	
      }
      return res;
    
  }
  
  vector< string >& explode(const string& str)
  {
	istringstream split(str);
	vector< string >* tokens = new vector<string>;
	
	for(string each; getline(split, each, ' '); tokens->push_back( each.c_str()) );
	
	return *tokens;
  }
    
    /*
    * Fonction de chargement d'un graphe sous forme de matrice
    */
    bool tryLoadFile(const string& fileName){
	
	ifstream f(fileName.c_str());
	
	if(!f){
	    cerr << "Erreur pendant l'ouverture du fichier" << endl;
	    return false;      
	}else{
	    string line;
	    
	    while(getline(f,line)){
		// La ligne est un commentaire, on l'ignore simplement
		if(line.substr(0,1) == "c"){  
		  
		}
		// La ligne est une ligne de paramètre nous donnant le nombre de sommets et d'arcs
		else if(line.substr(0,1) == "p"){
		    line = line.substr(6,line.size()-6);
		    string tmp = line.substr(0,line.find_first_of(" "));
		    NbSommets = atoi(tmp.c_str());
		    cout << "Sommets : " << NbSommets  << endl;
		    allocMatrice();
		    initMatrice();
		}else{
		    vector<string>& tokens = explode(line);
		    /* tokens[0] : caractère de controle
		     * tokens[1] : id du sommet source
		     * tokens[2] : id du sommet destination
		     */
		    if(tokens[0] == "e"){
			// Controle ok, on doit mettre à jour deux arcs (graphe non-orienté)
			int src = atoi(tokens[1].c_str());
			int dest = atoi(tokens[2].c_str());
			/* SommetMat
			sommets.at(src)->updateArc(dest);
			sommets.at(dest)->updateArc(src);
			*/
			Matrice[src-1][dest-1] = '1';
			Matrice[dest-1][src-1] = '1';
		    }
		    delete(&tokens);
		}
	    }    
	}
	return true;
      
    }
    
    /*
     * Tests de complétude
     * 
     */
    
    bool isEmpty(){
      
      if(NbSommets < 2){
	  return true;
      }else{
	  
	for(int i = 0; i < NbSommets; ++i){
	    for(int j = 0; j < NbSommets ; ++j) {
		  if(i != j)
		      if( Matrice[i][j] == '1' )
			  return false;
		  
	    }
	  
	}
      }
      return true;
    }
  
    bool isComplete(){
      for(int i = 0; i < NbSommets; ++i){
	  for(int j = 0; j < NbSommets ; ++j) {
		if(i != j)
		    if( Matrice[i][j] == '0' )
			return false;
		
	  }
	
      }
      return true;

    }
    
  
};

#endif