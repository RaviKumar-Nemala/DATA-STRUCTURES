#include<iostream>
using namespace std;
struct node {
     int data;
     node*left;
     node*right;
     node(int dup_data) {
          data=dup_data;
          left=NULL;
          right=NULL;
     }
};
typedef node node;
void sum_replacement(node*root){ 
     
     if(root==NULL){
          return;
     }
     sum_replacement(root->left);  //if keep on going until the root is empty
     sum_replacement(root->right);//here we are traversing through the right part
     if(root->left!=NULL){//this condition is useful for not adding the leafnodes values which are presented at left side//
          root->data+=root->left->data;//here we are adding the left side itself value//
     }
     if(root->right!=NULL){//this condition is useful for not adding the leafnodes values which are presented at right side//
          root->data+=root->right->data;//we are adding the right side and itself value//
     }
     
}
void preorder(node*root){
     if(root==NULL){
          return;
     }
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     sum_replacement(root);
     preorder(root);

      /*     1    
          /    \     ->expected output is      15
                                              /   \
         2      3                             11   3
        /  \                                  /  \      
        4   5                                4    5    
*/ //add the leaf nodes of each parent node included with parent node data then include that value into the same parent node//
//for example for parent node 2 add the leaf nodes ex 4+5 along with itself i.e 2 total is equal to 11 put that value into the same node//
//for leaf nodes dont add the anything///
}