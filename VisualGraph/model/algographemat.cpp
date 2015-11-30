#include "algographemat.h"

using namespace std;

algoGrapheMat::algoGrapheMat(GrapheMat* g): graph(g)
{

}

algoGrapheMat::algoGrapheMat(const algoGrapheMat& other)
    :graph(other.graph)
{

}

GrapheMat* algoGrapheMat::BronKerbosch(GrapheMat const* G)
{
	
    // On trie le graphe selon le nombre décroissant de voisins
//    sort(graph->begin(), graph->end(), SommetMat::neighboorsCompare);
    return maxCliqueBronKerbosch(G, new GrapheMat("Clique Maximale de "+ G->getName()), *(new vector<SommetMat*>), *(new vector<SommetMat*>));
}

GrapheMat* algoGrapheMat::maxCliqueBronKerbosch(GrapheMat const* G, GrapheMat* K, vector<SommetMat*>& C, vector<SommetMat*>& A)
{
    cout << "recherche clique maximale de "<< G->getName()<< endl;
    if (C.empty())	/*noter la clique maximale K*/cout << "clique maximale trouvée  : "<< (*K);
    else	while (A.empty()){
            SommetMat* sommet = A.front();
			// copie utile ?
            GrapheMat Kprime= *K;
            Kprime.push_back(sommet);
			
            // TODO créer la fonction intersection(vector<SommetMat*>& C, ...) std::vector<bool>& ? ou créer fonction qui retourne vector<SommetMat*>
//            vector<SommetMat*>& Cprime= intersection(C, sommet->get_adjacents());
//            vector<SommetMat*>& Aprime= intersection(A, sommet->get_adjacents());
//            //récursion
//            maxCliqueBronKerbosch(G, &Kprime, Cprime, Aprime);

            maxCliqueBronKerbosch(G, &Kprime, C, A);

            // TODO vérifier que pop_back() supprime l'éléments front()
            A.pop_back();
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
