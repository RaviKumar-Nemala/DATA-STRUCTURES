#include<iostream>
using namespace std;
struct node{
int  data;
     node*left;
     node*right;
     node(int  dup_data){
          data=dup_data;
          left=NULL;
          right=NULL;
     }
};
node*add_node(int data){
     node*temp=new node(data);
     return temp;
}
int height(node *root){
     if(root==NULL)
     return 0;
     int lh=height(root->left);
     int rh=height(root->right);
     return max(lh,rh)+1;
}
bool is_balanced(node *root){
     if(root==NULL)
     return true;

     if(is_balanced(root->left)==false)
     return false;
     if(is_balanced(root->right)==false)
     return false;

     int lh=height(root->left);
     int rh=height(root->right);
     if(abs(lh-rh)<=1)
     return true;
     else
     return false;
}
int main(){
node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     if(is_balanced(root)){
          cout<<"tree is balanced"<<" ";
     }
     else {
          cout<<"tree is not balanced"<<" ";
     }
}