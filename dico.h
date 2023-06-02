#ifndef DEF_DICO
#define DEF_DICO

int piocherMot(char );
int nombreAleatoire(int );
void insererMot(string  , int , TArbre *noeud);
void dicoInsererMot(string s, TArbre*arbre);
int existMot(string,TArbre,string);
void afficherMots(string , TArbre );
void dicoAfficher(TArbre );
int dicoNbMotsDifferents(TArbre );
int dicoNbMotsTotal(TArbre );
int dicoNbOccMot(char ,TArbre );
int occchar(TArbre a,char c);
int totalchar(TArbre );
void lettrespercentage( TArbre );
#endif