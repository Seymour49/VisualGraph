#ifndef SOMMETMAT_H
#define SOMMETMAT_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>

class SommetMat {
private:
    int id;
    std::vector<bool> adjacents;
    
public:
  SommetMat(int x, size_t nb_sommets);
  virtual ~SommetMat();

  int get_id() const { return id; }
  std::vector<bool>& get_adjacents(){ return adjacents; }
  
//  void valueInit(bool x){
//      adjacents.push_back(x);
//   }

  std::ostream& print(std::ostream& out);
    
   friend std::ostream& operator<<(std::ostream& out, SommetMat& r){
        return r.print(out);
   }
  
  /**
   * Définit un autre sommet comme étant adjacent
   * @param id numéro de l'autre sommet
   */
  void updateArc(int id){ adjacents.at(id) = true; }
  
  /**
   * Vérifie qu'il y a un arc entre le sommet et un autre sommet
   * @param id numéro de l'autre sommet
   */
  bool isArc(int id){ return adjacents.at(id); }

  /**
   * Fonction retournant le nombre de voisins du sommet
   */
  int nbVoisins();
};
#endif
