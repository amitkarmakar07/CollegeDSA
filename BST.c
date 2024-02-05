#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *left,*right;
};
struct node*create_node(int d){
   struct node*newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=d;
   newnode->left=NULL;
   newnode->right=NULL;
   return newnode;
}
void insert(struct node*root, int key){
    struct node * temp;
    struct node * newnode=create_node(key);
    while(root!=NULL){
        temp=root;
        if(key==root->data) {
        printf("cant insert duplicate value");
         return;
         }
        else if(key>root->data) root=root->right;
        else root=root->left;
    }
   
    if(key>temp->data) temp->right=newnode;
    else temp->left=newnode;
}
struct node*inOrderPrecedessor(struct node*root){    // in order predecessors is the the right most of the the left sub tree.
    root=root->left;
    while(root->right !=NULL){
        root=root->right;
    }
    return root;
}
struct node*deletion(struct node*root , int val){
    struct node*iPre;
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL){ //leaf nodes
    free(root);
    return NULL;
    }
    if(val>root->data){
        root->right = deletion(root->right,val);  // call for the right sub tree
    }
    else if(val<root->data){
        root->left = deletion(root->left,val); //call for the left sub tree
    }
    else{
        iPre = inOrderPrecedessor(root);
        root->data=iPre->data;
        root->left = deletion(root->left,iPre->data);
    }
    return root;
}
void inOrder(struct node *root){  
   if(root!=NULL){
      inOrder(root->left);
      printf("%d ",root->data);
      inOrder(root->right);    
   }
}
int main(){
    struct node* root=create_node(20);   
   insert(root,30);
   insert(root,10);
   insert(root,25);
   insert(root,9);
   inOrder(root);
   root=deletion(root,25);
   inOrder(root);
   return 0;
 }
