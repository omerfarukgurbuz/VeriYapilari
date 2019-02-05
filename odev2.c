#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int* girdi;
int element;
int sonuc=0;

struct n{
    int data;
    struct n *left,*right;
};
typedef struct n node;




void getInput();
void bubbleSort(int* );
node* setTree(node*,int,int,char);







int main(){
    
    getInput();
    bubbleSort(girdi);//degisim sayisini bulmak icin
    printf("%d \n",sonuc);
    
    int i=0;
    for(i;i<element;i++)
        printf("%d ",girdi[i]);
    
    return 0;
}






void getInput(){//girdi almak icin
    printf("Kac elemanli bir agac olacagini giriniz\n");
    
    scanf("%d",&element);
    
    girdi=(int*)malloc(sizeof(int)*element);
    
    
    printf("Inorder olacak sekilde elemanlari giriniz\n");
    int i=0;
    for(i;i<element;i++){
        printf("%d inci elemani giriniz: \n",i);
        int a;
        scanf("%d",&a);
        girdi[i]=a;
    }  
}





    
 //Kabarcık sıralama fonksiyonumuz, parametre olarak dizimizi gönderiyoruz.
void bubbleSort(int* girdi)
{
    int i, j,tmp;
 
    //iterasyonların olduğu dış döngü
    for(i = 1; i < element; i++)
    {
        //Her iterasyonda elemanları karşılaştıracak olan iç döngü
        for( j = 0; j < element - 1; j++)
        {
            //iki eleman arasında karşılaştırma yapıyor eğer soldaki (i) sağdaki sayıdan (i+1)'den büyükse swap yapılacak'
            if(girdi[j] > girdi[j+1]){
                tmp=girdi[j];
                girdi[j]=girdi[j+1];
                girdi[j+1]=tmp;
                sonuc++;
            }
       }
    }
}





/*
 hocam ben simdi bu usteki kısımda sonucu bulabiliyorum fakat agaca atmadan yapiyo kod bunu agaca atma 
 kismini asagida iki hatta uc sekilde yaptik tabi bu agacdan kastim tamagac yoksa diger turlu kolay oluyo her turlu 
 konusmustuk bunu// simdi alttaki ilk kod bunu cok iyi yapiyo fakat surekli kullanicidan yon gostermesini istedigi icin
 kullanmadim onu ama bu isi iyi yapiyo kesinlikle//   diger 2. kod ise ilk 9 elemana kadar iyi calisiyo 9.dan sonra rastgele sag
 veya solda biyere ekleme yapiyo   
 */




node* setTree(node* tree,int sayi,int girilecek,char yon){//Manuel olarak saga sola ekleme yapan fonk
	if(yon=='n'){//root un NULL olma durumu
		node* tmp=(node*)malloc(sizeof(node));
		tmp->data=sayi;
		tmp->left=NULL;
		tmp->right=NULL;
		return tmp;
	}
	
	
	if(yon=='l'&& tree->data==sayi){//left in NULL olma durumu
		node* tmp=(node*)malloc(sizeof(node));
		tmp->data=girilecek;
		tmp->left=NULL;
		tmp->right=NULL;
		tree->left=tmp;
		return tree;
		
	}
	
	if(yon=='r'&& tree->data==sayi){//right in NULL olma durumu
		node* tmp=(node*)malloc(sizeof(node));
		tmp->data=girilecek;
		tmp->left=NULL;
		tmp->right=NULL;
		tree->right=tmp;
		return tree;
		
	}
	
	printf("%d vertexi %d vertexinin solunda mi yoksa sagin da mi sol ise 1 sag ise 2 giriniz \n",sayi,tree->data);
	int k;
	scanf("%d",&k);
	
	if(k==1){
            tree->left= setTree(tree->left,sayi,girilecek,yon);
            return tree;
                        
	}
		
		
	if(k==2){
	    tree->right=setTree(tree->right,sayi,girilecek,yon); 
            return tree ;
		
	}	
}


/*
struct node* insert(struct node* node, int key,int a,int dizi) 
{ 
    if (node == NULL)
	{
	  	 dz[dizi]=a; 
	  return newNode(key); 
	}
	if(node->left==NULL){
		 node->left  = insert(node->left, key,a,dizi); 	
	}	
	else{
		a++;
		if(node->right==NULL){
			node->right = insert(node->right, key,a,dizi);  
		}
		else{
			a++;
			if(a%2==1){
				node->left  = insert(node->left, key,a,dizi); 
			}
			else{
				node->right = insert(node->right, key,a,dizi);
			}
		}
	}
			
    return node; 
} 

*/