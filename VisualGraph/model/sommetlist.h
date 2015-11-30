#ifndef SOMMETLIST_H
#define SOMMETLIST_H

#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <list>

#include "sommet.h"

class SommetList : public Sommet{
    typedef std::list<SommetList *> listsommets;

private:
    listsommets adjacents;

public:
    SommetList(int x);

    virtual ~SommetList();
    
    /**
     * Retourne les sommets adjacents au sommet "this"
     */
    listsommets& get_adjacents(){ return adjacents; }

    /**
     * Retournant le nombre de voisins du sommet
     * @return nombre de voisins
     */
    int nbNeighboors() const;

    /**
     * @brief print
     * @param out
     * @return
     */
    std::ostream& print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, SommetList& s){
        return s.print(out);
    }

    void updateArc(SommetList* dest){
        // On doit ajouter un pointeur
        adjacents.push_back(dest);
    }

};

#endif // SOMMETLIST_H

