#ifndef SOMMETLIST_H
#define SOMMETLIST_H

#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>

using namespace std;

class SommetList {
private:
    int id;
    list<SommetList *> adjacents;

public:
    SommetList(int x):id(x),adjacents(null){
    }

    ~SommetList(){
        adjacents.clear();
    }
    const int get_id(){ return id; };
    list<SommetList*>& get_adjacents(){ return adjacents; };

     ostream& print(ostream& out){

      out << "Sommet " << id << " : " ;

      for(list<Sommet *>::iterator it = adjacents.begin();it != adjacents.end();++it){
              out << (*it).get_id() << ";";
      }
      out << endl;


      return out;
      }


      friend ostream& operator<<(ostream& out, SommetList& s){
      return s.print(out);
      }

      void updateArc(SommetList* dest){
            // On doit ajouter un pointeur
            adjacents.push_back(dest);
      }

};

#endif // SOMMETLIST_H

