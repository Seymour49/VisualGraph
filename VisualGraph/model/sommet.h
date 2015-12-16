#ifndef SOMMET_H
#define SOMMET_H

#include <vector>
#include <ostream>

class Sommet
{
protected:
    int id;

public:

    Sommet(int _id) : id(_id) {}
    /**
     * @brief get_id
     * @return
     */
    int get_id() const { return id; }
//    virtual std::vector<sommet*>& get_adjacents() const = 0;

    // CARACTERISTIQUES CALCULABLES
    /**
     * Retournant le nombre de voisins du sommet
     * @return nombre de voisins
     */
    virtual int nbNeighboors() const =0;

    bool moreNeighboors(Sommet *s1, Sommet *s2);

    bool operator< (Sommet* s2){
        return moreNeighboors(this, s2);
    }

    // AFFICHAGE
    virtual std::ostream& print(std::ostream& out) const = 0;

    /**
      * @brief operator <<  redéfinie l'opérateur de sortie sur flux
      * @param out flux de sortie sur lequel imprimer le sommet
      * @param r sommet à afficher
      * @return flux de sortie
      */
     friend std::ostream& operator<<(std::ostream& out, Sommet& r){
          return r.print(out);
     }

    // METHODES UTILES


     /**
      * Fonction de comparaison selon le nombre de sommets adjacents.
      * @param Sommet a @param Sommet b
      * @return a.nbVoisins() > b.nbVoisins()
      */
     static bool neighboorsCompare(const Sommet*a, const Sommet*b){
         return const_cast<Sommet *>(a)->nbNeighboors() > const_cast<Sommet *>(b)->nbNeighboors(); // TODO Ugo : pourquoi const_cast ?
     }

     /**
      * Fonction de comparaison selon le nombre de sommets adjacents.
      * @param Sommet a @param Sommet b
      * @return nb voisins > nb voisins de l'autre
      */
     bool neighboorsCompare(const Sommet* other) const{
         return nbNeighboors() > other->nbNeighboors();
     }
};

#endif // SOMMET_H
