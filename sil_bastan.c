#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;
int main(){
	node* root;
	root=(node*)malloc(sizeof(node));
	node* iter;
	iter=root;
	node* available;
	available=(node*)malloc(sizeof(node));
	
	int i; 
	for(i;i<5;i++){
		iter->x=i;
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		iter->next=NULL;
	}
	iter=root;
	
	
    while(iter->next!=NULL){
    	println("iter x:%d\n",iter->x);
    	iter=iter->next;
	}
	return 0;
	}
