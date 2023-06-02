#include<bits/stdc++.h>
using namespace std;

// Construct an empty tree
BST newBST(){
    return(NULL);
};


// Test if the tree is empty or not
string emptyBST(BST a){
    if(a==NULL)
        return("yes");
    else return("no");
}


// Construct a node of the tree
BST newNode(char c, int n,BST left, BST right){
    BST a = new node();
    a->val= c;
    a->left= left;
    a->right= right;
    a->occ=n;
    return(a);
}


// Return the letter of the node
char nodeChar(BST a){
    return(a->val);
}


// Return the occurrence of the letter of the node
int nodeCharNbOcc(BST a){
    return(a->occ);
}

// Return the left child of the node
BST leftBST(BST a){
    if(a!=NULL)
        return(a->left);
}

// Return the right child of the node
BST rightBST(BST a){
    if(a!=NULL)
        return(a->right);
}

// Deletion of the tree
void deleteBST(BST *a){
    while(*a != NULL){
        deleteBST(&((*a)->right));
        deleteBST(&((*a)->left));
        free(*a) ;
        *a = NULL;
    }
}


// Return the height of the tree
int heightBST(BST a){
    if(a!=NULL){
        return(1+ max(heightBST(a->right),heightBST(a->left)));
    }
    else return(0);
}