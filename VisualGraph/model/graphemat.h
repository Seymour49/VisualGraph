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
//  CONSTRUCTEURS ET DESTRUCTORS
    GrapheMat(std::string s);
    GrapheMat(const GrapheMat& g);

    virtual ~GrapheMat();

//  AFFICHAGES
    /**
     * Découpe une ligne du fichier et récupère chaque élément.
     * @param str chaine en entrée à découper
     * @return vecteur de chaine ... TODO UGO comment
     */
    std::vector< std::string >& explode(const std::string& str);

    /**
     * Impression sur un flux du graphe
     * @param out
     * @return le flux donné en paramètre avec le graphe 'imprimé'
     */
    std::ostream& print(std::ostream& out);

    friend std::ostream& operator<<(std::ostream& out, GrapheMat& r)
    { return r.print(out); }

//  AUTRES
    /**
     * Fonction d'initialisation d'un graphe
     */
    void initSommets();

    /**
     * Chargement d'un graphe sous forme de matrice
     * à partir d'un fichier d'exemple
     * @param fileName
     * @return
     */
    bool tryLoadFile(const std::string& fileName);

    /**
      * Fonction de calcul de la complétude du Graphe
      */
    bool isComplete();
};

#endif
