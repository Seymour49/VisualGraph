#include "graphemat.h"

using namespace std;
/* ======================================= */
    /* Constructeurs et destructeur */
/* ======================================= */
GrapheMat::GrapheMat(string s):vector<SommetMat *>(),name(s)
{}

GrapheMat::GrapheMat(const GrapheMat& g):vector<SommetMat *>(g), name(g.name),nb_sommets(g.nb_sommets),nb_arcs(g.nb_arcs){
//    for(unsigned int i=0; i< g.size();++i){
//        push_back(g[i]);
//    }
}


GrapheMat::~GrapheMat()
{
    for(vector<SommetMat *>::iterator it = this->begin(); it != this->end(); ++it)
    delete(*it);

    this->clear();
}

/* ======================================= */
               /* Autres */
/* ======================================= */
vector< string >& GrapheMat::explode(const string& str)
{
    istringstream split(str);
    vector< string >* tokens = new vector<string>;
    
    for(string each; getline(split, each, ' '); tokens->push_back( each.c_str()) );
    
    return *tokens;
}

ostream& GrapheMat::print(ostream& out) const
{
    out << "Graphe : " << name << endl;
    
    for(unsigned int i=1; i < size();++i){
        out << *(at(i)) ;
    }
    
    return out;
}

void GrapheMat::initSommets()
{
    SommetMat *s = new SommetMat(0,0);
    //on suppose le sommet 0 n'existe pas
    push_back(s);

    // Initialisation du vecteur d'adjacents à faux (pas d'arcs)
    for(int i=1; i<= nb_sommets;++i){
        SommetMat* tmp = new SommetMat(i, size_t(nb_sommets));
        push_back(tmp);
    }
}

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
            nb_sommets = atoi(tmp.c_str());
            nb_arcs = atoi( line.substr(line.find_first_of(" ")+1, line.size()-tmp.size()).c_str() );
            cout << "Sommets : " << nb_sommets << ", arcs : " << nb_arcs << endl;
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
                this->at(src)->updateArc(dest);
                this->at(dest)->updateArc(src);
            }

            delete(&tokens);
            }
        }

        // On trie le graphe selon le nombre décroissant de voisins
        sort(this->begin(), this->end(), SommetMat::neighboorsCompare);
    }
    return true;
    
}

bool GrapheMat::isComplete() {

    for(int i=1; i<nb_sommets;++i){
    if(at(i)->nbVoisins() != (nb_sommets -1))
        return false;
    }

    return true;

}
