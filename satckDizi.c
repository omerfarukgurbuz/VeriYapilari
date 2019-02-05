#include <stdio.h>
#include <stdlib.h>

int *dizi;
int boyut=2;
int top=0;

int pop();
void push(int);
void goster();

int main(){
	dizi=(int*)malloc(sizeof(int)*2);
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	
	
	goster();
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
    goster();		

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);
	
	
	goster();
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
	printf("%d pop edildi\n",pop());
	goster();				
}



void push(int a){
	if(top>=boyut){//zirve boyuttan daha büyükse veya eþitse boyutu 2 katýnaçýkar ve eski dizi sil
		int *dizi2=(int*)malloc(sizeof(int)*boyut*2);
		int i;
		for(i=0;i<boyut;i++){
			dizi2[i]=dizi[i];
		}
		free(dizi);
		dizi=dizi2;
		boyut*=2;
		
	}
	dizi[top++]=a;
}



int pop(){
	if(top<=boyut/4){//zirve boyutun 4 te 1 i ise boyutu yarýya indir eski diziyi sil
		int *dizi2=(int*)malloc(sizeof(int)*(boyut/2));
		int i;
		for(i=0;i<boyut/2;i++){
			dizi2[i]=dizi[i];
		}
		free(dizi);
		dizi=dizi2;
		boyut /=2;
	}
	return dizi[--top];	
}


void goster(){//yazdýr
	printf("\nboyut: %d\n",boyut);
	int i;
	for(i=0;i<top;i++){
		printf("%d\n",dizi[i]);	
	}
}
