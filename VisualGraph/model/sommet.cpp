#include "sommet.h"
bool Sommet::moreNeighboors(Sommet *s1, Sommet *s2)
{
    if (s1->nbNeighboors() < s2->nbNeighboors())
        return false;
    else return true;
}
