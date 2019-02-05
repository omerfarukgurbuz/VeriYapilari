#include <stdio.h>
#include <stdlib.h>


struct n{
 int x;
 struct n * next;
};

typedef struct n node; 
void goster(node*);

int main(){
    node* root;//listenin baþlangýç elemanýný gösteren yapý
	root=(node*)malloc(sizeof(node)); 	
	

	node* iter;//liste üzerinde sürekli hareket eden node türünde yapý
	iter=root;
	int i=0;
	while(iter->next != NULL){
		
		 for(i=0;i<10;i++){
		 	iter->next=(node*)malloc(sizeof(node));
		 		iter->x=i;
		 	iter=iter->next;
		 
		 	iter->next=NULL;
		 	
		 }
}
 iter=root;
 //deger_ata(iter,6);
 iter=root;
 goster(iter);	
		
		
	
	return 0;
	
}

void goster(node* n){//ekrana bagli listin x degerlerini yazdirmak icin
	int i=0;
	while(n!= NULL){
		printf("%d inci dugumun inti: %d\n",i,n->x);
		n=n->next;
		i++;
		
	}	
}/*
void deger_ata(node* r,int y){
     while(r->next!=NULL){
     	
     	r->next=(node*)malloc(sizeof(node));
     	r->x=y;
     	r=r->next;
     	r->next->next=NULL;
     	
     	
	 }	
	
	
	
	
	
}*/

