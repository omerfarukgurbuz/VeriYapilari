#include <stdio.h>
#include <stdlib.h>
/* Gerekli degerleri aldiktan sonra,ilk olarak heap sort ile siraladim. en ustte en buyuk eleman olacak sekilde...
sonra can'a en ustteki seker paketini yedirdikten sonra o paketi 2'ye bolup, tekrar heap sort yaparak o paketin yerini guncelledim.
Can her seferinde en usteki paketi yiyerek en fazla sekeri yemis olacaktir.*/

void sekerleriAl(int,int *,int);
void yerlestir(int,int *,int,int);
void yazdir(int,int *);
void degis(int,int *,int);

int main()
{
    int paketSayisi;
    printf("Seker Paketi(N): ");
    scanf("%d",&paketSayisi);
    printf("--------------------------------------------\n");
    int dizi[paketSayisi],dakika,sekerSayisi=0,i,yedigiSeker=0;
    printf("Eve Donmek Icin Kac Dakikasi Var(K): ");
    scanf("%d",&dakika);
    printf("--------------------------------------------\n");
    sekerleriAl(paketSayisi,dizi,sekerSayisi);
    printf("--------------------------------------------\n");
    printf("HEAP SORT==> ");
    yazdir(paketSayisi,dizi);

    for(i=0; i<dakika; i++){
            yedigiSeker += dizi[1];
        degis(paketSayisi,dizi,sekerSayisi);
    }
    printf("--------------------------------------------\n");
    printf("Yedigi Seker Sayisi: %d 'dir.\n",yedigiSeker);
    printf("--------------------------------------------");

    return 0;
}

void sekerleriAl(int paketSayisi,int dizi[],int sekerSayisi){ // sekerleri alip heap sortta yerini belirlemek icin yerlestir fonksiyonuna gonderiyor

    int i;

    for(i=1; i<=paketSayisi; i++){
        printf("%d. Paketteki Seker Sayisi: ",i);
        scanf("%d",&sekerSayisi);
        yerlestir(paketSayisi,dizi,sekerSayisi,i);
    }
}

void yerlestir(int paketSayisi,int dizi[],int sekerSayisi,int i){  // heap sor burda yapiliyor.
    int gecici,j;

    if(i>1){
            j=i;
    while(j>1){
            if(sekerSayisi > dizi[j/2]){   // eger eklenecek eleman kendi atasindan buyukse onla yer degistirir.
                gecici=dizi[j/2];
                dizi[j/2]=sekerSayisi;
                dizi[j]=gecici; 
                yazdir(i,dizi);
            }
            else if(j==i){                // degilse en sona eklenir.
                dizi[j]=sekerSayisi;
                yazdir(i,dizi);
            }
           j=j/2;
        }
    }
        else{                               // bunun amaci ilk elemani almak.
            dizi[i]=sekerSayisi;
            yazdir(i,dizi);
        }
}

void yazdir(int paketSayisi,int dizi[]){
    int i;

    for(i=1; i<=paketSayisi; i++){
        printf("%d ",dizi[i]);
    }
    printf("\n");
}

void degis(int paketSayisi,int dizi[],int sekerSayisi){ // can en buyuk yani kokteki paketi yiyince paketi yariya dusurup tekrar yerlestir fonksiyonuna gonderdim.

    int i=1;
    dizi[i]=dizi[i]/2;
    for(i=1; i<=paketSayisi; i++){
        yerlestir(paketSayisi,dizi,dizi[i],i);
    }
    yazdir(paketSayisi,dizi);

}
