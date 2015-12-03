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

    GrapheMat* cliqueInit= new GrapheMat("Clique Maximale de "+ G->getName());

    SommetMat* sommetInitial= G->at(1); // TODO choisir un sommet initial pour commencer la recherche de clique
    vector<SommetMat*>& consideredVertices = *(G->getAdjacents(sommetInitial)); //version avec les adjacents à un seul sommet
    consideredVertices.push_back(sommetInitial);
//    consideredVertices.push_back(sommetInitial);
//    consideredVertices= G->adjacents(consideredVertices); // TODO créer la fonctions qui retourne les sommets tous adjacents à un vector<SommetMat*>

    return maxCliqueBronKerbosch(G, cliqueInit, consideredVertices);
}
/*
 * Version de base, peu performante
1: function MaxClique(G, K, C)
2: if C = ∅ then noter la clique maximale K
3: else for each x ∈ C do MaxClique(G, K ∪ {x}, C ∩ Γ(x))
4: end function
*/
GrapheMat* algoGrapheMat::maxCliqueBronKerbosch(GrapheMat const* G, GrapheMat* clique, vector<SommetMat*> const& considered)
{
    cout << "recherche clique maximale de "<< G->getName()<< endl;
    if (considered.empty() && clique->size()>1){
        /*noter la clique maximale K*/
        cout << "clique maximale trouvée  : "<< (*clique)<< endl;
    }
    else {
        // On cherche la clique maximale pour chaque sommet considéré
        for (SommetMat* sommet : considered) {
            if (!clique->contains(sommet->get_id())) {
                GrapheMat* copieClique= new GrapheMat(*clique); //TODO créer constructeur par recopie
                                                               // TODO plus tard détruire les copies créer de cliques, sinon fuite mémoire
                copieClique= copieClique->add(sommet);

            // TODO créer la fonction intersection(vector<SommetMat*>& C, ...)
                vector<SommetMat*> newConsidered = G->intersection(considered, *(G->getAdjacents(sommet)));

                GrapheMat* newClique= maxCliqueBronKerbosch(G, copieClique, newConsidered);
                if (newClique->size() > clique->size()){
                    delete clique;
                    clique= newClique;
                    cout << "Clique plus grande trouvée : "<< (*clique)<< endl;
                } else {
                    cout << "La clique maximale trouvée est plus petite que la clique max courante "<< endl;
                }
            }
        }
        return clique;
    }
}
/*
 * Meilleure version :
Candidats autorisés. On peut empˆecher ceci en disant qu’une fois qu’on a  ́enum ́er ́e toutes les cliques
qui contiennent le sommet x, alors on pourra s’interdire de consid ́erer x dans toute la suite. On maintient
donc trois ensembles : la clique courante K, un ensemble de candidats C, et un sous-ensemble A de C
form ́e des sommets qu’on s’autorise `
a ajouter `a K. On aboutit alors `a un algorithme :
1: function MaxClique(G, K, C, A)
2: if C = ∅ then noter la clique maximale K else
else 3: while A = ∅ do
        4: choose x ∈ A
        5: MaxClique(G, K ∪ {x}, C ∩ Γ(x), A ∩ Γ(x))
        6: A ← A − {x}
    7: end while
8: end function
*/
//GrapheMat* algoGrapheMat::maxCliqueBronKerboschV2(GrapheMat const* G, GrapheMat* clique, vector<SommetMat*>& considered, vector<SommetMat*>& A)
//{
//    cout << "recherche clique maximale de "<< G->getName()<< endl;
//    if (considered.empty())	/*noter la clique maximale K*/cout << "clique maximale trouvée  : "<< (*clique);
//    else	while (A.empty()){
//            SommetMat* sommet = A.front();
//            // copie utile ?
//            GrapheMat copieClique= *clique;
//            Kprime.push_back(sommet);
			
//            // TODO créer la fonction intersection(vector<SommetMat*>& C, ...) std::vector<bool>& ? ou créer fonction qui retourne vector<SommetMat*>
////            vector<SommetMat*>& Cprime= intersection(C, sommet->get_adjacents());
////            vector<SommetMat*>& Aprime= intersection(A, sommet->get_adjacents());
////            //récursion
////            maxCliqueBronKerbosch(G, &Kprime, Cprime, Aprime);

//            maxCliqueBronKerbosch(G, &copieClique, C, A);

//            // TODO vérifier que pop_back() supprime l'éléments front()
//            A.pop_back();
//		}

//	return K;
//}


/* Amélioration :
 * Utilisation de pivots. Cette nouvelle version ne signale chaque clique maximale qu’une seule fois, ce
qui est un progr`es. Cependant, elle effectue un appel r ́ecursif par clique, maximale ou non. Pour am ́eliorer
 ̧ca, une id ́ee consiste `
a choisir un sommet u ∈ C (le “pivot”), et `a supposer qu’on a  ́enum ́er ́e toutes les
cliques maximales contenant K ∪ {u}. Alors, nous affirmons que chaque nouvelle clique contenant K
mais pas u doit contenir un nouveau sommet qui n’est pas adjacent `a u. Justification (par l’absurde) :
on  ́etend K en une clique maximale K ∪ S, o`
u tous les  ́el ́ements de S sont adjacents `a u. Alors, comme
u est adjacent `
a tous les  ́el ́ements de K, on trouve que K ∪ S ∪ {u} est une clique plus grosse, ce qui
contredit la maximalit ́e de la pr ́ec ́edente. Il en d ́ecoule imm ́ediatement un nouvel algorithme :

1: function MaxClique(G,K,C,A) 
2: if C = ? then noter la clique maximale K else 
else 3: let u ? C tel que |C ??(u)| est maximal in
    4: while A??(u) 6= ? do
        5: choose x ? A??(u)
        6: MaxClique(G,K ?{x},C ??(x),A??(x))
        7: A ? A?{x}
    8: end while
9: end function
*/
