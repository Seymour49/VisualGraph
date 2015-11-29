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
     * Démarre l'algorithme de recherche de clique Maximum
     * @param G graphe sur lequel on recherche la clique maximum
     * @return vrai si une clique Maximum est trouvée
     */
    GrapheMat* startBronKerbosch(GrapheMat const* G) const;

    /**
     * @param G graphe dont on cherche la clique maximale,
     * passé en paramètre pour le résultat
     * @param K clique maximale courante
     * @param C liste de sommets adjacents au sommets de la clique courante
     * @param A liste d'adjacents que l'on s'autorise à ajouter (pas déjà tenté)
     * @return
     * TODO retirer K des arguements et le mettre en retour de la fonction
     */
    GrapheMat* maxCliqueBronKerbosch(GrapheMat const* G, GrapheMat* K, std::vector<SommetMat*>& C, std::vector<SommetMat*>& A) const;
};

#endif // ALGOGRAPHEMAT_H
