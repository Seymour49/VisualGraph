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
 * TODO @see ATTENTION le nb de sommet n'est pas incrémenté avec add() ni push_back() (redéfinir ?),
 *      il est tjr identique au nombre de sommet total dans le plus grand graphe (père de tous les graphe)
 * TODO un constructeur par recopie
 * TODO optimiser ???
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

    void vider();

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

    friend std::ostream& operator<<(std::ostream& out, GrapheMat const& r)
    { return r.print(out); }

    friend std::ostream& operator<<(std::ostream& out, GrapheMat& r)
    { return r.print(out); }

// OPERATEURS
    /**
     * Union entre un graphe et un sommet, on vérifie que le sommet n'est pas
     *  déjà dans le graphe avant de l'ajouter
     * @see une allocation est faite, il faut libérer la mémoire par la suite
     * @param G graphe
     * @param sommet
     * @return union des 2
     */
    GrapheMat* add(SommetMat* sommet);

    /**
     * Retourne les adjacents d'un sommet sous forme d'un vecteur de pointeurs sur SommetMat
     * @param sommet dont on veut les adjacents
     * @return un pointeur sur un vecteur contenant les adjacents du sommet
     */
    vector<SommetMat*>* getAdjacents(SommetMat* sommet) const;

//  AUTRES
    /**
     * Fonction d'initialisation d'un graphe
     */
    void initSommets();

    /**
     * Cherche si le graphe contient un sommet donné
     * @param id id du sommet que l'on cherche dans le graphe
     * @return vrai si le sommet est dans le graphe
     */
    bool contains(int id) const;

    /**
     * intersection entre 2 vecteur de sommets
     *  conserve l'ordre du premier vecteur
     * @param v1 premier vecteur
     * @param v2 second vecteur
     * @return intersection de v1 et v2
     */
    std::vector<SommetMat *>& intersection(const std::vector<SommetMat *>& v1, const std::vector<SommetMat *>& v2) const;

    /**
     * Chargement d'un graphe sous forme de matrice
     * à partir d'un fichier d'exemple
     * @param fileName
     * @return faux si le chargement du fichier échoue
     */
    bool tryLoadFile(const std::string& fileName);

    /**
      * Fonction de calcul de la complétude du Graphe
      */
    bool isComplete();
};

#endif
