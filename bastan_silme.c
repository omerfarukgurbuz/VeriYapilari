#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};

typedef struct n node;
void bagla(node*,node*);
void yazdir(node*);
int main(){
	node* root;
	root=(node*)malloc(sizeof(node));
	node* iter;
	iter=root;
	node* available;
	available=(node*)malloc(sizeof(node));

	
	bagla(iter,root);
	
    iter=root;
	while(iter->next!=NULL){
	 if(iter==root){
	 	available=root;
	 	root=root->next;
	 	iter=root;
	 }	
 	iter=iter->next;
	}
	iter=root;
		

	yazdir(root);


	    
	

	
	return 0;
}



//burda bagli listeyi tanýmladým ve info kýsmýna deðer atadým
void bagla(node* liste,node* basla){
	liste=basla;
	int i;
	for(i=0;i<1;i++){
		liste->x=i;
		liste->next=(node*)malloc(sizeof(node));
		liste=liste->next;
		liste->next=NULL;
	}
	
	liste=basla;	
}



/*
void cikar(node* liste,node* basla,node* temp){
    liste=basla;
	
	while(liste->next!=NULL){
		
		if(liste->x==basla->x){
			temp=basla;
			basla=basla->next;
		
			
		}
     liste=liste->next;
	}		
    liste=basla;
		
}
*/



void yazdir(node* liste){
	while(liste!=NULL){
		printf("%d \n",liste->x);
		liste = liste->next;
	}	
}
