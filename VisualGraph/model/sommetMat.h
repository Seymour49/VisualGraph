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
   * Fonction de comparaison selon le nombre de sommets adjacents.
   * @param Sommet a @param Sommet b @return a.nbVoisins() > b.nbVoisins()
   */
  static bool neighboorsCompare(const SommetMat*a, const SommetMat*b){
      return const_cast<SommetMat *>(a)->nbVoisins() > const_cast<SommetMat *>(b)->nbVoisins();
  }


  /**
   * @brief print
   * @param out
   * @return
   */
  std::ostream& print(std::ostream& out);
    
  /**
    * @brief operator <<  redéfinie l'opérateur de sortie sur flux
    * @param out flux de sortie sur lequel imprimer le sommet
    * @param r sommet à afficher
    * @return flux de sortie
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
   * @return vrai si il y a un arc entre le sommet et l'autre sommet
   */
  bool isArc(int id) const{ return adjacents.at(id); }

  /**
   * Retournant le nombre de voisins du sommet
   * @return nombre de voisins
   */
  int nbVoisins();
};
#endif
