#ifndef SOMMETLIST_H
#define SOMMETLIST_H

#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <list>

using namespace std;

class SommetList {
    typedef list<SommetList *> ListSommets;

private:
    int id;
    ListSommets adjacents;

public:
    SommetList(int x);

    virtual ~SommetList();

    int get_id() const { return id; }
    
    /**
     * Retourne les sommets adjacents au sommet "this"
     */
    ListSommets& get_adjacents(){ return adjacents; }

    ostream& print(ostream& out);


      friend ostream& operator<<(ostream& out, SommetList& s){
      return s.print(out);
      }

      void updateArc(SommetList* dest){
            // On doit ajouter un pointeur
            adjacents.push_back(dest);
      }

};

#endif // SOMMETLIST_H

