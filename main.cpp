#include <bits/stdc++.h>
#include "BST.h"
#include "BST.cpp"
#include "dico.h"
#include "dico.cpp"


int main(){
	cout<<"*************************AFFICHAGE SELON L'ORDRE D'INSERTION*********************"<<endl; 
    TArbre dico;
	dico = arbreConsVide();
	int i=0;
	srand(time(NULL));
	char *mot;
	while(i<100)
	{
		int x=piocherMot(mot);
		if(x==1){
			cout<<mot<<endl;
			dicoInsererMot(mot,&dico);
		}
		i++;
	}
	cout<<"\n*******************************TEST D'EXISTENCE*******************************"<<endl; 
	string s = "" , t = "maison" ;
	cout<<"test sur le mot "<<t<<": "<<existMot(s, &dico , t) <<endl; 
	dicoAfficher(dico);  //affichage du dictionnaire
	cout<<"*******************************STATISTIQUES*******************************"<<endl; 
	cout<<"Arbre est vide? "<< arbreEstVide(dico)<< endl;
	cout<<"Racine de l'arbre: "<<arbreRacineLettre(dico)<< endl;
	cout<<"Nombre de Mots Total: "<<dicoNbMotsTotal(dico)<<endl;
	cout<<"Nombre de Mots Differents: "<<dicoNbMotsDifferents(dico)<<endl;
	arbreSuppr(&dico);  //suppression du dictionnaire
	cout<<"\n*******************************SUPPRESSION*******************************"<<endl;
	cout<<"Suppression de l'arbre.."<<arbreEstVide(dico)<<endl;
	cout<<"Arbre est supprimée avec succès"<<endl;
	cout<<"\n*******************************FIN*******************************"<<endl; 
	return 0;  
}