#include "sommetMat.h"

using namespace std;

SommetMat::SommetMat(int x):id(x){}

ostream& SommetMat::print(ostream& out)
{
	out << "Sommet " << id << " : " ;
	
	for(unsigned int i=1;i<adjacents.size();++i){
		    out << adjacents.at(i) /*<< ";"*/;
	}
	out << endl;
	
	return out;
}

SommetMat::~SommetMat(){
    adjacents.clear();
}
