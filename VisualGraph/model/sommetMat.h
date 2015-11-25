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
  /**
   * @brief get_id
   * @return
   */
  int get_id() const { return id; }
  std::vector<bool>& get_adjacents(){ return adjacents; }

  /**
   * @brief print
   * @param out
   * @return
   */
  std::ostream& print(std::ostream& out);
    
  /**
    * @brief operator <<  redéfinie l'opérateur de sortie sur flux
    * @param out
    * @param r
    * @return
    */
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
   * Retournant le nombre de voisins du sommet
   */
  int nbVoisins();
};
#endif
