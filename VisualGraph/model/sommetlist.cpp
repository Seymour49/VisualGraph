#include "sommetlist.h"

 SommetList::SommetList(int x):id(x) {

 }


ostream& SommetList::print(ostream& out)
{
    out << "Sommet " << id << " : " ;

    for(list<SommetList *>::iterator it = adjacents.begin();it != adjacents.end();++it){
    out << (*it)->get_id() << ";";
    }
    out << std::endl;

    return out;
}

SommetList::~SommetList()
{
    adjacents.clear();
}
