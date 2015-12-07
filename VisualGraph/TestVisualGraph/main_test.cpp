#include <boost/concept_check.hpp>
#include <iostream>

#include "grapheChar.h"

using namespace std;

/*

vector<vector<bool>> setIntersectionVS(vector<vector<bool>> v1, vector<bool> s){
     vector<vector<bool>> res;
     
     if(v1.size() == 0){
	return res;
       
     }else{
	  for(unsigned i = 0; i < v1.size() ; ++i){
	      if ( v1.at(i) == s )
		    res.push_back(s);
	  }
	  return res;
     }    
}

vector<vector<bool>> setIntersectionVV(vector<vector<bool>> v1, vector<vector<bool>> v2){
     vector<vector<bool>> res;
     
     if(v1.size() == 0 || v2.size() == 0){
	return res;
       
     }else{
	  if(v1.size() <= v2.size()){
	      for(unsigned i = 0; i < v1.size() ; ++i){
		  if( v1.at(i) == v2.at(i) )
		      res.push_back(v1.at(i));
	      }
	  }else{
	      for(unsigned i = 0; i < v2.size() ; ++i){
		  if( v1.at(i) == v2.at(i) )
		      res.push_back(v2.at(i));
	      }    
	    
	  }
	  return res;
     }    
}

vector<vector<bool>> setUnionVS(vector<vector<bool>> X, vector<bool> s){
      vector<vector<bool>> res = X;  
    if(setIntersectionVS(res, s).size() == 0)
	    res.push_back(s);	

    return res;  
  
}

vector<vector<bool>> setUnionVV(vector<vector<bool>> v1, vector<vector<bool>> v2){
    vector<vector<bool>>res;
    if(v1.size() > v2.size() ){
	res = v1;
	for(unsigned int i=0; i < v2.size() ; ++i)
	    if(setIntersectionVS(res, v2.at(i)).size() == 0)
		res.push_back(v2.at(i));	
    }else{
	res = v2;
	for(unsigned int i=0; i < v1.size() ; ++i)
	    if(setIntersectionVS(res, v1.at(i)).size() == 0)
		res.push_back(v1.at(i));	
    }

    return res;

}

vector<vector<bool>> voisins(GrapheMat g, vector<bool> ligne){
    vector<vector<bool>> res;
    
    for(unsigned i = 0; i < g.getMatrice().size(); ++i){
	if(ligne[i] == true)
	    res.push_back(g.getMatrice().at(i));
    }
    return res;
}

void BK(GrapheMat g, vector<vector<bool>> R, vector<vector<bool>> P, vector<vector<bool>> X){
    if(P.size() == 0 && X.size() == 0){
	  cout << "Clique Maximal détectée" << endl;
	
    }
    else{
	for(unsigned i = P.size() -1; i >=0; --i){
	    vector<bool> ligne = P.at(i);
	    
	    cout << "travail en cours " << endl;
	    BK(g,setIntersectionVV(voisins(g,ligne)), setUnionVS(R,ligne), setIntersectionVV(X,voisins(g,ligne)));
	    
	    X = setUnionVS(X,ligne);
	    P.pop_back();

	}
      
    }
}

*/

void interGrapheGraphe(GrapheChar *g1, GrapheChar* g2){
  
  
  }

void unionGrapheSommet(GrapheChar *g, char* s){
  
  
}


void BK(GrapheChar* R, GrapheChar* P, GrapheChar* X){
   if(P->isEmpty() && X->isEmpty() ){
      cout << "Clique maximale detectée" << endl;
      cout << *R << endl;     
   }else{
      for(int i=0; i< P->getNbSommet(); ++i){
	  cout << "work in progress." << endl;
	  
	  // R u P[i] ; P n Voisins(P[i]) ; X n Voisins(P[i])
	  
	  
	
      }
     
   }
  
}

int main(int argc, char **argv) {

    GrapheChar *g = new GrapheChar();
    
    if(g->tryLoadFile(argv[1])){
	cout << *g << endl;
	
	if(g->isComplete())
	    cout << "Complet" << endl;
	else if(g->isEmpty()) 
	    cout << "Vide" << endl;
	    
	GrapheChar *P = new GrapheChar(*g);
	cout << *P << endl;
	if(P->isComplete())
	    cout << "Complet" << endl;
	else if(P->isEmpty()) 
	    cout << "Vide" << endl;
	/*
	GrapheChar *X = new GrapheChar(g->getNbSommet());
	cout << "X" << endl;
	cout << *X << endl;
	if(X->isComplete())
	    cout << "Complet" << endl;
	else if(X->isEmpty()) 
	    cout << "Vide" << endl;
	
	GrapheChar *R = new GrapheChar(g->getNbSommet());
	cout << "R" << endl;
	cout << *R << endl;
	if(R->isComplete())
	    cout << "Complet" << endl;
	else if(R->isEmpty()) 
	    cout << "Vide" << endl;
	
	*/
	cout << "Test voisins" << endl << P->getNbVoisins(8);
	
	GrapheChar* V = P->voisins(8);
	
// 	V = P->voisins(8);
	/*
	cout << "Affichage du graphe engendré par les voisins du sommet 8" << endl;
	
	for(int i=0; i < P->getNbSommet(); ++i){
	    if(P->getMatrice()[8][i] == '1' ){
		  cout << "Sommet " << i << " : " ;
		  for(int j=0; j< P->getNbSommet(); ++j){
		      cout << P->getMatrice()[i][j] ;
		  }
		  cout << endl;
	    }
	}
	
	cout <<"V a "<< V->getNbSommet() << "sommets " << endl;
	cout << *V << endl;
	*/
	delete(g);
	delete(P);
// 	delete(X);
// 	delete(R);
	delete(V);

    }
    else{
	cout << "Erreur de fichier" << endl;      
    }

    return 0;
}
