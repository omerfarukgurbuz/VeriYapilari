#include <stdio.h>
#include <stdlib.h>


struct n{
    int data;
    struct n* left;
    struct n* right;
};
typedef struct n node;

node* ekle(node*,int);
void dolasLNR(node*);



int main(){

    node* agac=(node*)malloc(sizeof(node));
    agac=ekle(agac,20);
    agac=ekle(agac,2);
    agac=ekle(agac,200);
    agac=ekle(agac,25);
    agac=ekle(agac,10);
    dolasLNR(agac);




}




node* ekle(node* agac,int x){

    if(agac == NULL){
        node* root = (node*)malloc(sizeof(node));
        root -> left = NULL;
        root -> right = NULL;
        root -> data = x;
        return root;
    }


    if(agac -> data < x)
        agac ->right = ekle(agac -> right,x); return agac;

    agac->left =ekle(agac->left,x);
    return agac;
}



void dolasLNR(node* agac){

    if(agac==NULL)
        return;

    dolasLNR(agac->left);
    printf("%d ",agac->data);
    dolasLNR(agac->right);

}





















