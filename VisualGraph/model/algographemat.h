#ifndef ALGOGRAPHEMAT_H
#define ALGOGRAPHEMAT_H

#include <vector>
#include <list>
#include <algorithm>
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
     * Supprime les sommets qui n'ont pas le nombre minimum de voisins
     * @param sommets liste triées des sommets
     * @param min_adjacents nombre minimum d'adjacents
     */
    static void purge(std::vector<SommetMat *> &sommets, int min_adjacents);

    /* ==================================*/
        /*      ALGORITHMES         */

    /**
     * Démarre l'algorithme de recherche d'une plus grande clique maximale
     *  à partir des sommets avec le plus d'adjacents (approximation)
     * @param G graphe sur lequel on recherche la clique maximum
     * @return une clique maximale trouvée
     */
    static GrapheMat* AlgoGrowing(GrapheMat const* G);

    /**
     * Démarre l'algorithme de recherche de clique Maximum avec la 1ere version de BK
     * @param G graphe sur lequel on recherche la clique maximum
     * @return clique Maximum trouvée
     */
    static GrapheMat* BronKerbosch(GrapheMat const* G);

    /**
     * Démarre l'algorithme de recherche de clique Maximum avec la 2e version de BK
     * @param G graphe sur lequel on recherche la clique maximum
     * @return clique Maximum trouvée
     */
    static GrapheMat* BronKerboschV2(GrapheMat const* G);

    /**
     * Démarre l'algorithme de recherche de clique Maximum avec la 2e version de BK (de Wikipédia)
     * @param G graphe sur lequel on recherche la clique maximum
     * @return clique Maximum trouvée
     */
    static GrapheMat* BronKerboschV2_bis(GrapheMat const* G);

    /**
     * Démarre l'algorithme de recherche de clique maximale avec
     *  BK et Growing 1 tour sur 2
     * @param G graphe sur lequel on recherche la clique maximum
     * @return clique Maximum trouvée
     */
    static GrapheMat* AlgoGrowingWithBK(GrapheMat const* G);


    /**
     * Démarre l'algorithme de recherche de clique maximale avec
     *  AlgoGrowing( puis BK sur les sommets T(= taille clique) adjacents minor
     * @param G graphe sur lequel on recherche la clique maximum
     * @return clique Maximum trouvée
     * NE FONCTIONNE PAS
     */
    static GrapheMat* BronKerboschWithGrowing(GrapheMat const* G);


    /* === Algos ===*/
    /**
     * Algorithme de recherche d'une clique maximale
     *  à partir des sommets avec le plus d'adjacents (approximation)
     * @param G graphe où l'on recherche la clique
     * @param clique courante
     * @param considered sommets considérés pour l'ajout, trié par ordre décroissant
     * @return clique trouvée
     */
    static GrapheMat* maxCliqueGrowing(GrapheMat const* G, GrapheMat *clique, std::vector<SommetMat *> &considered);
    /**
     * Version de base de BK, peu performante, visite de tous les noeuds
     *  passé en paramètre pour le résultat
     * @param G graphe dont on cherche la clique maximale,
     * @param K clique maximale courante
     * @param C liste de sommets adjacents au sommets de la clique courante
     * @param A liste d'adjacents que l'on s'autorise à ajouter (pas déjà tenté)
     * @return
     * TODO retirer K des arguements et le mettre en retour de la fonction
     */
    static std::list<GrapheMat*>& maxCliqueBronKerbosch  (GrapheMat const* G, GrapheMat* clique, const std::vector<SommetMat *> &considered);
    /**
     * Candidats autorisés : On peut empˆecher ceci en disant qu’une fois qu’on a  ́enum ́er ́e toutes les cliques
    qui contiennent le sommet x, alors on pourra s’interdire de consid ́erer x dans toute la suite. On maintient
    donc trois ensembles : la clique courante K, un ensemble de candidats C, et un sous-ensemble A de C
    form ́e des sommets qu’on s’autorise `
    a ajouter `a K. On aboutit alors `a un algorithme :
    */
    static GrapheMat* maxCliqueBronKerboschV2(GrapheMat const* G, GrapheMat* clique, const std::vector<SommetMat*>& considered, std::vector<SommetMat*>& A);
    /*
     * Seconde implémentation candidats autorisés
     */
    static GrapheMat* maxCliqueBronKerboschV2_bis(GrapheMat const* G, GrapheMat* clique, std::vector<SommetMat*>& considered, std::vector<SommetMat*>& excluded);
    /**
     * On utilise BK sur un seul niveau de récursivité, au lieu de le faire sur N niveau (N : nb noeuds),
     *  puis on utilise l'algorithme personnel
     *  Cela donne une meilleure approximation, puisqu'on teste plus de noeuds, on pourrait
     *  utiliser ce principe avec un plus grand nombre de niveaux de récursivité de BK
     *  car on a une meilleure sélection à chaque niveau de BK. L'idéal serait de trouver le juste
     *  milieu entre rapidité et précision. Mais cela dépend de la taille du graphe considéré et
     *  du nombre d'arcs de celui ci. Mais cette solution est la meilleure que nous ayons pour trouver une
     *  bonne approximation du la clique maximale.
     * @param G
     * @param clique
     * @param considered
     * @param A
     * @return
     */
    static GrapheMat* maxCliqueMixed(GrapheMat const* G, GrapheMat* clique, std::vector<SommetMat*> const& considered, std::vector<SommetMat*>& A);
};

#endif // ALGOGRAPHEMAT_H
