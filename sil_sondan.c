#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;


int main(){
    node* root;   root=(node*)malloc(sizeof(node));
    node* iter;   iter=root;
    node* temp;   temp=(node*)malloc(sizeof(node));	 temp->next=NULL;
    bagla(iter);
	iter=root; 
	while(iter!=NULL){
		if(iter->next->next==NULL){
			temp=iter;
			iter->next=NULL;
			break;
		}
		iter=iter->next;
	}
	iter=root;
	yazdir(iter,temp);
     
	
	
return 0;	
}



void bagla (node* iterf){
	    int i; 
	    for(i;i<5;i++){
		    iterf->x=i;
		    iterf->next=(node*)malloc(sizeof(node));
		    iterf=iterf->next;
		    iterf->next=NULL;}
	}
	
	

			
//yazdirma islemi iter in nexti 0 olana kadar	
void yazdir(node* iterf,node* tempf){
	    while(iterf->next!=NULL){
    	    printf("iter x:%d\n",iterf->x);
    	    iterf=iterf->next;
	        }	
	        printf("available %d",tempf->x);
	   }

	  
