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

int height(node*root)
{
     if(root==NULL){
          return 0;
     }
     int lh=height(root->left);
     int rh=height(root->right);
     return max(lh,rh)+1;
}
bool is_balanced(node*root,int *height){
     if(root==NULL){
          return true;
     }
     int lh=0,rh=0;
     if(is_balanced(root->left,&lh)==false){
          return false;
     }
     if(is_balanced(root->right,&rh)==false){
          return false;
     }
     *height=max(lh,rh)+1;
     if(abs(lh-rh)<=1){
          return true;
     }
     else{
          return false;
     }
}
int main(){
      system("cls");
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->right->left=new node(7);
     root->right->right=new node(8);
     int height=0;
    if(is_balanced(root,&height)){
          cout<<"tree is balanced"<<" ";
     }
     else {
          cout<<"tree is not balanced"<<" ";
     }
}

