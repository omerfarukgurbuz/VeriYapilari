#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;

node* ekleSiraliDairesel(node*, int) ;//dairesel sýralý ekleme yapan fonk
node* silDairesel(node*,int);//dairesel seçilen düðümü silen fonk
void yazdir(node*);

int main(){
	node* root;  root=NULL;
	
	root=ekleSiraliDairesel(root,10);
	root=ekleSiraliDairesel(root,100);
	root=ekleSiraliDairesel(root,1);	
	root=ekleSiraliDairesel(root,11);
	root=ekleSiraliDairesel(root,1000);
	root=ekleSiraliDairesel(root,10000);
	root=silDairesel(root,1);
	root=silDairesel(root,10000);
    root=silDairesel(root,100);	
	root=silDairesel(root,9);    

	yazdir(root);
	
	return 0;
    }



node* ekleSiraliDairesel(node* rootf,int xf){
	
	if(rootf==NULL){//hiç eleman olmama durumu bir eleman üretiriz ve bunun kendini göstermesini saðlarýz
	    rootf=(node*)malloc(sizeof(node));
		rootf->x=xf;
		rootf->next=rootf;
		
		return rootf;	
	    }
	
	if(rootf->x >xf){//ilk elemanýn yani rootun x i xf den büyük olma durumu
	    node* tempf=(node*)malloc(sizeof(node));//yeni bir düðüm yaparýz ve nextine root u koyarýz 
	    tempf->x=xf;
	    tempf->next=rootf;
	    node* iterf=rootf;
	    
	    while(iterf->next!=rootf){//son elemanýn root u göstermesini istediðimiz için son elemaný buluruz
	    	iterf=iterf->next;
		    }
		    
		iterf->next=tempf;//son elemanýn nextine yeni rootumuzu yani tempi koyarýz
		return tempf;
		}
	
	node*iterf=rootf;
	while(iterf->next!=rootf&&iterf->next->x<xf){//x xf den küçük olduðu sürece git yada son roota gelinceye kadar  
		iterf=iterf->next;
	    } 
		   
	node* tempf=(node*)malloc(sizeof(node));
	tempf->x=xf;
	tempf->next=iterf->next;
	iterf->next=tempf;
	
	return rootf;	
    }



node* silDairesel(node*rootf,int xf){
	node* tempf;
	node* iterf=rootf;
	
	if(rootf->x==xf){//listenin baþýndan silme durumu
		while(iterf->next!=rootf){//son elemaný bulup onun gösterdiði yeri bulup
			iterf=iterf->next;
		    }
		    
		iterf->next=rootf->next;//bulduðumuz yeri yeni root a eþitledik    
		free(rootf);
		return iterf->next;
	    }
	
	while(iterf->next!=rootf&&iterf->next->x!=xf){//ilk elemana gelinceye kadar yada aradýðýmýz elemaný buluncaya kadar iteri ilerlet 
		iterf=iterf->next;
	    }
    
	if(iterf->next==rootf){//eðer iterin nexti  root u gösteriyosa aradýðýmýz elemaný bulamadýk demektir 
		printf("eslesen eleman bulunamadi\n");
		return rootf;
	    } 	
	
	tempf=iterf->next;//diðer durumda iterin nextini sileceðimiz için yeni iterin nexti = iter->next->next olur 
	iterf->next=iterf->next->next;
	free(tempf);
	return rootf;
    }     
    


void yazdir(node* rootf){
	
	node* iterf=rootf;//tek eleman olunca sorun yaþamamak için 
	printf("%d\n",iterf->x);
	iterf=iterf->next;

	while(iterf!=rootf){//iter=root oluncaya kadar
		printf("%d\n",iterf->x);
		iterf=iterf->next;
	    }
    }    
