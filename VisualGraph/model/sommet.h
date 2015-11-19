#ifndef SOMMET_H
#define SOMMET_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <boost/iterator/iterator_concepts.hpp>

using namespace std;

class Sommet {
private:
    int id;
    vector<bool>adjacents;
    
public:
  Sommet(int x):id(x){
    
  }
  
  const int get_id(){ return id; };
  vector<bool>& get_adjacents(){ return adjacents; };
  
  void valueInit(bool x){
      adjacents.push_back(x);
   }
  
   ostream& print(ostream& out){
	
	out << "Sommet " << id << " : " ;
	
	for(unsigned int i=1;i<adjacents.size();++i){
		    out << adjacents.at(i) << ";";
	}
	out << endl;
	
	
	return out;
    }
    
    
    friend ostream& operator<<(ostream& out, Sommet& r){
	return r.print(out);
    }
  
  void updateArc(int id){
      adjacents.at(id) = true;
  }
  
  bool isArc(int id){
      return adjacents.at(id);
  }
  
};
#endif