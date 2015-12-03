#ifndef ALGOGRAPHEMAT_H
#define ALGOGRAPHEMAT_H

#include <vector>

#include "../model/graphemat.h"

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
    std::vector<SommetMat*>& intersect(std::vector<SommetMat*>& G1,  std::vector<SommetMat*>& G2);
    
    /**
     * Démarre l'algorithme de recherche de clique Maximum
     * @param G graphe sur lequel on recherche la clique maximum
     * @return vrai si une clique Maximum est trouvée
     */
    static GrapheMat* BronKerbosch(GrapheMat const* G);

    /**
     * @param G graphe dont on cherche la clique maximale,
     * passé en paramètre pour le résultat
     * @param K clique maximale courante
     * @param C liste de sommets adjacents au sommets de la clique courante
     * @param A liste d'adjacents que l'on s'autorise à ajouter (pas déjà tenté)
     * @return
     * TODO retirer K des arguements et le mettre en retour de la fonction
     */
    static GrapheMat* maxCliqueBronKerbosch(GrapheMat const* G, GrapheMat * clique, const std::vector<SommetMat *> &considered);
    static GrapheMat* maxCliqueBronKerboschV2(GrapheMat const* G, GrapheMat* K, std::vector<SommetMat*>& considered, std::vector<SommetMat*>& A);
};

#endif // ALGOGRAPHEMAT_H
