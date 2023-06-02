#include<bits/stdc++.h>
using namespace std;

//construction d'un arbre vide
TArbre arbreConsVide(){
    return(NULL);
};


//tester si l'arbre est vide ou non
string arbreEstVide(TArbre a){
    if(a==NULL)
        return("oui");
    else return("non");
}


//construction d'un neud de l'arbre
TArbre arbreCons(char c, int n,TArbre fg, TArbre fd){
    TArbre a = new node();
    a->val= c;
    a->fg= fg;
    a->fd= fd;
    a->occ=n;
    return(a);
}


//retourner la lettre du noeud
char arbreRacineLettre(TArbre a){
    return(a->val);
}


//retourner l'occurence de la lettre du noeud
int arbreRacineNbOcc(TArbre a){
    return(a->occ);
}

//retourner le fils gauche du noeud
TArbre arbreFilsGauche(TArbre a){
    if(a!=NULL)
        return(a->fg);
}

//retourner le fils droit du noeud
TArbre arbreFilsDroit(TArbre a){
    if(a!=NULL)
        return(a->fd);
}

//suppression de l'arbre
void arbreSuppr(TArbre *a){
    while(*a != NULL){
        arbreSuppr(&((*a)->fd));
        arbreSuppr(&((*a)->fg));
        free(*a) ;
        *a = NULL;
    }
}


//retourner l'hauteur de l'arbre
int hauteurArbre(TArbre a){
    if(a!=NULL){
        return(1+ max(hauteurArbre(a->fd),hauteurArbre(a->fd)));
    }
    else return(0);
}

