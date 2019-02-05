#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;
void bagla(node*);
void yazdir(node*,node*);
int main(){
	node* root;    root=(node*)malloc(sizeof(node));
    node* iter;    iter=root;
	node* temp;    temp=(node*)malloc(sizeof(node));
	
	bagla(iter);
	iter=root;
	
	while(iter->next!=NULL){
		if(iter->next->x==15){
			temp=iter->next;
			iter->next=iter->next->next;
		    break;
		}
		iter=iter->next;
	}
	iter=root;
	yazdir(iter,temp);
	
	

	return 0;
}

//Baðlý listemizi burda tanýmladým 5 elemaný olan bir bagli list	
	void bagla (node* iterf){
	    int i; 
	    for(i;i<20;i++){
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
	   
