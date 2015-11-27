#ifndef ALGOGRAPHEMAT_H
#define ALGOGRAPHEMAT_H

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
     * @return vrai si une clique Maximum est trouvée
     */
    bool startBronKerbosch() const;
};

#endif // ALGOGRAPHEMAT_H
