#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;

node* siraliEkle(node*,int);//s�ral� ekleme algoritmas�
node* sil(node*,int);//se�ilen d���m� siler
void yazdir(node*);//yazd�rma

int main(){
	
	node* root;  root=NULL;
	root=siraliEkle(root,500);//fonksiyon her seferinde root de�erini d�nd�rece�i i�in e�er root de�i�irse diye bu atama �artt�r
	root=siraliEkle(root,600);
	root=siraliEkle(root,50);
	root=siraliEkle(root,55);
	root=siraliEkle(root,5);
	root=siraliEkle(root,999);
		
	root=sil(root,50);
	root=sil(root,5);
    root=sil(root,66);
    
	yazdir(root);
					
	
	
	
	
	return 0;
    }




node* siraliEkle(node* rootf,int xf){	
	
	if(rootf==NULL){//root bo� ise yani hen�z hi� eleman yoksa
		rootf=(node*)malloc(sizeof(node));
		rootf->next=NULL;
		rootf->x=xf;
		return rootf;
	    }
	    
	if(rootf->x>xf){//yeni eklenecek eleman�n x i rootun x inden k���kse
		node* tempf=(node*)malloc(sizeof(node));
	    tempf->x=xf;
	    tempf->next=rootf;
	    return tempf;
	    }  
	    
	node* iterf=rootf;
	while(iterf->next!=NULL&&iterf->next->x <xf){//eklenecek eleman�n iterin xi x den k���ks oldu�u s�rece veya null olmad��� s�rece git 
		iterf=iterf->next;
	    }
	
	node* tempf=(node*)malloc(sizeof(node));
	tempf->next=iterf->next;
	iterf->next=tempf;
	tempf->x=xf;

	return rootf;//root de�erimiz de�i�ti ise yeni rootu d�nd�rmek
	}



node* sil(node* rootf,int xf){
	node* tempf;
	node* iterf=rootf;
	
	if(rootf->x==xf){//e�er ilk eleman xf e e�itse temp=root  ve yeni root =root->next 
		tempf=rootf;
		rootf=rootf->next;
		free(tempf);
		return rootf;
	    }
	    
	while(iterf->next!=NULL&&iterf->next->x!=xf){//e�itlik olmad��� s�rece ve next =null olmad��� s�rece iteri sonraki d���me g�t�r
		iterf=iterf->next;
	    } 
	
	if(iterf->next==NULL){//yukardaki iki durumdan biri olan iterin nexti =null ise son elemana gelmi�iz demektir ve bulunamad�
		printf("sayi bulunamadi\n");
		return rootf;
	    }
	    
	tempf=iterf->next;//di�er durum listenin ortas�nda bi yerde elemana denk gelmi�izdir ve al�p sileriz
	iterf->next=iterf->next->next;
	free(tempf);
	return rootf;
    }




//yazdirma islemi iter =NULL olana kadar	
void yazdir(node* iterf){
	
	    while(iterf!=NULL){
	    	
    	    printf("iter x:%d\n",iterf->x);
    	    iterf=iterf->next;
	        }	
	        
	    }
	   
