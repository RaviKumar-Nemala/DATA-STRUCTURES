#include<iostream>
using namespace std;
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
void flatten(node*root){
     if(root==NULL||(root->left==NULL&&root->right==NULL)){
          return ;
     }
     if(root->left!=NULL){
     flatten(root->left);
     node*temp=root->right;
     root->right=root->left;
     root->left=NULL;
     node*t=root->right;
     while(t->right!=NULL){
          t=t->right;
     }
     t->right=temp;
}

flatten(root->right);

}

void preorder(node*root){
     if(root==NULL){
          return ;
     }
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
}
void inorder(node *root){
     if(root==NULL){
          return ;
     }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->right= new node(11);
     root->left->left=new node(22);
     root->right->right= new node(5);
     flatten(root);
     //preorder(root);
     inorder(root);
}


