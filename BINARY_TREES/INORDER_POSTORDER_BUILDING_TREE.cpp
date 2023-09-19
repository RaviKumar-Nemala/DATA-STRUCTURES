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
node*build_tree(int postorder[],int inorder[],int start,int end){

static int idx=4;
if(start>end){
     return NULL;
}

int current=postorder[idx]; //in post order traversal last node is the root node so last node has to be  build first

idx--;

node* n=new node(current);

if(start==end) return n;
int pos=search(postorder,inorder,start,end,current);
n->right=build_tree(postorder,inorder,pos+1,end); //post order lo right side of the tree mundu build cheyyali enduku ante post order lo mundu left next right last lo root vastundi already root ayipoyindi kabatii tarvatha left node vastundi dani tarvatha right node vastundi
n->left=build_tree(postorder,inorder,start,pos-1);

}
void inorder_print(node*root){
     if(root==NULL) return ;
     inorder_print(root->left);
     cout<<root->data<<" ";
     inorder_print(root->right);
}
void preorder_print(node*root){
     if(root==NULL) return ;
     cout<<root->data<<" ";
     preorder_print(root->left);
     preorder_print(root->right);
}
int main(){
     int postorder[]={4,2,5,3,1};
     int inorder[]={4,2,1,5,3};
     node *root=build_tree(postorder,inorder,0,4);
    // inorder_print(root);
    preorder_print(root);
}

