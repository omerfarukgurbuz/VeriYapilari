
#include<stdio.h> 
#include<stdlib.h> 
dz[500];


struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
void inorder(struct node*,int ); 
struct node* insert(struct node*, int,int,int); 
struct node *newNode(int ); 





int main() 
{ 

    printf("eleman sayisini giriniz\n");
    int e,deger,k;
    
	scanf("%d",&e);
	printf("k degerini giriniz\n");
	scanf("%d",&k);
	int i=2,dizi =0, d=e; 
    struct node *root = NULL;
    while(e!=0){
    	printf("\n %d. eleman degeri-->  ",dizi+1);
    	scanf("%d",&deger);
    	
    	if(e==d){
    		  root = insert(root, deger,i,dizi); 
		}
		else{
			insert(root, deger,i,dizi);
		}
		dizi++;
		i=dz[dizi-1];
		e--;
	}
	
	printf("\n   toplami k dan buyk 3 lu ler ---> toplami");
    inorder(root,k); 

    return 0; 
}  



  
// Bu fonksiyonda normal LNR ekrana basan kodu modifie edip kullandik once en sola kadar gidiyo sonra datasini okuyup 4 tane durumda ife sokuyo
void inorder(struct node *root,int y) 
{ 
int toplam=0;
    if (root != NULL) 
    { 
        inorder(root->left,y); 
        if(root!=NULL && root->left !=NULL && root->left->left !=NULL){
        	toplam=root->key+root->left->key+root->left->left->key;
        	if(toplam>y)
        		printf("\n%d : %d : %d =%d",root->key,root->left->key,root->left->left->key,toplam);
        	int toplam=0;
		}
		if(root!=NULL && root->left !=NULL && root->left->right !=NULL){
        	toplam=root->key+root->left->key+root->left->right->key;
        	if(toplam>y)
        		printf("\n%d : %d : %d =%d",root->key,root->left->key,root->left->right->key,toplam);
        	int toplam=0;
		}
		if(root!=NULL && root->right !=NULL && root->right->left !=NULL){
        	toplam=root->key+root->right->key+root->right->left->key;
        	if(toplam>y)
        		printf("\n%d : %d : %d =%d",root->key,root->right->key,root->right->left->key,toplam);
        	int toplam=0;
		}
		if(root!=NULL && root->right !=NULL && root->right->right !=NULL){
        	toplam=root->key+root->right->key+root->right->right->key;
        	if(toplam>y)
        		printf("\n%d : %d : %d =%d",root->key,root->right->key,root->right->right->key,toplam);
			int toplam=0;
		}
        inorder(root->right,y); 
    } 
} 




//burda 2 ile yudesini alarak yon bulmaya calistik ama belli bi yerden sonra bu dogru yere eklemiyo
 
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




// Yeni dugum ekleme durumu
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 


