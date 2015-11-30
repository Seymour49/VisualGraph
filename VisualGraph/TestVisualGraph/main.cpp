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
  
  
  return true;
  
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
     * KO Tester intersection via std::set_intersection(v.begin(),v.end(), v2.begin(), v2.end(), vecteur resultat); 
     * Définir intersection
     */
    GrapheMat* g1 = new GrapheMat("G1");
    
    string file = "../model/testGraphe25.txt";
    cout << file << endl;
    
    if(g1->tryLoadFile(file) ){
	cout << "Chargement réussi " << endl;
	// Découpage du graphe en différents vecteurs de sommets
	vector<SommetMat *> v1;
	vector<SommetMat *> v2;
	
	for(int i=1; i<g1->getNbSommets();++i){
	    v1.push_back(g1->at(i));
	    if(i%3 == 0)
	      v2.push_back(g1->at(i));
	}
	cout << "V1" << endl;
	for(auto n : v1 )
	    cout << *n ;
	cout << "V2" << endl;
	for(auto n : v2 )
	    cout << *n ;
	
	vector<SommetMat *> v3;
	/*
	 *  Ne fonctionne pas;
	 */
	//set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(), v3);
	
	cout << "V3" << endl;
	for(auto n : v3)
	    cout << *n ;
      
    }else{
	cout << "Et merde..." << endl;
    }
    
    delete(g1);
    
    string dummy;
    cin >>dummy;
    return 0;
}