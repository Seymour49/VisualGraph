#include <iostream>
#include <boost/iterator/iterator_concepts.hpp>

#include "../model/graphemat.h"

using namespace std;


/**
 * Fonction d'intersection entre deux vecteurs de sommets.
 * @param const_vector<T*> v1 @param const_vector<T*> v2
 * @return vector<T*>
 */
vector<SommetMat *> setIntersection(const vector<SommetMat* > &v1,const vector<SommetMat *> &v2){
    vector<SommetMat *> res;
    if(v1.size() == 0 || v2.size() == 0 ){
	return res;
      
    }
    else{
      for(unsigned int i = 0; i< v1.size() ; ++i ){
	  for(unsigned int j = 0; j< v2.size(); ++j ){
	      if( v1.at(i)->get_id() == v2.at(j)->get_id() )
		res.push_back(v1.at(i)); 
	  }
	
      }
          return res;
    }

}

vector<SommetMat *> setIntersection(const vector<SommetMat *> &v1,SommetMat* s){
  
    vector<SommetMat *> res;
    
    for(unsigned int i = 0; i< v1.size() ; ++i ){
	
	  if( v1.at(i)->get_id() == s->get_id() )
		res.push_back(v1.at(i)); 
      
    }  
    return res;
  
}
/**
 * Fonction d'union entre deux vecteurs de sommets.
 * @param const_vector<T*> v1 @param const_vector<T*> v2
 * @return vector<T*>
 */
vector<SommetMat *> setUnion(const vector<SommetMat* > &v1,const vector<SommetMat *> &v2){
    vector<SommetMat *> res;
    /* Principe :
     * 
     *	On copie dans res le plus volumineux des vecteurs
     * 	Ensuite, pour chaque élément du plus petit, on 
     *  teste l'intersection avec res. Si elle est nulle,
     * 	on ajoute l'élément à res
     *
     */ 
    
    if(v1.size() > v2.size() ){
	res = v1;
	for(unsigned int i=0; i < v2.size() ; ++i)
	    if(setIntersection(res, v2.at(i)).size() == 0)
		res.push_back(v2.at(i));	
    }else{
	res = v2;
	for(unsigned int i=0; i < v1.size() ; ++i)
	    if(setIntersection(res, v1.at(i)).size() == 0)
		res.push_back(v1.at(i));	
    }

    return res;
}

vector<SommetMat* > neighboors(GrapheMat g1, SommetMat * s){
    vector<SommetMat* > res;
    
    for(unsigned int i = 1; i < s->get_MatriceAdjacents().size() ; ++i){
	if(s->get_MatriceAdjacents().at(i) ){
	    res.push_back(g1.at(i));
	}
    }
    
    return res;
}

vector<SommetMat *> setUnionVS(const vector<SommetMat* > v1,SommetMat *s){
    vector<SommetMat *> res = v1;  
    if(setIntersection(res, s).size() == 0)
	    res.push_back(s);	

    return res; 
}

void deleteSommet(vector<SommetMat *> v, SommetMat* s){
    for(vector<SommetMat*>::iterator it (v.begin()); it != v.end(); ++it){
	if( (*it)->get_id() == s->get_id() ){
	    v.erase(it);
	}
    }
}

void BK(GrapheMat g, vector<SommetMat *> R, vector<SommetMat *> P, vector<SommetMat *> X){
    if(P.size() == 0 && X.size() == 0){
	  cout << "Clique Maximal détectée" << endl;
	  for(auto n : R ){
	      cout << *n ;
	  }
    }
    else{
	cout << "Il est passé par ici" << endl;
	for(auto n : P){
	   vector<SommetMat* >  v1 =setUnionVS(R,n);
	   vector<SommetMat* > v2 =setIntersection(P,neighboors(g,n));
	   vector<SommetMat* > v3 =setIntersection(X, neighboors(g,n));
	   cout << "Il repassera par la" << endl;
	    BK(g,v1, v2, v3);
	    X = setUnionVS(X,n);
	    deleteSommet(P,n);
	}
      
    }
}



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

bool testIntersection(int argc, char** argv, GrapheMat* g){
    
    if(g->tryLoadFile("../model/testGraphe25.txt") ){
	// Découpage du graphe en différents vecteurs de sommets
	vector<SommetMat *> v1;
	vector<SommetMat *> v2;
	
	for(int i=1; i<=g->getNbSommets();++i){
	    v1.push_back(g->at(i));
	    if(i%3 == 0)
	      v2.push_back(g->at(i));
	}
	cout << "V1" << endl;
	for(auto n : v1 )
	    cout << *n ;
	cout << "V2" << endl;
	for(auto n : v2 )
	    cout << *n ;
	
	/*
	 * Fonctionne, reste à faire test performance
	 */
	vector<SommetMat *> v3 = setIntersection(v1,v2);
	
	cout << "V3" << endl;
	for(auto n : v3)
	    cout << *n ;
      
    }else{
	cout << "Erreur de chargement du fichier de test" << endl;
	return false;
    }
  
    return true;
}


bool testUnion(GrapheMat* g1, GrapheMat* g2)
{
    if( g1->tryLoadFile("../model/testGraphe25.txt") ){
	if( g2->tryLoadFile("../model/testGraphe.txt")){
	  
	  vector<SommetMat *> v1;
	  vector<SommetMat *> v2;
	  for(int i=1; i <= g1->getNbSommets(); ++i)
	      v1.push_back(g1->at(i));
	  
	  for(int i=1; i <= g2->getNbSommets(); ++i)
	      v2.push_back(g2->at(i));
	  

	  vector<SommetMat* > v3= setUnion(v1,v2);
	  
	  for(auto n : v3)
	      cout << *n ;
	  
	}else{
	    cout << "Error while loading ../model/testGraphe.txt" << endl;
	}
    }else{
	cout << "Error while loading ../model/testGraphe25.txt" << endl;
	return false;
    }
  
    return true;
}


int main(int argc, char **argv)
{
    GrapheMat* g1 = new GrapheMat("Test");
     /**
     * Test de chargement 
     */
    /*
    if (testLoading(argc, argv, g1))
      cout<< "Test Chargement fichier réussi"<< endl;
    else 
      cout<< "Test Chargement fichier échoué"<< endl;
    */
    
    /*
     * Test intersection
     */
    /*
    if(testIntersection(argc,argv,g1))
	cout << "Fin de test Intersection : Succès" << endl;
    else
	cout << "Fin de test Intersection : Echec" << endl;
    */
    /**
     * Test Union : Fonctionne à priori, demande de vérification de l'algo pour Flo par Ugo
     */
    /*
     GrapheMat* g2 = new GrapheMat("Test2");
     if(testUnion(g1,g2))
	cout << "Fin test Union : Succès" << endl;
     else
	cout << "Fin test Union : Echec" << endl;
     
     delete(g2);
     
     */
     
     /**
      * Test BK
      * 
      */
     if( g1->tryLoadFile("../model/testGraphe25.txt") ){
	   vector<SommetMat* >  R;
	   vector<SommetMat* > P;
	   vector<SommetMat* > X;
	   
	   for(unsigned i = 1; i < g1->size() ; ++ i){
	      P.push_back(g1->at(i));
	   }
	   
	   BK(*g1,R,P,X);
       
     }
      delete(g1);

    
    string dummy;
    cin >>dummy;
    return 0;
}