#include <stdio.h>
#include <stdlib.h>
/*hocam bu program� stacksiz yazmak 1 saatimi almazd� fakat stack dedi�iniz i�in hi� bir yerinde stack mant���n�n d���na ��kmadan sadece
push ve pop fonksiyonlar�n� kullanarak elemanlara eri�tim .Tam 2 g�n�m gitti bu 2 �dev i�in*/ 
int top=0;
int boyut;


int  elemanSayisi();
void push(int,int*);
int  pop(int*);

void kuleAl(int*);
int  kapsamaAlani(int*,int*);

void kopyala(int*,int*);
void tekrarla(int*,int*,int*,int);
void yazdir(int*);




int main(){
	int* dizi=(int*)malloc(sizeof(int)*elemanSayisi());//Stack olu�turdum
	int* kapsama=(int*)malloc(sizeof(int)*boyut);//kapsama alanlar�n�n saklanaca�� ba�ka bir stack
	
	int dizi2[boyut];//stack 1 in kopyalama i�leminde kullan�lacak
	kuleAl(dizi);
	
	int topkop=top;
    tekrarla(dizi,dizi2,kapsama,topkop);//Kapsama alanlar�n� bulup yerine koyan fonk
	
    yazdir(dizi);
    yazdir(kapsama);
    
	
    return 0;	
}




int elemanSayisi(){//Stack�n boyutunu al�r
	printf("toplam kule sayiyisini girin:\n");
	int a;
	scanf("%d",&a);
	boyut=a;
	return a;
}



void kuleAl(int* ptr){//Girilen kule boylar�n� s�rayla push eder
	int i;
	for(i=0;i<boyut;i++){
		printf("\nkuleboyu ekle:");
		int a;
		scanf("%d",&a);
		push(a,ptr);
	}
	
}



/*beni en �ok ura�t�ran k�s�mlardan biriydi ��nk� 
ben ilk ba�ta bu kopyalama i�lemini ptr2=ptr1 yaparak halledece�imi zannettim fakat
bu �ekilde bir kopyalama s�� kopyalama oluyo ve haf�zada g�sterilen tek bir adres var b�yle olunca 
yap�lan de�i�iklikler her iki kopyay�da etkiliyo ki yakla��k bi 5 saat u�ra�t�ktan sonra sorunun burda
olaca�� akl�m�n ucundan bile ge�mezdi ama farkettim ve deep kopy yaparak burdaki sorunu d�zelttim*/
void kopyala(int* ptr,int* ptr2){//deep copy i�lemi 
	int i;
	for(i=0;i<boyut;i++){
		ptr2[i]=ptr[i];
	}
}




int kapsamaAlani(int* ptr, int* ptr2){//pop komutunu kullanarak kulelerin kapsama alan�n� buldum
	kopyala(ptr,ptr2);
    int deneme=pop(ptr);
    while(deneme!=ptr[top]){
    	deneme=pop(ptr);
	}
	
	int firstpop=ptr[top];
	int secondpop=pop(ptr);
	
	int i=1;
	while(firstpop>=secondpop){//ilk pop edilen eleman yani top daki elemandan daha b�y�k bi de�er kar��s�na pop edilmedi�i s�rece kapsama alan�n� art�r
		i++;
		if(top==0)
		    break;
		secondpop=pop(ptr);	
	}
	kopyala(ptr2,ptr);//stacki pop edip bo�alt���m�z i�in eski stacki geri kopyalad�m
	return i;
	
}




void tekrarla(int* ptr,int* ptr2,int* kapsa,int topp){//burda da verilen stackteki t�m elemanlar i�in kapsama alan� fonksiyoununu �a��r tabi sondan ba�a do�ru yine
    int i;
    for(i=0;i<boyut;i++){
    	    
    	kapsa[boyut-(i+1)]=kapsamaAlani(ptr,ptr2);
		top=topp-(i+1);    
	}
}




void push(int a,int* ptr){//push fonksiyounu 
	
	ptr[top++]=a;	
}




int pop(int* ptr){//pop fonksiyonu 
	
	return ptr[--top];
}




void yazdir(int* ptr){//yazdirma i�lemi
	printf("\n-----------------------------\n");

	int i;
	for(i=0;i<boyut;i++){
		printf("%d\t",ptr[i]);
	}
}


