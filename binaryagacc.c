#include <stdio.h>
#include <stdlib.h>

struct n{
	
	int data;
	struct n* sol;
	struct n* sag;
};

typedef struct n node;

node* ekle(node*,int);
void dolasLNR(node*);
void dolasRNL(node*);
int bul(node*,int);
int max(node*);
int min(node*);




int main(){
	node* agac=NULL;
        node* deneme=NULL;
	
	
	agac=ekle(agac,12);
	agac=ekle(agac,200);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,56);
	agac=ekle(agac,24);
	agac=ekle(agac,18);
	agac=ekle(agac,27);
	agac=ekle(agac,28);
        dolasLNR(agac);
        dolasRNL(agac);
	
        printf("%d ",bul(agac,276));
        printf("%d ",max(agac));
        printf("%d ",min(agac));
        
	
}

node* ekle(node* agac,int x){
    
    if(agac==NULL){//hicbir node yoksa
        node* root=(node*)malloc(sizeof(node));
        root->data=x;
        root->sag=NULL;
        root->sol=NULL;
        return root;
    }
    
    
    if(agac->data<x){//eger x buyuksa saga ekleme yapar
        agac->sag=ekle(agac->sag,x);
        return agac;
    }
    
    
    agac->sol=ekle(agac->sol,x);//eger x kucuksa sola ekleme
    return agac;
}



void dolasLNR(node* agac){
    if(agac==NULL){//agac null olunca return yap
        return;
    }
    dolasLNR(agac->sol);//agacın solu boyunca agac null oluncaya kadar git
    printf("%d  ",agac->data);
    dolasLNR(agac->sag);// agacın sagına git           
}



void dolasRNL(node* agac){
    if(agac==NULL){
        return;
    }
    dolasRNL(agac->sag);
    printf("%d  ",agac->data);
    dolasRNL(agac->sol);           
}

int bul(node* agac,int aranan){
    if(agac==NULL)
        return -1;
    if(agac->data==aranan)
        return 1;
    if(bul(agac->sol,aranan)==1){
        return 1;
    }
    if(bul(agac->sag,aranan)==1)
        return 1;
}


int max(node* agac){
    if(agac==NULL)
        return -1;
    
    if(agac->sag==NULL){
        return agac->data;
    }
    max(agac->sag);
}


int min(node* agac){
    if(agac==NULL)
        return -1;
    
    if(agac->sol==NULL){
        return agac->data;
    }
    min(agac->sol);
}
