#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;

node* siraliEkle(node*,int);//sýralý ekleme algoritmasý
node* sil(node*,int);//seçilen düðümü siler
void yazdir(node*);//yazdýrma

int main(){
	
	node* root;  root=NULL;
	root=siraliEkle(root,500);//fonksiyon her seferinde root deðerini döndüreceði için eðer root deðiþirse diye bu atama þarttýr
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
	
	if(rootf==NULL){//root boþ ise yani henüz hiç eleman yoksa
		rootf=(node*)malloc(sizeof(node));
		rootf->next=NULL;
		rootf->x=xf;
		return rootf;
	    }
	    
	if(rootf->x>xf){//yeni eklenecek elemanýn x i rootun x inden küçükse
		node* tempf=(node*)malloc(sizeof(node));
	    tempf->x=xf;
	    tempf->next=rootf;
	    return tempf;
	    }  
	    
	node* iterf=rootf;
	while(iterf->next!=NULL&&iterf->next->x <xf){//eklenecek elemanýn iterin xi x den küçüks olduðu sürece veya null olmadýðý sürece git 
		iterf=iterf->next;
	    }
	
	node* tempf=(node*)malloc(sizeof(node));
	tempf->next=iterf->next;
	iterf->next=tempf;
	tempf->x=xf;

	return rootf;//root deðerimiz deðiþti ise yeni rootu döndürmek
	}



node* sil(node* rootf,int xf){
	node* tempf;
	node* iterf=rootf;
	
	if(rootf->x==xf){//eðer ilk eleman xf e eþitse temp=root  ve yeni root =root->next 
		tempf=rootf;
		rootf=rootf->next;
		free(tempf);
		return rootf;
	    }
	    
	while(iterf->next!=NULL&&iterf->next->x!=xf){//eþitlik olmadýðý sürece ve next =null olmadýðý sürece iteri sonraki düðüme götür
		iterf=iterf->next;
	    } 
	
	if(iterf->next==NULL){//yukardaki iki durumdan biri olan iterin nexti =null ise son elemana gelmiþiz demektir ve bulunamadý
		printf("sayi bulunamadi\n");
		return rootf;
	    }
	    
	tempf=iterf->next;//diðer durum listenin ortasýnda bi yerde elemana denk gelmiþizdir ve alýp sileriz
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
	   
