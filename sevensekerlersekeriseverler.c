#include <stdio.h>
#include <stdlib.h>

int bag;//bagArray de ki toplam paket sayisi

void insert(int,int,int*);
void print(int,int*);
void change(int*);
int* getInput(int*);



int main(int argc, char** argv) {
    
    int* bagArray;//Paketlerimizin bulundugu dizi yani heap
    int time,temp=0;// time= cocugun eve donmesi icin gereken sure  temp = cocugun yedigi seker sayisi
    
    printf("Eve donmesi icin gereken sure? -K- :");
    scanf("%d",&time);
    
    bagArray=getInput(bagArray);
    
    
    int i=0;
    for(i;i<time;i++){//Cocuk eve gidene kadarki surede yedigi sekerler her seferinde yeniden duzenle
        temp += bagArray[1];
        change(bagArray);  
    }
    
    printf("==============================================\n");   
    printf("Paketlerin son hali ::: ");
    print(bag,bagArray);
    printf("==============================================\n");
    printf("Cocugun yedigi seker sayisi:%d",temp);
    

    
    return (EXIT_SUCCESS);
}



int* getInput(int* bagArray){//Paketlerdeki sekerlerin sayisini alip heapa koyan fonk
    printf("Toplam kac tane seker paketi var? -N- :");
    scanf("%d",&bag);
    
    bagArray=(int*)malloc(sizeof(int)*bag);
    
    int i=1,bagElement;
    for(i;i<=bag;i++){
        printf("%d paketteki seker sayisi: ",i);
        scanf("%d",&bagElement);
        insert(bagElement,i,bagArray);
    }
    
    printf("==============================================\n");
    printf("Heap sort hali ::: ");
    print(bag,bagArray);
    printf("==============================================\n");
    
    return bagArray;
    
}





void insert(int bagElement ,int number ,int* bagArray){//Heap sort algoritmasi 
    int temp,check;
    
    if(number > 1){
        check = number;
        
        while(check > 1){
            
            if(bagElement > bagArray[check / 2]){//girilen degerin kendi kokunden buyuk olma durumunu kontrol eder
                temp = bagArray[check / 2];
                bagArray[check / 2] = bagElement;
                bagArray[check] = temp;  
                //print(number,bagArray);
            }
            
            
            else if(check == number){//girilen deger esit degilse ve while 2.kez dondugunde bir daha ekleme yapmamas icin
                bagArray[check] = bagElement;
                //print(number,bagArray);
            }
              
            check /= 2;  
        }  
    }
    
    
    else{//sadece ilk elemanin eklendigi durum
        bagArray[number] = bagElement;
        //print(number,bagArray);
    }  
}





void change(int* bagArray){
    int i=1;
    bagArray[i] = bagArray[i]/2;//paket yere dustugunde eleman sayisi yariya inmesi
    
    for(i;i <= bag;i++)//heapi yeniden 0 dan duzenle
        insert(bagArray[i],i,bagArray);
    
    
    //print(bag,bagArray);
    
}





void print(int bag,int* bagArray){//ekrana basma
    int i=1;
    
    for(i;i<=bag;i++)
        printf("%d ",bagArray[i]);
    
    printf("\n");
}



/*
         * Fonksiyonun asil can alici isini insert yapmaktadir 
         * Her while dongusunden sonra kontrolu(check) 2 ye bolerek heap agacindaki katmanlar arasindaki kokler arasinda gecis yapicaz
         * Mesela bizim agacimiz  6    seklinde olsun  burda ekleme yaparken  ekleyecegimizi farz edelim fonk while icinde girilen paketteki eleman sayisini(bagElement)
         *                       3 2    soru isareti olan yere koymasi gerekir fakat 5 kendi koku olan 3 den buyuk bu yuzden while icindeki if kosulu saglanir ve
         *                      2 ?    soru isareti yani 5 ile 3 yer degisir ve kontrolu 2 ye bolup yeniden bi kontrol yapariz 5 yeni koku olan 6 dan da buyuk mu
         *                             buyukse yine yerleri degisir degilse yeni heapimiz 6  seklinde olur
         *                                                                               5 2
         *                                                                              2 3  
         */ 