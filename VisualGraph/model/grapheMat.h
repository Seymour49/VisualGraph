#ifndef GRAPHEMAT_H
#define GRAPHEMAT_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "sommet.h"

using namespace std;
/*
 * Classe représentant un graphe sous forme de matrice.
 * On considère le graphe comme un vecteur de sommet, 
 * chaque sommet étant représenté par un identifiant
 * et un vecteur de booleen de taille NbSommet.
 * 
 */

class GrapheMat {
private:
  string name;
  int NbSommets;
  int NbArcs;
  vector<Sommet> sommets;
  
public:
  GrapheMat(string s):name(s){}
  
  vector< string >& explode(const string& str)
  {
	istringstream split(str);
	vector< string >* tokens = new vector<string>;
	
	for(string each; getline(split, each, ' '); tokens->push_back( each.c_str()) );
	
	return *tokens;
  }
  
  ostream& print(ostream& out){
	out << "Graphe : " << name << endl;
	
	for(unsigned int i=1;i<sommets.size();++i){
	    out << sommets.at(i) ;
	}
	
	return out;
    }
    
    
    friend ostream& operator<<(ostream& out, GrapheMat& r){
	return r.print(out);
    }
    
    void initSommets(){
	for(int i=0; i<= NbSommets;++i){
	    Sommet s(i);
	    for(int j=0; j<=NbSommets;++j){
	      // Initialisation du vecteur d'adjacents
		s.valueInit(false);
	    }
	    sommets.push_back(s);
	}
	    
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
		    NbArcs = atoi( line.substr(line.find_first_of(" ")+1, line.size()-tmp.size()).c_str() );
		    cout << "Sommets : " << NbSommets << ", arcs : " << NbArcs << endl;
		    initSommets();
		    
		}else{
		    vector<string>tokens = explode(line);
		    /* tokens[0] : caractère de controle
		     * tokens[1] : id du sommet source
		     * tokens[2] : id du sommet destination
		     */
		    if(tokens[0] == "e"){
			// Controle ok, on doit mettre à jour deux arcs (graphe non-orienté)
			int src = atoi(tokens[1].c_str());
			int dest = atoi(tokens[2].c_str());
			sommets.at(src).updateArc(dest);
			sommets.at(dest).updateArc(src);			
			
		    }
		}
	    }    
	}
	return true;
      
    }
  
  
};

#endif