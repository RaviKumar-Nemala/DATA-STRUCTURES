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
node*add_node(node*root,int dup_data){
     root= new node(dup_data);
     return root;
     delete root; 
}
node*build_tree(node*root,int data){
     if(root==NULL){
          node*temp=add_node(root,data);
          root=temp;
          return root;
     }
     if(data>=root->data){
          root->right=build_tree(root->right,data);
     }
     else if(data<root->data){
          root->left=build_tree(root->left,data);
     }
}
int find_max_left(node* root){
     if(root==NULL){
          return -1;
     }
     while(root->right!=NULL){
          root=root->right;
     }
     return root->data;
}
node*Delete_node(node*root,int key){
     if(root==NULL){
          return NULL;
     }
     if(key>root->data){
         root->right=Delete_node(root->right,key);
     }
     else if(key<root->data){
          root->left=Delete_node(root->left,key);
     }
     else{
          if(root->left==NULL&&root->right==NULL){
               free(root);
               return NULL;
          }
          else if(root->left==NULL){
               node*temp=root->right;
               free(root);
               return temp;
          }
          else if(root->right==NULL){
               node*temp= root->left;
               free(root);
               return temp;
          }
          else{
               int max_left=find_max_left(root->left);
               root->data=max_left;
               root->left=Delete_node(root->left,max_left);
          }
          return root;
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
     int i;
     node*root=NULL;
     for(i=0;i<100;i++){
          root=build_tree(root,i+1);
     }
     inorder(root);
     cout<<"PRINING THE NODES AFTER DELETION:"<<endl;
     for(i=0;i<100;i++)
     root=Delete_node(root,i+1);
     inorder(root);
}