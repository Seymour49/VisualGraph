#ifndef SOMMETMAT_H
#define SOMMETMAT_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>

#include "sommet.h"

class SommetMat : public Sommet{
private:
    std::vector<bool> adjacents;
    
public:
  SommetMat(int x, size_t nb_sommets);
  virtual ~SommetMat();

  std::vector<bool> get_MatriceAdjacents() const{ return adjacents; }

  /**
   * Fonction de comparaison selon le nombre de sommets adjacents.
   * @param Sommet a @param Sommet b
   * @return a.nbVoisins() > b.nbVoisins()
   */
  static bool neighboorsCompare(const SommetMat*a, const SommetMat*b){
      return const_cast<SommetMat *>(a)->nbVoisins() > const_cast<SommetMat *>(b)->nbVoisins(); // TODO Ugo : pourquoi const_cast ?
  }

  /**
   * Fonction de comparaison selon le nombre de sommets adjacents.
   * @param Sommet a @param Sommet b
   * @return a.nbVoisins() > b.nbVoisins()
   */
  bool neighboorsCompare(const SommetMat* other) const{
      return nbVoisins() > (const_cast<SommetMat *>(other)->nbVoisins()); // TODO Ugo : pourquoi const_cast ?
  }

  /**
   * @brief print
   * @param out
   * @return
   */
  std::ostream& print(std::ostream& out) const;
  
  /**
   * Définit un autre sommet comme étant adjacent
   * @param id numéro de l'autre sommet
   */
  void updateArc(int id){ adjacents[id] = true; }
  
  /**
   * Vérifie qu'il y a un arc entre le sommet et un autre sommet
   * @param id numéro de l'autre sommet
   * @return vrai si il y a un arc entre le sommet et l'autre sommet
   */
  bool isArc(int id) const { return adjacents.at(id); }

  /**
   * Retournant le nombre de voisins du sommet
   * @return nombre de voisins
   */
  int nbVoisins() const;
};
#endif
