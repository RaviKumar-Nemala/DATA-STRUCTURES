#include<iostream>
using namespace std;
struct node{
     int data;
     struct node*left;
     struct node*right;
     node(int dup_data){
          data=dup_data;
          left=NULL;
          right=NULL;
     }
};
void inorder(node *root){
     if(root==NULL){
          return ;
     }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
void preorder(node *root){
     if(root==NULL){
          return ;
     }
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
}
void postorder(node *root){
     if(root==NULL){
          return ;
     }
     postorder(root->left);
     postorder(root->right);
     cout<<root->data<<" ";
}
int main(){
     struct node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->right->left=new node(6);
     root->right->right=new node(7);
     cout<<"\nCALLING THE INORDER TRAVERSAL"<<endl;
     inorder(root);
     cout<<"\nCALLING THE PRE ORDER TRAVERSAL"<<endl;
     preorder(root);
     cout<<"\nCALLING THE POST ORDER TRAVERSAL"<<endl;
     postorder(root);
}