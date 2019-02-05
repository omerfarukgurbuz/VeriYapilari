#include <stdio.h>
#include <stdlib.h>
int size,fonk;

int* getInput(int* );
void insert(int,int,int*);
void print(int,int*);
int divide(int*);
void change(int*,int);
void average(int*,int);




int main(int argc, char** argv) {
    int* array;
    int i;
    array=getInput(array);
    
    for(i=0; i<fonk; i++){
        change(array,size);
    }
    printf("Bolume gonderdikten Sonra Heap Sort ::: ");
    print(size,array);
    printf("==========================================\n");
    average(array,size);
    printf("==========================================\n");

    
    
    return (EXIT_SUCCESS);
}







int* getInput(int* array){//Heaptaki elemanlari alan fonk
    printf("Kaç Sayi Girilecek -N- :");
    scanf("%d",&size);
    printf("Kac Kez 3 e Bolunecek: -K- :");
    scanf("%d",&fonk);
    array=(int*)malloc(sizeof(int)*size);
    
    int i=1,element;
    for(i;i<=size;i++){
        printf("%d inci sayiyi giriniz: ",i);
        scanf("%d",&element);
        insert(element,i,array);
    }
    
    printf("==============================================\n");
    printf("Heap sort hali ::: ");
    print(size,array);
    printf("==============================================\n");
    
    return array;
    
}








void insert(int element ,int number ,int* array){//Heap sort algoritmasi 
    int temp,check;
    
    if(number > 1){
        check = number;
        
        while(check > 1){
            
            if(element > array[check / 2]){//girilen degerin kendi kokunden buyuk olma durumunu kontrol eder
                temp = array[check / 2];
                array[check / 2] = element;
                array[check] = temp;  
                //print(number,bagArray);
            }
            
            
            else if(check == number){//girilen deger esit degilse ve while 2.kez dondugunde bir daha ekleme yapmamas icin
                array[check] = element;
                //print(number,bagArray);
            }
              
            check /= 2;  
        }  
    }
    
    
    else{//sadece ilk elemanin eklendigi durum
        array[number] =element;
        //print(number,bagArray);
    }  
}








void print(int size,int* array){//ekrana basma
    int i=1;
    
    for(i;i<=size;i++)
        printf("%d ",array[i]);
    
    printf("\n");
}








int divide(int* array){     // Girilen heapin rootyunu 3 e boler
    double temp = 0;
    
    if((array[1] % 3) != 0){
    temp = array[1]/3 + 1;
    }
    else{
        temp = array[1]/3;
    }
    return temp;
}







void change(int* array,int size){           
 int i=1;                             
    array[i] = divide(array);
    for(i=1; i<=size; i++){
        insert(array[i],i,array);
    }
}    





void average(int* array,int size){//ortalama bulan fonk
    int i,medium=0;
    for(i=1; i<=size; i++){
        medium += array[i];
    }
    printf("Minimum Ortalama: %d'dir\n",medium / size);
}
