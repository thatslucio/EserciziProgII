/*  Scrivere le function C per la visita (preorder, inorder e postorder) di un albero binario rappresentato
mediante array.  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int data;
    struct nodo *sinista;
    struct nodo *destra;
}nodo;

typedef nodo *albero;

albero init(int,albero,albero);
albero crea(int [],int ,int );
void inorder(albero);
void preorder(albero);
void postorder(albero);


int main(){

    albero tree;
    int a[] = {1,2,3,4,5,6};

    tree = crea(a,0,6);

    printf("\n---Visita inorder---\n");
    inorder(tree);

    printf("\n---Visita preorder---\n");
    preorder(tree);

    printf("\n---Visita postorder---\n");
    postorder(tree);


    return 0;
}

albero init(int d1,albero p1,albero p2){

    albero t;
    t = malloc(sizeof(nodo));

    t->data = d1;
    t->sinista = p1;
    t->destra = p2;

    return t;
}

albero crea(int a[],int i,int size){
    if(i>=size)
    return NULL;

    else
    return init(a[i],crea(a,2*i+1,size),crea(a,2*i+2,size));
}

void inorder(albero tree){

    if(tree != NULL){
        inorder(tree->sinista);
        printf("%d ",tree->data);
        inorder(tree->destra);
    }
}

void preorder(albero tree){

    if(tree != NULL){
        printf("%d ",tree->data);
        inorder(tree->sinista);
        inorder(tree->destra);
    }
}

void postorder(albero tree){

    if(tree != NULL){
        inorder(tree->sinista);
        inorder(tree->destra);
        printf("%d ",tree->data);
    }
}
