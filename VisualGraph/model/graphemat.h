#ifndef GRAPHEMAT_H
#define GRAPHEMAT_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>

#include "sommetMat.h"

/*
 * Classe représentant un graphe sous forme de matrice.
 * On considère le graphe comme un vecteur de sommet, 
 * chaque sommet étant représenté par un identifiant
 * et un vecteur de booleen de taille NbSommet.
 * 
 */

class GrapheMat {
private:
  std::string name;
  int NbSommets;
  int NbArcs;
  std::vector<SommetMat> sommets;
  
public:
  GrapheMat(std::string s);
  GrapheMat(const GrapheMat& g);
  
  virtual ~GrapheMat();
  
  
  std::vector< std::string >& explode(const std::string& str);
  
  std::ostream& print(std::ostream& out);
    
    
    friend std::ostream& operator<<(std::ostream& out, GrapheMat& r){
	return r.print(out);

    }
    
    void initSommets();
    
    /**
    * Fonction de chargement d'un graphe sous forme de matrice
    */
    bool tryLoadFile(const std::string& fileName);
  
    /**
      * Fonction de calcul de la complétude du Graphe
      */
    bool isComplete();
};

#endif
