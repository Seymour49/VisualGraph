#include "sommetMat.h"

using namespace std;

SommetMat::SommetMat(int x, size_t nb_sommets):Sommet(x)
{
    adjacents.resize(nb_sommets+1, false);
}

ostream& SommetMat::print(ostream& out) const
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

int SommetMat::nbNeighboors() const{
    int res = 0;
    for(unsigned int i=1;i<adjacents.size();++i){
        if(isArc(i)){
            ++res;
        }
    }

    return res;
}
