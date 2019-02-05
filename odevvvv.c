#include <stdio.h>
#include <stdlib.h>
int top=0;
int boyut;


int elemanSayisi();
void push(int,int*);
void kuleAl(int*);
int kapsamaAlani(int*,int*);
void kopyala(int*,int*);
void tekrarla(int*,int*,int*,int);
int pop(int*);
void yazdir(int*);

int main(){
	int* dizi=(int*)malloc(sizeof(int)*elemanSayisi());
	int* kapsama=(int*)malloc(sizeof(int)*boyut);
	int dizi2[boyut];
	kuleAl(dizi);

	int topkop=top;
	tekrarla(dizi,dizi2,kapsama,topkop);
	
    yazdir(dizi);
    
    yazdir(kapsama);
    
    
    //yazdir(kapsama);
	
    return 0;	
}

int elemanSayisi(){
	printf("toplam kule sayiyisini girin:\n");
	int a;
	scanf("%d",&a);
	boyut=a;
	return a;
}



void kuleAl(int* ptr){
	int i;
	for(i=0;i<boyut;i++){
		printf("\nkuleboyu ekle:");
		int a;
		scanf("%d",&a);
		push(a,ptr);
	}
	
}
void kopyala(int* ptr,int* ptr2){
	int i;
	for(i=0;i<boyut;i++){
		ptr2[i]=ptr[i];
	}
}

int kapsamaAlani(int* ptr, int* ptr2){
	kopyala(ptr,ptr2);
    int deneme=pop(ptr);
    while(deneme!=ptr[top]){
    	deneme=pop(ptr);
	}
	
	int firstpop=ptr[top];
	int secondpop=pop(ptr);
	
	int i=1;
	while(firstpop>=secondpop){
		i++;
		if(top==0)
		    break;
		secondpop=pop(ptr);	
	}
	kopyala(ptr2,ptr);
	return i;
	
}


void tekrarla(int* ptr,int* ptr2,int* kapsa,int topp){
    int i;
    for(i=0;i<boyut;i++){
    	    
    	kapsa[boyut-(i+1)]=kapsamaAlani(ptr,ptr2);
		top=topp-(i+1);    
	}
}



void push(int a,int* ptr){
	
	ptr[top++]=a;	
}


int pop(int* ptr){
	
	return ptr[--top];
}


void yazdir(int* ptr){
	printf("\n-----------------------------\n");

	int i;
	for(i=0;i<boyut;i++){
		printf("%d\t",ptr[i]);
	}
}
