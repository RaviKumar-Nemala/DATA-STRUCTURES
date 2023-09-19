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

void preorder(node*root){
if(root== NULL){
     return ;
}
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}
node*create_balanced_bst(int a[],int start,int end){
     if(start>end){
          return NULL;
     }
     int mid=(start+end)/2; //here we need to find out the mid element of the array becaz the given array is sorted so left side of the mid array is belongs to the root->left part where as right side part is belongs to thte root->right part//
     node *root = new node(a[mid]);
     root->left= create_balanced_bst(a,start,mid-1);//recursively calling the left subpart
     root->right= create_balanced_bst(a,mid+1,end);//recursively calling the right subpart
     return root;
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
     int a[]={1,2,3,4,5};
 node*temp= create_balanced_bst(a,0,4);
 preorder(temp);
 cout<<"\n";
 inorder(temp);
}