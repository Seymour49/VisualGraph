#include "sommetlist.h"

using namespace std;

SommetList::SommetList(int x):Sommet(x)
{ }


ostream& SommetList::print(ostream& out) const
{
    out << "Sommet " << id << " : " ;

    for(list<SommetList *>::const_iterator it = adjacents.begin(); it != adjacents.end(); ++it){
        out << (*it)->get_id() << ";";
    }
    out << std::endl;

    return out;
}

SommetList::~SommetList()
{
    adjacents.clear();
}

/**
 * Retournant le nombre de voisins du sommet
 * @return nombre de voisins
 */
int SommetList::nbNeighboors() const
{
    return adjacents.size();
}
