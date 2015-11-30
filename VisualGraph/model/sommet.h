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
};

#endif // SOMMET_H
