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
node*add_node(node*root,int dup_data){
     root= new node(dup_data);
     return root;
     delete root; 
}
node*build_tree_with_preorder(int preorder[],int *pre_idx , int key,int min,int max ,int n){
     if(*pre_idx>n){
          return NULL;
     }
     node*root=NULL;
     if(preorder[*pre_idx]>min&&preorder[*pre_idx]<max){
          root= new node(key);
          *pre_idx=*pre_idx+1;
     if(*pre_idx<n){
          root->left=build_tree_with_preorder(preorder,pre_idx,preorder[*pre_idx],min,root->data,n);
     }
     if(*pre_idx<n){
          root->right=build_tree_with_preorder(preorder,pre_idx,preorder[*pre_idx],root->data,max,n);
     }
}
return root;
}
void pre_order(node*root){
     if(root==NULL) return ;
     cout<<root->data<<" ";
     pre_order(root->left);
     pre_order(root->right);
}
int main(){
     int preorder[]={1,5,4,3,2};
     int idx=0;
     node*root=build_tree_with_preorder(preorder,&idx,preorder[0],INT_MIN,INT_MAX,5);
    pre_order(root);
}