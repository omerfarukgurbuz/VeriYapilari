#include <stdio.h>
#include <stdlib.h>
/*hocam bu programý stacksiz yazmak 1 saatimi almazdý fakat stack dediðiniz için hiç bir yerinde stack mantýðýnýn dýþýna çýkmadan sadece
push ve pop fonksiyonlarýný kullanarak elemanlara eriþtim .Tam 2 günüm gitti bu 2 ödev için*/ 
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
	int* dizi=(int*)malloc(sizeof(int)*elemanSayisi());//Stack oluþturdum
	int* kapsama=(int*)malloc(sizeof(int)*boyut);//kapsama alanlarýnýn saklanacaðý baþka bir stack
	
	int dizi2[boyut];//stack 1 in kopyalama iþleminde kullanýlacak
	kuleAl(dizi);
	
	int topkop=top;
    tekrarla(dizi,dizi2,kapsama,topkop);//Kapsama alanlarýný bulup yerine koyan fonk
	
    yazdir(dizi);
    yazdir(kapsama);
    
	
    return 0;	
}




int elemanSayisi(){//Stackýn boyutunu alýr
	printf("toplam kule sayiyisini girin:\n");
	int a;
	scanf("%d",&a);
	boyut=a;
	return a;
}



void kuleAl(int* ptr){//Girilen kule boylarýný sýrayla push eder
	int i;
	for(i=0;i<boyut;i++){
		printf("\nkuleboyu ekle:");
		int a;
		scanf("%d",&a);
		push(a,ptr);
	}
	
}



/*beni en çok uraþtýran kýsýmlardan biriydi çünkü 
ben ilk baþta bu kopyalama iþlemini ptr2=ptr1 yaparak halledeceðimi zannettim fakat
bu þekilde bir kopyalama sýð kopyalama oluyo ve hafýzada gösterilen tek bir adres var böyle olunca 
yapýlan deðiþiklikler her iki kopyayýda etkiliyo ki yaklaþýk bi 5 saat uðraþtýktan sonra sorunun burda
olacaðý aklýmýn ucundan bile geçmezdi ama farkettim ve deep kopy yaparak burdaki sorunu düzelttim*/
void kopyala(int* ptr,int* ptr2){//deep copy iþlemi 
	int i;
	for(i=0;i<boyut;i++){
		ptr2[i]=ptr[i];
	}
}




int kapsamaAlani(int* ptr, int* ptr2){//pop komutunu kullanarak kulelerin kapsama alanýný buldum
	kopyala(ptr,ptr2);
    int deneme=pop(ptr);
    while(deneme!=ptr[top]){
    	deneme=pop(ptr);
	}
	
	int firstpop=ptr[top];
	int secondpop=pop(ptr);
	
	int i=1;
	while(firstpop>=secondpop){//ilk pop edilen eleman yani top daki elemandan daha büyük bi deðer karþýsýna pop edilmediði sürece kapsama alanýný artýr
		i++;
		if(top==0)
		    break;
		secondpop=pop(ptr);	
	}
	kopyala(ptr2,ptr);//stacki pop edip boþaltýðýmýz için eski stacki geri kopyaladým
	return i;
	
}




void tekrarla(int* ptr,int* ptr2,int* kapsa,int topp){//burda da verilen stackteki tüm elemanlar için kapsama alaný fonksiyoununu çaðýr tabi sondan baþa doðru yine
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




void yazdir(int* ptr){//yazdirma iþlemi
	printf("\n-----------------------------\n");

	int i;
	for(i=0;i<boyut;i++){
		printf("%d\t",ptr[i]);
	}
}


