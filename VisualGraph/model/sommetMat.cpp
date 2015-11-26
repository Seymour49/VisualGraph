#include "sommetMat.h"

using namespace std;

SommetMat::SommetMat(int x, size_t nb_sommets):id(x)
{
    adjacents.resize(nb_sommets+1, false);
}

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

int SommetMat::nbVoisins(){
    int res = 0;
    for(unsigned int i=1;i<adjacents.size();++i){
        if(isArc(i)){
            ++res;
        }
    }

    return res;
}
