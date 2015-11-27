#include <iostream>

#include "../model/graphemat.h"

using namespace std;

bool testLoading(int argc, char** argv, GrapheMat* g){
    cout << "argc : "<< argc<< endl;
    if (argc>1){
	    
	if(g->tryLoadFile(argv[1])){
	    cout <<(*g) << endl;
	}
	else{
	    cout << "Erreur de fichier" << endl;
	    return false;
	}
    //     delete(g);
    } else {
	cout<< "Entrez le chemin d'un fichier de clique :"<< endl;
	ostringstream oss;
	string filename;
	oss <<"../../model/";
	cin >> filename;
	
	cout <<"Chargement du fichier"<< oss.str();
// 	cin >> filename;
	if(g->tryLoadFile(oss.str() + filename)){
	    cout <<(*g) << endl;
	}
	else{
	    cout << "Mauvais fichier" << endl;
	    return false;
	}
    }
    
    return true;
}

int main(int argc, char **argv) {

    GrapheMat* g = new GrapheMat("Test");
    
    bool successTestLoad= testLoading(argc, argv, g);
    if (successTestLoad) cout<< "Test Chargement fichier réussi"<< endl;
    else cout<< "Test Chargement fichier échoué"<< endl;
    string dummy;
    cin >>dummy;
    return 0;
}