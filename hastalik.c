#include <stdio.h>
#include <stdlib.h>

int  deger_al(int);
void deger_ata(int [],int [],int );
void sirala(int [],int [],int );
void karsilastir(int [],int[],int );

int main ()
 {  int hasta;
 
    hasta=deger_al(hasta);
    
 	int* insan;//malloc ile dinamik bir dizi tanýmladim
 	insan=(int *)malloc(hasta*sizeof(int));
 	int* virus;
 	virus=(int *)malloc(hasta*sizeof(int));	
 	
 	deger_ata(insan,virus,hasta);
 	sirala(insan,virus,hasta);
 	karsilastir(insan,virus,hasta);
 	
 
 	return 0;
}

int deger_al(int a){//hasta sayisini kullanýcýdan aldým
 	printf("\n0 ile 10 arasinda hasta sayisini giriniz  ");
 	scanf("%d",&a); 
	
    if(a>10 || a<0){
    	printf("\n0 ile 10 arasinda  dedik ama degil mi !!!\n");
    	return deger_al(a);	
	}
 	return a;
 }

 
 void deger_ata(int dizi[],int diziiki[],int a){//her hastaya anti-x ve her virüse de virüs-x atamasý yaptým 
 	int i=0,j=0,deger;
 	for(i;i<a;i++){
 		printf("%d inci hastadiki anti-X sayisini giriniz  ",i);
 		scanf("%d",&deger);
 		dizi[i]=deger;
	 }
	printf("\n");
	for(j;j<a;j++){
 		printf("%d inci virusdeki virus-X sayisini giriniz  ",j);
 		scanf("%d",&deger);
 		diziiki[j]=deger;
	 }	
 	
 }
 
 
 
 void sirala(int dizi[],int diziiki[],int a){//bubble short siralama algoritmasý kullanarak sýraladým
 	
 	int i=0,j=1,kova;
 	for(i;i<a;i++){
 		j=1;
 	  for(j;j<a;j++){
 	  	if(dizi[j-1]>=dizi[j]){
 	  		kova=dizi[j];   dizi[j]=dizi[j-1];    dizi[j-1]=kova;
 	  		}
	   }	
	 }
	 i=0;j=1;
 	for(i;i<a;i++){
 		j=1;
 	  for(j;j<a;j++){
 	  	if(diziiki[j-1]>=diziiki[j]){//büyük olan indisi diðeri ile deðiþtirmek için doldur boþalt yaptým
 	  		kova=diziiki[j];diziiki[j]=diziiki[j-1];diziiki[j-1]=kova;
 	  		}
	   }	
	 }	 	
 }
 
 
 
 void karsilastir(int dizi[],int diziiki[],int a)//basit bir ayný indisleri karþýlaþtýrmak için if yapýsý
 {
 	int i=0,kurtulan=0;
 	for(i;i<a;i++){
 		if(dizi[i]>=diziiki[i]){
 			printf("\n%d inci kisi hayatta kaldi anti-X:%d > virus-X:%d \n",i,dizi[i],diziiki[i]);
 			kurtulan=kurtulan+1;
 			}	
	 }
 	 if (kurtulan!=0){
 		printf("\nNO! kurtulan kisi sayisi %d\n",kurtulan);
	 }
	 else{
	 	printf("\nYES! kimse kurtulamadi basiniz sagolsun :)");
	 }
 }
