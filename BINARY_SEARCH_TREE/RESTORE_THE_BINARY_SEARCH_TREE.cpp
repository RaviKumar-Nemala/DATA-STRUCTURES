#include<iostream>
using namespace std;
#include<climits>
struct node{
     int data;
     node*left;
     node*right;
     node(int dup_data){
          data=dup_data;
          left=NULL;
          right=NULL;
     }
};
typedef struct node node;
void calculate(node*root,node**first,node**mid,node**last,node**prev){
     if(root==NULL){
          return;
     }
     calculate(root->left,first,mid,last,prev);
     if(*prev&&root->data<(*prev)->data){
          if(*first==NULL){
               *first=*prev;
               *mid=root;
          }
          else{
               *last=*prev;
          }
     }
     *prev=root;
     calculate(root->right,first,mid,last,prev);
}
void swap(int *a,int *b ){
     int temp=*a;
     *a=*b;
     *b=temp;
}
void  restore(node*root){
     if(root==NULL){
          return ;
     }
     node*last=NULL;
     node*first=NULL;
     node*mid=NULL;
     node*prev=NULL;
     calculate(root,&first,&mid,&last,&prev);
     if(first&&prev){
          swap(&(first->data),&(prev->data));
     }
     else{
          swap(&(first->data),&(mid->data));
     }
}
void inorder(node*root){
     if(root==NULL){
          return ;
     }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
int main(){
     node*root= new node(5);
     root->left= new node(6);
     root->right= new node(2);
     inorder(root);
     restore(root);
     cout<<"AFTER THE RESTORING THE BINARY TREES";
     inorder(root);
}