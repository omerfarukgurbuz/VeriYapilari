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
 	root->next=NULL;
 	int i;
 	for(i=0;i<5;i++){
 		iter->x=i;
 		iter->next=(node*)malloc(sizeof(node));
 		iter=iter->next;
	 }
	 iter->next=NULL;
	 iter=root;
	 node* temp;
	 temp=(node*)malloc(sizeof(node));
	 temp->next=(node*)malloc(sizeof(node));
	 temp=root;
	 root=root->next;
	 iter=root;
	 while(iter->next->next!=NULL){
	 	iter=iter->next;
	 	
	 }
	temp->next=iter->next;
	temp->next->next=NULL;
	iter->next=iter->next->next;
	 iter=root;
 	while(iter->next!=NULL){
 		printf("iter x %d\n",iter->x);
 		iter=iter->next;
	 }
 	 	while(temp!=NULL){
 		printf("iter x %d\n",temp->x);
 		temp=temp->next;
	 }
 	
 	return 0;
 }
 
 
