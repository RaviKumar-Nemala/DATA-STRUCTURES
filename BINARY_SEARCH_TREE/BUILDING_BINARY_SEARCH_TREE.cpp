#include<iostream>
#include<algorithm>
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
void inorder(node*root){
     if(root==NULL){
          return ;
     }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
bool binary_search(node*root,int key){
     if(root==NULL){
          return false;
     }
     if(root->data==key){
          return true;
     }
     if(key>root->data){
          return  binary_search(root->right,key);
     }
     return binary_search(root->left,key);
}
int main(){
     node*root=NULL;
     int i;
     for( i=0;i<4;i++){
          root= build_tree(root,i+1);
     }
     inorder(root);
     
     if(binary_search(root,i+9)){
          cout<<"\nMATCH IS FOUND"<<" ";
          cout<<i;
     }
     else{
          cout<<"\nNO MATCHES ARE  FOUND";
     }
}