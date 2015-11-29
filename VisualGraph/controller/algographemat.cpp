#include "algographemat.h"

algoGrapheMat::algoGrapheMat(GrapheMat* g): graph(g)
{

}

algoGrapheMat::algoGrapheMat(const algoGrapheMat& other)
    :graph(other.graph)
{

}

/**
 * @param G graphe sur lequel on recherche la clique maximum
 */
GrapheMat* algoGrapheMat::startBronKerbosch(GraphMat const* G)
{
	return maxCliqueBronKerbosch(G, new GraphMat(), new vector<SommetMat*>, new vector<SommetMat*>);
}

/**
 * @param G graphe dont on cherche la clique maximale, 
 * passé en paramètre pour le résultat
 * @param K clique maximale courante
 * @param C liste de sommets adjacents au sommets de la clique courante
 * @param A liste d'adjacents que l'on s'autorise à ajouter (pas déjà tenté)
 * @return
 * TODO retirer K des arguements et le mettre en retour de la fonction
 */
GrapheMat* algoGrapheMat::maxCliqueBronKerbosch(GraphMat const* G, GraphMat const*K, vector<SommetMat*> C, vector<SommetMat*> A) const
{
	if (C.isEmpty())	noter la clique maximale K
	else	while (A.isEmpty()){
			SommetMat* sommet = A.first();
			// copie utile ?
			GraphMat const* Kprime= *K;
			Kprime.pushback(x);
			
			vector<SommetMat*> Cprime= intersection(C, adjacents(x));
			vector<SommetMat*> Aprime= intersection(A, adjacents(x));
			//récursion
			maxCliqueBronKerbosch(G, Kprime, Cprime, Aprime);
			
			A.remove(sommet);
		}

	return K;
}
/* Amélioration :
1: function MaxClique(G,K,C,A) 
2: if C = ? then noter la clique maximale K else 
3: let u ? C tel que |C ??(u)| est maximal in 
4: while A??(u) 6= ? do 
5: choose x ? A??(u) 
6: MaxClique(G,K ?{x},C ??(x),A??(x)) 
7: A ? A?{x} 
8: end while 
9: end function
*/