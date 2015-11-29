#ifndef GRAPHEMAT_H
#define GRAPHEMAT_H

#include <algorithm>
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


class GrapheMat : public std::vector<SommetMat *>{
private:
  std::string name;
  int nb_sommets;
  int nb_arcs;

public:

//  CONSTRUCTEURS ET DESTRUCTORS
    GrapheMat(std::string s);
    GrapheMat(const GrapheMat& g);

    virtual ~GrapheMat();

//  GETTERS
    /**
     * @brief getNbSommets
     * @return nombre de sommets
     */
    int getNbSommets() const {return nb_sommets;}

    /**
     * @brief getName
     * @return nom du graphe
     */
    std::string getName() const {return name;}

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
    std::ostream& print(std::ostream& out) const;

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
