#ifndef GRAPHELIST_H
#define GRAPHELIST_H

#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>

#include "sommetlist.h"

using namespace std;

class GrapheList{
private:
    string name;
    int NbSommets;
    int NbArcs;
    list<SommetList> sommets;

public:
    GrapheList(string s);

};


#endif // GRAPHELIST_H

