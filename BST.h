#ifndef DEF_BST
#define DEF_BST

#include<bits/stdc++.h>
using namespace std;


struct node{
    char val;
    node* fg;
    node* fd;
    int occ=0;
    int comp=0;
};

typedef node* TArbre;  

TArbre arbreConsVide();
string arbreEstVide(TArbre);
TArbre arbreCons(char, int, TArbre, TArbre, int);
char arbreRacineLettre(TArbre);
int arbreRacineNbOcc(TArbre);
TArbre arbreFilsGauche(TArbre);
TArbre arbreFilsDroit(TArbre);
void arbreSuppr(TArbre*);
int hauteurArbre(TArbre);
void printBST(node*, int, int, int) ;
void printBSTT(node* a);

#endif
