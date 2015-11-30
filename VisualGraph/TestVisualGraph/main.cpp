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

bool testIntersection(GrapheMat* g1, GrapheMat* g2){
  
  
  
  
}

int main(int argc, char **argv) {
    /**
     * Test de chargement 
     * 
    GrapheMat* g = new GrapheMat("Test");
    
    bool successTestLoad= testLoading(argc, argv, g);
    if (successTestLoad) cout<< "Test Chargement fichier réussi"<< endl;
    else cout<< "Test Chargement fichier échoué"<< endl;
    
    */
    
    /*
     * Test intersection
     */
    
    /* DONE
     * 	tests valgrind ok sur création et suppression
     * TODO 
     * Tester intersection via std::set_intersection(v.begin(),v.end(), v2.begin(), v2.end(), vecteur resultat);
     * 
     */
    GrapheMat* g1 = new GrapheMat("G1");
    GrapheMat* g2 = new GrapheMat("G2");
    
    string file1 = "../../model/testGraphe10.txt";
    string file2 = "../../model/testGraphe20.txt";
    
    if(g1->tryLoadFile(file1) && g2->tryLoadFile(file2)){
	cout << "Chargement réussi " << endl;
      
    }else{
	cout << "Et merde..." << endl;
    }
    
    delete(g1);
    delete(g2);
    
    string dummy;
    cin >>dummy;
    return 0;
}