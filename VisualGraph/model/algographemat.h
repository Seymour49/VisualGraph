#ifndef ALGOGRAPHEMAT_H
#define ALGOGRAPHEMAT_H

#include <vector>
#include <list>
#include <cassert>

#include "../model/graphemat.h"

/**
 * Classe permettant d'utiliser les algorithmes de recherche de clique maximale, avec des méthodes statiques
 * TODO mieux utiliser les pointeurs et références ? (@Florian)
 * TODO faire les versions v2 et v3 (les 2 ?) de BronKerbrosch. Nécessite pas mal de fonctions (intersections et unions)
 * TODO utiliser des vector<bool/byte> ?
 * TODO utiliser seulement des graphes au lieux de vector<SommetMat *> (@Florian)
 */
class algoGrapheMat
{
protected:
    GrapheMat const* graph;
    
public:
    algoGrapheMat(GrapheMat* g);
    algoGrapheMat(const algoGrapheMat& other);

    /**
     * Intersection de deux vecteur de pointeurs de SommetMat
     * @param G1
     * @param G2
     * @return l'intersection sous forme d'un vecteur de pointeurs de SommetMat
     */
//    std::vector<SommetMat*>& intersect(std::vector<SommetMat*>& G1,  std::vector<SommetMat*>& G2);
    
    static GrapheMat* maxClique(GrapheMat* C1, GrapheMat* C2);

    /**
     * Cherche la plus grande clique parmis un eliste de cliques, supprime les autres
     * @param listCliques
     * @return
     */
    static GrapheMat* biggestClique(const std::list<GrapheMat*>& listCliques);

    /**
     * Démarre l'algorithme de recherche de clique Maximum avec la 1ere version de BK
     * @param G graphe sur lequel on recherche la clique maximum
     * @return vrai si une clique Maximum est trouvée
     */
    static GrapheMat* BronKerbosch(GrapheMat const* G);

    /**
     * Démarre l'algorithme de recherche de clique Maximum avec la 2e version de BK
     * @param G graphe sur lequel on recherche la clique maximum
     * @return vrai si une clique Maximum est trouvée
     */
    static GrapheMat* BronKerboschV2(GrapheMat const* G);

    /**
     * @param G graphe dont on cherche la clique maximale,
     * passé en paramètre pour le résultat
     * @param K clique maximale courante
     * @param C liste de sommets adjacents au sommets de la clique courante
     * @param A liste d'adjacents que l'on s'autorise à ajouter (pas déjà tenté)
     * @return
     * TODO retirer K des arguements et le mettre en retour de la fonction
     */
    static std::list<GrapheMat*>& maxCliqueBronKerbosch  (GrapheMat const* G, GrapheMat* clique, const std::vector<SommetMat *> &considered);
    static std::list<GrapheMat*>& maxCliqueBronKerboschV2(GrapheMat const* G, GrapheMat* clique, const std::vector<SommetMat*>& considered, std::vector<SommetMat*>& A);
};

#endif // ALGOGRAPHEMAT_H
