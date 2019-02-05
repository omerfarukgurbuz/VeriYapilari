#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};
typedef struct n node;

node* ekleSiraliDairesel(node*, int) ;//dairesel s�ral� ekleme yapan fonk
node* silDairesel(node*,int);//dairesel se�ilen d���m� silen fonk
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
	
	if(rootf==NULL){//hi� eleman olmama durumu bir eleman �retiriz ve bunun kendini g�stermesini sa�lar�z
	    rootf=(node*)malloc(sizeof(node));
		rootf->x=xf;
		rootf->next=rootf;
		
		return rootf;	
	    }
	
	if(rootf->x >xf){//ilk eleman�n yani rootun x i xf den b�y�k olma durumu
	    node* tempf=(node*)malloc(sizeof(node));//yeni bir d���m yapar�z ve nextine root u koyar�z 
	    tempf->x=xf;
	    tempf->next=rootf;
	    node* iterf=rootf;
	    
	    while(iterf->next!=rootf){//son eleman�n root u g�stermesini istedi�imiz i�in son eleman� buluruz
	    	iterf=iterf->next;
		    }
		    
		iterf->next=tempf;//son eleman�n nextine yeni rootumuzu yani tempi koyar�z
		return tempf;
		}
	
	node*iterf=rootf;
	while(iterf->next!=rootf&&iterf->next->x<xf){//x xf den k���k oldu�u s�rece git yada son roota gelinceye kadar  
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
	
	if(rootf->x==xf){//listenin ba��ndan silme durumu
		while(iterf->next!=rootf){//son eleman� bulup onun g�sterdi�i yeri bulup
			iterf=iterf->next;
		    }
		    
		iterf->next=rootf->next;//buldu�umuz yeri yeni root a e�itledik    
		free(rootf);
		return iterf->next;
	    }
	
	while(iterf->next!=rootf&&iterf->next->x!=xf){//ilk elemana gelinceye kadar yada arad���m�z eleman� buluncaya kadar iteri ilerlet 
		iterf=iterf->next;
	    }
    
	if(iterf->next==rootf){//e�er iterin nexti  root u g�steriyosa arad���m�z eleman� bulamad�k demektir 
		printf("eslesen eleman bulunamadi\n");
		return rootf;
	    } 	
	
	tempf=iterf->next;//di�er durumda iterin nextini silece�imiz i�in yeni iterin nexti = iter->next->next olur 
	iterf->next=iterf->next->next;
	free(tempf);
	return rootf;
    }     
    


void yazdir(node* rootf){
	
	node* iterf=rootf;//tek eleman olunca sorun ya�amamak i�in 
	printf("%d\n",iterf->x);
	iterf=iterf->next;

	while(iterf!=rootf){//iter=root oluncaya kadar
		printf("%d\n",iterf->x);
		iterf=iterf->next;
	    }
    }    
