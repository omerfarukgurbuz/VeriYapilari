#include <stdio.h>
#include  <stdlib.h>

struct n{
	int x;
	struct n*  next;
};

typedef struct n node;
int main(){
	node* root;
	root=(node*)malloc(sizeof(node));
	node* iter;
	iter=(node*)malloc(sizeof(node));
	iter=root;
	int i;
	for(i=0;i<5;i++){
		iter->x=i;
		iter=iter->next;

	}
    iter->next=NULL;
	iter=root;
	while(iter->next!=NULL){
		printf("iter info: %d\n",iter->x);
		iter=iter->next;
	}
	return 0;
}


