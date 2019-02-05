#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n* next;
};
typedef struct n node;



node* ekle(node*,int);
node* birlestir(node*,node*);
void bastir(node*);




int main(){
	node* root=NULL;
	node* root2=NULL;
	
	
	//bu kisimda 1 den 10 a kadar sayilari alip bir bagli listeye ekledik istersek daha fazla veya az sayi alabiliriz
	//ben scanf ile surekli sormasin diye boyle gosterdim zaten amac 2 baglilisteyi birlestirmek 
	int i=0;
	for(i;i<10;i++)
		root=ekle(root,i);
	
	//burda 2.bagli listenin elemanlarini aldik
	for(i=20;i>=0;i--)
		root2=ekle(root2,i);
		
    //birlestirme islemi		
	root=birlestir(root,root2);	
	bastir(root);

	
	return 0;
}






node* ekle(node* root,int x){//Girilen elemanlari bagli listeye ekleyen fonk
	if(root==NULL){
		node* temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=NULL;
		return temp;
	}
	


	node* iter=root;
	while(iter->next!=NULL)
		iter=iter->next;
	
	
		
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	iter->next=temp;
	return root;	
}






node* birlestir(node* root,node* root2){//iki bagli listeyi birlestiren fonk
	node* iter=root;
	node* iter2=root2;
	
	while(iter->next!=NULL)
		iter=iter->next;
	
	iter->next=iter2;
	return root;	
	
}





void  bastir(node* root){//ekrana yazdiran fonk
	node* iter=root;
	
	while(iter!=NULL){
		printf("%d ",iter->data);
		iter=iter->next;
	}
	
}

