#ifndef SOMMETMAT_H
#define SOMMETMAT_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>

using namespace std;

class SommetMat {
private:
    int id;
    vector<bool>adjacents;
    
public:
  SommetMat(int x):id(x){
  }
  
  ~SommetMat(){
      adjacents.clear();    
  }
  const int get_id(){ return id; };
  vector<bool>& get_adjacents(){ return adjacents; };
  
  void valueInit(bool x){
      adjacents.push_back(x);
   }
  
   ostream& print(ostream& out){
	
	out << "Sommet " << id << " : " ;
	
	for(unsigned int i=1;i<adjacents.size();++i){
		    out << adjacents.at(i) /*<< ";"*/;
	}
	out << endl;
	
	
	return out;
    }
    
    
    friend ostream& operator<<(ostream& out, SommetMat& r){
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