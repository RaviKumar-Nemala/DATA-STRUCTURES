#include<iostream>
#include<queue>
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

int sum_of_all_nodes(node*root){
     if(root==NULL) return 0;
     return sum_of_all_nodes(root->left)+sum_of_all_nodes(root->right)+root->data;
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     cout<<sum_of_all_nodes(root)<<" ";
}