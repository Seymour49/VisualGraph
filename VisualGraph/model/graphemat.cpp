#include "graphemat.h"

using namespace std;

/*
 * Constructeurs et destructeur
 */
GrapheMat::GrapheMat(string s):name(s)
{}

GrapheMat::GrapheMat(const GrapheMat& g):name(g.name),NbSommets(g.NbSommets),NbArcs(g.NbArcs){
    for(unsigned int i=0; i< g.sommets.size();++i){
        sommets.push_back(g.sommets[i]);
    }
}


GrapheMat::~GrapheMat()
{
    sommets.clear();
}

/*
 * Fonction permettant de découper une ligne du fichier
 * et d'en récupérer chaque élément.
 */
vector< string >& GrapheMat::explode(const string& str)
{
    istringstream split(str);
    vector< string >* tokens = new vector<string>;
    
    for(string each; getline(split, each, ' '); tokens->push_back( each.c_str()) );
    
    return *tokens;
}

/*
 * Fonction d'affichage en mode terminal
 */
ostream& GrapheMat::print(ostream& out)
{
    out << "Graphe : " << name << endl;
    
    for(unsigned int i=1;i<sommets.size();++i){
	out << sommets.at(i) ;
    }
    
    return out;
}


/*
 * Fonction d'initialisation d'un graphe
 *
 */
void GrapheMat::initSommets()
{
    sommets.push_back(SommetMat(0, 0));
    for(int i=1; i<= NbSommets;++i){
        SommetMat s(i, size_t(NbSommets));
//        for(int j=0; j<=NbSommets;++j){
//            // Initialisation du vecteur d'adjacents
//            s.valueInit(false);
//        }
        sommets.push_back(s);
    }
	
}


/*
 * fonction de chargement d'un graphe à partir
 * d'un fichier d'exemple
 */
bool GrapheMat::tryLoadFile(const string& fileName)
{
    ifstream f(fileName.c_str());
    
    if(!f){
	cerr << "Erreur pendant l'ouverture du fichier" << endl;
	return false;      
    }else{
	string line;
	
	while(getline(f,line)){
	    // La ligne est un commentaire, on l'ignore simplement
	    if(line.substr(0,1) == "c"){  
		
	    }
	    // La ligne est une ligne de paramètre nous donnant le nombre de sommets et d'arcs
	    else if(line.substr(0,1) == "p"){
		line = line.substr(6,line.size()-6);
		string tmp = line.substr(0,line.find_first_of(" "));
		NbSommets = atoi(tmp.c_str());
		NbArcs = atoi( line.substr(line.find_first_of(" ")+1, line.size()-tmp.size()).c_str() );
		cout << "Sommets : " << NbSommets << ", arcs : " << NbArcs << endl;
		initSommets();
		
	    }else{
		vector<string>& tokens = explode(line);
		/* tokens[0] : caractère de controle
		    * tokens[1] : id du sommet source
		    * tokens[2] : id du sommet destination
		    */
		if(tokens[0] == "e"){
		    // Controle ok, on doit mettre à jour deux arcs (graphe non-orienté)
		    int src = atoi(tokens[1].c_str());
		    int dest = atoi(tokens[2].c_str());
		    sommets.at(src).updateArc(dest);
		    sommets.at(dest).updateArc(src);			
		    
		}
		delete(&tokens);
	    }
	}    
    }
    return true;
    
}

bool GrapheMat::isComplete() {

    for(int i=1; i<NbSommets;++i){
    if(sommets[i].nbVoisins() != (NbSommets -1))
        return false;
    }

    return true;

}
