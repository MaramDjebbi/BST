#include "BST.h"
#include <bits/stdc++.h>
using namespace std;

//retourner un nombre aleatoire
int nombreAleatoire(int nombreMax){
    int y = rand()  ;
    return y%nombreMax;
}


//piocher un mot du dictionnaire
int choisi[1005] , cnt = 0 ; 
int piocherMot(char *motPioche){
    FILE* dico=NULL;
    int nbMots=0,numMotChoisi=0,i=0;
    int caractereLu=0;
    dico=fopen("dico.txt","r");  //ouvrir le fichier en mode lecture
    if(dico==NULL){  //le fichier text n'existe pas
        cout<<"\nImpossible de charger le dictionnaire des mots\n";
        return 0;
    }
    while(caractereLu!=EOF){  //compter le nombre de mots dans le fichier
        caractereLu=fgetc(dico);
        if(caractereLu=='\n' || caractereLu==EOF)
            nbMots++;
    };
    if(cnt==nbMots) return 0 ; //le fichier ne contient aucun mot
    while(true){ 
        numMotChoisi=nombreAleatoire(nbMots);
        if(choisi[numMotChoisi]) continue;
        choisi[numMotChoisi] = 1 ; 
        cnt++ ; 
        break ; 
    }
    rewind(dico); //retour au debut du fichier
    while (numMotChoisi > 0)  //parcourir le fichier pour trouver le mot a piocher
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico); //piocher le mot
    motPioche[strlen(motPioche) - 1] = '\0'; //remplacer le dernier caractère da le ligne (qui est '\n') par un '\0'
    fclose(dico);  //fermer le fichier text
    return 1;
}


//inserer un mot dans le dictionnaire
void insererMot(string s , int i, TArbre *noeud)  
{
    if (*noeud != NULL)
    {
        if (s[i] != '\0') //pas fin de mot
        {
            if ((*noeud)->val == s[i])  //caractere a inserer == caractere du noeud actuel
            {
                i++; // passer au caractere suivant dans le mot
                insererMot(s , i, &((*noeud)->fg)); //descendre gauche
            }
            else
            {
                if((*noeud)->val > s[i]){ //caractere a inserer < caractere du noeud actuel
                        TArbre n = arbreCons(s[i], 0, NULL, *noeud); //créer un nouveau noeud
                        i++;   // passer au caractere suivant
                        *noeud = n;  
                        insererMot(s,i, &((*noeud)->fg));   //descendre gauche
                }else{  //caractere a inserer > caractere du noeud actuel 
                    if ((*noeud)->fd != NULL)  //fils droit du noeud actuel contient une lettre
                    {
                        insererMot(s , i, &((*noeud)->fd));  //descendre droite
                    }
                    else //caractere n'existe pas
                    {
                        (*noeud)->fd = arbreCons(s[i], 0, NULL, NULL);  ////créer un nouveau noeud
                        insererMot(s,i, &(*noeud)->fd); //descendre droite
                    }
                }
            }
        }
        else if (s[i] == '\0' && (*noeud)->val != '\0')//cas particulier
        {
                    TArbre n = arbreCons('\0', 1, NULL, *noeud); 
                    *noeud = n;
        }
        else if (s[i] == '\0' && (*noeud)->val == '\0') //fin de mot
        {
            (*noeud)->occ++; //incrémenter l'occurence du mot
        }
    }
    else  //noeud == null
    {
        if (s[i] != '\0') // insertion d'un caractere
        {
            *noeud = arbreCons(s[i], 0, NULL, NULL); //construire un nouveau noeud
            i++; //passer au caractere suivant dans le mot
            insererMot(s , i , &((*noeud)->fg));
        }   
        else //   insertion d'un \0 
        {
            *noeud = arbreCons('\0', 1, NULL, NULL);
        }
    }
}


//tester l'existence d'un mot t dans le dictionnaire
int existMot(string s, TArbre *noeud , string t) 
{
    if(t==s){ //fin du mot 
        if((*noeud) == NULL || (*noeud)->val != '\0') return 0 ; 
        return 1 ; 
    } 
    if(s.size()>t.size()) return 0 ;  
    int i = s.size() ; 
    if (*noeud != NULL)  
    {
        char c = (*noeud)->val ; 
        string ss = s ; 
        if (t[i]==c)
        {
            s+= c ; 
            return existMot(s,&(*noeud)->fg , t) ; 
        }
        else 
        {
            return existMot(ss,&(*noeud)->fd , t) ; 
        }
    }
    return 0 ; 
}


//Permet d'ajouter un mot au dictionnaire
void dicoInsererMot(string s, TArbre*arbre)
{
    if (s.size() > 0)
    {
        if (*arbre == NULL)
            *arbre = arbreConsVide();
        insererMot(s,0, arbre);
    }
}


//afficher un mot de l'arbre
void afficherMots(string s, TArbre a)
{
    if (a != NULL)
    {
        if (a->val != '\0') 
        {
            if (a->fg != NULL) //ajouter caractere a mot
            {
                string t = s + a->val ;
                afficherMots(t, a->fg);
            }
            if (a->fd != NULL) //fait rien et descendre droite
            {
                afficherMots(s, a->fd);
            }
        }
        else
        { 
            cout<<'('<<(a->occ)<<')'<<' '<<s<<endl; // l'occurence du mot dans le dictionnaire
            if (a->fd != NULL)
                afficherMots(s, a->fd);
        }
    }
}



//afficher tout le dictionnaire avec l'occurence da chaque mote
void dicoAfficher(TArbre a)
{
    cout<<"\n*******************************DICTIONNAIRE*******************************"<<endl;
    string s = "" ; 
    afficherMots(s, a);
    cout<<"\n";
}


//nombre de mots differents
int dicoNbMotsDifferents(TArbre a){

    if (a == NULL)
        return 0;
    if(a->val=='\0')
            return 1;
    else
        return dicoNbMotsDifferents(a->fg)  + dicoNbMotsDifferents(a->fd);    
}

//nombre de mots totals
int dicoNbMotsTotal(TArbre a){

    if (a == NULL)
        return 0;
    if(a->val=='\0')
            return a->occ;
    else
        return dicoNbMotsTotal(a->fg)  + dicoNbMotsTotal(a->fd);    
}

//occurence d'un mot dans le dictionnaire
int dicoNbOccMot(char mot[],TArbre noeud){    
	  if(noeud != NULL){
        if(mot[0] == noeud->val ){  //caractere a lire du mot == caractere actuel dans l'arbre
            if(mot[0] == '\0'){  // fin du mot
                  return noeud->occ;  //retourner l'occurence
            }else{
                mot++;  //passer au caractere suivant
                return dicoNbOccMot(mot,noeud->fg); //descendre gauche
            }
        }
        return dicoNbOccMot(mot,noeud->fd);  //descendre droite
      }
      return 0;
}

