#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;


int main(){
	node* root;//baslangic d���m� belirledim
	root=(node*)malloc(sizeof(node));
	node* iter;//iter belirledim bunu roota e�itledim bu s�rekli hareket edecek
	iter=root;
    node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->x=12093;
	int i=0;
	for(i;i<10;i++){//10 d���ml� bir lba�l� liste tan�mlad�m
		iter->x=i;
		iter->next=(node*)malloc(sizeof(node));//sonraki d���me de�er atamak i�in her seferinde sonraki d���m� tan�mlad�m
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

