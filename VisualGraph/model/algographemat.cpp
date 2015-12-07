#include "algographemat.h"

using namespace std;

algoGrapheMat::algoGrapheMat(GrapheMat* g): graph(g)
{

}

algoGrapheMat::algoGrapheMat(const algoGrapheMat& other)
    :graph(other.graph)
{

}

// @see utiliser une variable plutot que 2 return ?
GrapheMat* algoGrapheMat::maxClique(GrapheMat* C1, GrapheMat* C2){
    assert(C1 != C2); // Pour éviter de libérer la zone mémoire que l'on va retourner
    if (C1->size() > C2->size()){
        delete C2;
        cout << "Clique plus grande trouvée de taille "<< C1->size()<< endl;
        return C1;
    } else {
        delete C1;
        cout << "Clique plus grande trouvée de taille "<< C2->size()<< endl;
        return C1;
    }
}

GrapheMat* algoGrapheMat::biggestClique(const std::list<GrapheMat *> &listCliques)
{
    cout << "recherche clique max parmi " << listCliques.size()<< " cliques"<< endl;
    GrapheMat* max= new GrapheMat("Clique vide pour recherche clique max");
    for (GrapheMat* G: listCliques){
        // On pourrait utiliser maxClique()
        if (max->size() < G->size()){
            delete max;
            max= G;
        } else delete G;
    }
    cout << "Clique de taille "<< max->size()<< " trouvée"<< endl;
    return max;
}

GrapheMat* algoGrapheMat::BronKerbosch(GrapheMat const* G)
{
    // On trie le graphe selon le nombre décroissant de voisins
//    sort(graph->begin(), graph->end(), SommetMat::neighboorsCompare);

    GrapheMat* cliqueInit= new GrapheMat("Clique de "+ G->getName());

    SommetMat* sommetInitial= G->at(1); // TODO choisir un sommet initial pour commencer la recherche de clique
    vector<SommetMat*>& consideredVertices = *(G->getAdjacents(sommetInitial)); //version avec les adjacents à un seul sommet
    consideredVertices.push_back(sommetInitial);
//    consideredVertices= G->adjacents(consideredVertices); // TODO créer la fonctions qui retourne les sommets tous adjacents à un vector<SommetMat*>

    cliqueInit->add(sommetInitial);

    list<GrapheMat*> maxCliquesG= maxCliqueBronKerbosch(G, cliqueInit, consideredVertices);

    GrapheMat* cliqueMax= biggestClique(maxCliquesG);
    return cliqueMax;
}

GrapheMat* algoGrapheMat::BronKerboschV2(GrapheMat const* G)
{
    GrapheMat* cliqueInit= new GrapheMat("Clique de "+ G->getName());

    SommetMat* sommetInitial= G->at(1); // TODO choisir un sommet initial pour commencer la recherche de clique
    vector<SommetMat*>& consideredVertices = *(G->getAdjacents(sommetInitial)); //version avec les adjacents à un seul sommet
    consideredVertices.push_back(sommetInitial);
//    consideredVertices= G->adjacents(consideredVertices); // TODO créer la fonctions qui retourne les sommets tous adjacents à un vector<SommetMat*>

    cliqueInit->add(sommetInitial);

    vector<SommetMat*> candidats= consideredVertices;

    list<GrapheMat*> maxCliquesG= maxCliqueBronKerboschV2(G, cliqueInit, consideredVertices, candidats);

    GrapheMat* cliqueMax= biggestClique(maxCliquesG);
    return cliqueMax;
}

/*
 * Version de base, peu performante
1: function MaxClique(G, K, C)
2: if C = ∅ then noter la clique maximale K
3: else for each x ∈ C do MaxClique(G, K ∪ {x}, C ∩ Γ(x))
4: end function
*/
list<GrapheMat*>& algoGrapheMat::maxCliqueBronKerbosch(GrapheMat const* G, GrapheMat* clique, vector<SommetMat*> const& considered)
{
    cout << considered.size()<< " sommet à considérer pour une clique de taille "<< clique->size()<< endl;

    list<GrapheMat*>* maxCliques= new list<GrapheMat*>;
    maxCliques->push_back(clique);
    if (considered.empty()){
        maxCliques->push_back(clique);

        cout << "clique maximale trouvée  : "<< clique->getName()<< ", de taille : "<< clique->size()<< endl;
    } else {
        // On cherche la clique maximale pour chaque sommet considéré
        // TODO on pourrait utiliser seulement une clique, et regarder la taille de la nouvelle clique trouvée avec maxClique()
        for (SommetMat* sommet : considered) {
            if (!clique->contains(sommet->get_id())) {
                cout << "Ajout du sommet "<< sommet->get_id()<< " : ";
                GrapheMat* copieClique= new GrapheMat(*clique); //TODO créer constructeur par recopie
                copieClique= copieClique->add(sommet);

            // TODO créer la fonction intersection(vector<SommetMat*>& C, ...)
                vector<SommetMat*>& newConsidered = G->intersection(considered, *(G->getAdjacents(sommet)));
                cout << "Nombre de sommet considéres passe de "<< considered.size()<< ", à "<< newConsidered.size()<< endl;

                GrapheMat* newClique= biggestClique(maxCliqueBronKerbosch(G, copieClique, newConsidered));
                maxCliques->push_back(newClique);

                cout << endl;
            }
        }
    }
    // On pourrait retourner biggestClique(*maxCliques)
    return *maxCliques;
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
list<GrapheMat*>& algoGrapheMat::maxCliqueBronKerboschV2(GrapheMat const* G, GrapheMat* clique, vector<SommetMat*> const& considered, vector<SommetMat*>& A)
{
    cout << considered.size()<< " sommet à considérer pour une clique de taille "<< clique->size()<< endl;

    list<GrapheMat*>* maxCliques= new list<GrapheMat*>;
    maxCliques->push_back(clique);
    if (considered.empty()){
        maxCliques->push_back(clique);

        cout << "clique maximale trouvée  : "<< clique->getName()<< ", de taille : "<< clique->size()<< endl;
    } else {
        while (!A.empty()){
            SommetMat* sommet = A.back(); // TODO améliorer le choix du sommet utilisé (comme lors appel)

            if (!clique->contains(sommet->get_id())) { // TODO normalement c'est à supprimer, grace aux éléments exclus
                cout << "Ajout du sommet "<< sommet->get_id()<< " : ";
                GrapheMat* copieClique= new GrapheMat(*clique); //TODO créer constructeur par recopie
                copieClique= copieClique->add(sommet);

            // TODO créer la fonction intersection(vector<SommetMat*>& C, ...)
                vector<SommetMat*> adjacents= *(G->getAdjacents(sommet));
                vector<SommetMat*>& newConsidered = G->intersection(considered, adjacents);
                vector<SommetMat*>& copieA= G->intersection(A, adjacents);

                cout << "Nombre de sommet considéres passe de "<< considered.size()<< ", à "<< newConsidered.size()<< endl;

                GrapheMat* newClique= biggestClique(maxCliqueBronKerboschV2(G, copieClique, newConsidered, copieA));
                maxCliques->push_back(newClique);

                cout << endl;
            }
            A.pop_back();
        }
    }
    return *maxCliques;
}


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
