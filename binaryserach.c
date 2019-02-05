#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key,int a) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    /*if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);  
    
    */
    if (node ->left == NULL){
       node->left  = insert(node->left, key);  
    }
    else{
        a++;
    }
  
    if (node ->right == NULL){
       node->right  = insert(node->right, key);  
    }
    else{
        a++;
    }
    /* return the (unchanged) node pointer */
    return node; 
} 
   
// Driver Program to test above functions 
int main() 
{ 
    int vertex;
    scanf("%d",&vertex);
    struct node *root = NULL; 
    
    int i=0;
    while(vertex!=0){
    root = insert(root, 50,i); 
    vertex--;
    }
   
    // print inoder traversal of the BST 
    inorder(root); 
   
    return 0; 
} 