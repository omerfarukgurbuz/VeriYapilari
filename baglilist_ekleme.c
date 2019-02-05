#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;


int main(){
	node* root;//baslangic düðümü belirledim
	root=(node*)malloc(sizeof(node));
	node* iter;//iter belirledim bunu roota eþitledim bu sürekli hareket edecek
	iter=root;
    node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->x=12093;
	int i=0;
	for(i;i<10;i++){//10 düðümlü bir lbaðlý liste tanýmladým
		iter->x=i;
		iter->next=(node*)malloc(sizeof(node));//sonraki düðüme deðer atamak için her seferinde sonraki düðümü tanýmladým
		iter=iter->next;
		if(i==2){
			temp->next=iter->next;
			iter->next=temp;
		}
		if(i==9)
		iter->next=NULL;
		
	}

	
	
  yazdir(root);	
	
return 0;	
}

void yazdir(node* link){
	int i=0;
	while(link->next!=NULL){
		printf("%d sira deger %d\n",i,link->x);
		link=link->next;
		i++;
	}	
}

