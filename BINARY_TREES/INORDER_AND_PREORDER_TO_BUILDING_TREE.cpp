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
int search(int preorder[],int inorder[],int start,int end,int current){
     for(int i=start;i<=end;i++){
          if(inorder[i]==current){
               return i;
          }
     }
     return -1;
}
void inorder_print(node*root){
     if(root==NULL) return ;
     inorder_print(root->left);
     cout<<root->data<<" ";
     inorder_print(root->right);
}
node*build_tree(int preorder[],int inorder[],int start,int end){

static int idx=0;
if(start>end){
     return NULL;
}
int current=preorder[idx];
idx++;
node* n=new node(current);
if(start==end) return n;
int pos=search(preorder,inorder,start,end,current);
n->left=build_tree(preorder,inorder,start,pos-1);
n->right=build_tree(preorder,inorder,pos+1,end);
}
int main(){
     int preorder[]={1,2,4,3,5};
     int inorder[]={4,2,1,5,3};
     node*root=build_tree(preorder,inorder,0,4);
      inorder_print(root);
}