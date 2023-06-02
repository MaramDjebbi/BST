#ifndef DEF_BST
#define DEF_BST

#include<bits/stdc++.h>
using namespace std;


struct node{
    char val;
    node* left;
    node* right;
    int occ=0;
};

typedef node* BST;  

BST newBST();
string emptyBST(BST);
BST newNode(char, int, BST, BST, int);
char nodeChar(BST);
int nodeCharNbOcc(BST);
BST leftBST(BST);
BST rightBST(BST);
void deleteBST(BST*);
int heightBST(BST);

//void printBST(node*, int, int, int) ;
//void printBSTT(node* a);

#endif
