#include "grapheMat.h"

using namespace std;

int main(int argc, char **argv) {

    GrapheMat* g = new GrapheMat("Test");
    
    if(g->tryLoadFile(argv[1])){
	cout <<(*g) << endl;	
    }
    else{
	cout << "Erreur de fichier" << endl;
      
    }
    delete(g);
    return 0;
}
