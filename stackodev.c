#include <stdio.h>
#include <stdlib.h>

int *dizi;
int *kapsama;
int boyut=2;
int top=0;

int pop();
void push(int);
void yazdir();
void kule_al();
void kapsama_alani();
void yazdirKapsama();

int main(){
	dizi=(int*)malloc(sizeof(int)*2);
	kule_al();
	kapsama=(int*)malloc(sizeof(int)*boyut);	
	kapsama_alani();
	//yazdirKapsama();
	yazdir();
}

void push(int a){
	if(top>=boyut){
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
	if(top<=boyut/3){
		int *dizi2=(int*)malloc(sizeof(int)*(boyut/2));
		int i;
		for(i=0;i<boyut;i++){
			dizi2[i]=dizi[i];
		}
		free(dizi);
		dizi=dizi2;
		boyut/=2;
	}
	return dizi[--top];
}



void kule_al(){
	int kule;
	printf("kulelerin kapsama alanlarini sirasiyla giriniz ve\n son kuleyi de girdikten sonra -9 a basiniz\n");
	while(1==1){
		printf("\nkulenin kapsama alanini giriniz veya -9 EXIT\n");
		scanf("%d",&kule);
		if(kule==-9){
			break;
		}
		push(kule);
	}
}
void kapsama_alani(){
	int j = 0;
	int c = 0;
	int tmp = top;
	int *fakedizi = (int*) malloc(sizeof(int)*boyut);
	int eskiboyut = boyut;
	for(c = 0; c<boyut; c++)
		fakedizi[c] = dizi[c];
	for(j=0; j<tmp;j++){
		perror("bas");
		
		int ilkpop = pop();
		int sonrakipop = pop();
		int i=1;
		perror("ikinciwhiledanonce");
		while(ilkpop>=sonrakipop){
			if(top == 0)
				break;
			i++;
			sonrakipop = pop();
		}
		perror("ikinciwhiledansonra");
	
		for(c = 0; c<eskiboyut-(j+1); c++)
			dizi[c] = fakedizi[c];
		perror("freedan sonra");
		kapsama[j] = i;
		top = tmp-(j+1);
			
	}
}
	



void yazdir(){
	printf("boyut: %d\n",boyut);
	int i;
	for(i=0;i<top;i++){
		printf("%d\t",dizi[i]);
	}
}

void yazdirKapsama(){
	int i=0;
	for(i;i<top;i++){
		printf("kapsama %d\n",kapsama[i]);
	}
	
	
}
