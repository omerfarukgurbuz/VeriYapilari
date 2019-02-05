#include <stdio.h>
#include <stdlib.h>
int* dizi,boyut,girilen;


void diziAl();
void quickSort(int *,int, int);
void tara();
void yazdir();




int main(){
    diziAl();
    yazdir();
    
    quickSort(dizi,0,boyut-1);
    yazdir();
    tara();
    return 0;
}




void diziAl(){//dizinin eleman say�s�n�,aranacak x de�erini ve elemanlar�n� al�r
    printf("Dizinin boyutunu girin: ");
	scanf("%d",&boyut);
    dizi=(int *)malloc(sizeof(int)*boyut);
    
	int i;
	for(i=0;i<boyut;i++){
        printf(" %d inci elemani girin :",i+1);
		scanf("%d",&dizi[i]);
    }
    printf("\nMinimize edilip aranacak X degerini giriniz\n");
    scanf("%d",&girilen);
	
}




void quickSort(int *dizi,int ilk,int son){//qu�ck sort ile s�ralama yapar
    int indis1,indis2,pivot,tmp; 
    pivot=ilk; // Pivot ilk eleman se�ilir
   

    if(son>ilk){
        pivot=ilk;
        indis1=ilk;
        indis2=son;
        while(indis1<indis2){
            while (indis2>indis1 &&dizi[indis1]<=dizi[pivot] && indis1<indis2){ // dizinin ba��ndan gidilerek pivottan b�y�k ilk elemanda dur
                indis1++;
            }
            while (dizi[indis2]>=dizi[pivot] && indis2>=indis1 && indis2>=indis2){ // dizinin sonundan ba�layarak pivottan k���k ilk elemanda dur
                indis2--;
            }
            if (indis2>indis1){ // bu buldu�umuz indislerin yerini de�i�tiriyoruz
                tmp=dizi[indis1];
                dizi[indis1]=dizi[indis2];
                dizi[indis2]=tmp;
            }
        }
        
        tmp=dizi[indis2];
        dizi[indis2]=dizi[pivot];
        dizi[pivot]=tmp;//yeniden pivot se�tim
        
        quickSort(dizi,ilk,indis2-1);//di�er elemanlar yeniden quick sort
        quickSort(dizi,indis2+1,son);
    }
}




void tara(){//aran�lan x  minimize de�eri bulmak i�in 
	int i;
	while(1==1){
	    girilen++;//burda hen�z ba�tayken girilen 1 art�r�l�r
	    int bayrak=1;
	    for(i=0;i<boyut;i++){
	    	if(dizi[i]==girilen){
			    bayrak=0;
			    break;
			}
		}
		if(bayrak==1)//bayrak hala 1 ise d�ng� k�r�l�r ve girilen de�i�keni bas�l�r
		    break;   
    }
    printf("\n\nDizide aranaip minimize edilip bulunan sayi: %d\n",girilen);
}




void yazdir(){
	printf("\n\n--------------------------------\n");
	int i;
    for(i=0;i<boyut;i++){
        printf("%d ",dizi[i]);
    }	
}
