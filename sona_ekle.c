#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;

void bagla(node*);
void yazdir(node*);

int main(){
	node* root;    root=(node*)malloc(sizeof(node));
	node* iter;    iter=root;
	node* temp;    temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	temp->x=1000;
	
	bagla(iter);
	iter=root;
	
	while(iter!=NULL){
		if(iter->next->next==NULL){
			iter->next=temp;
			break;
		}
		iter=iter->next;	
	}
	
	iter=root;
	yazdir(iter);
	
	
return 0;	
}



//Baðlý listemizi burda tanýmladým 5 elemaný olan bir bagli list	
	void bagla (node* iterf){
	    int i; 
	    for(i;i<10;i++){
		    iterf->x=i;
		    iterf->next=(node*)malloc(sizeof(node));
		    iterf=iterf->next;
		    iterf->next=NULL;}
	}		




//yazdirma islemi iter in kendi  0 olana kadar	
	void yazdir(node* iterf){
	    while(iterf!=NULL){
    	    printf("iter x:%d\n",iterf->x);
    	    iterf=iterf->next;
	        }	

	   }
	   
