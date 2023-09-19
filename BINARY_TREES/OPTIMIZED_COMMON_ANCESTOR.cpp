#include<iostream>
using namespace std;
#include<vector>
struct node{
     int data;
     node*left;
     node*right;
     node(int dup_data){
          data = dup_data;
          left=NULL;
          right=NULL;
     }
};
typedef struct node node;
node* ANCESTOR(node*root,int n1,int n2){
     if(root==NULL)
     {
          return NULL;
     }
     if(root->data==n1||root->data==n2) {
          return root;
     }
     node*left_tree=ANCESTOR(root->left,n1,n2);
     node*right_tree=ANCESTOR(root->right,n1,n2);
     if( left_tree&&right_tree )
     {
          return root;
     }
     if(left_tree==NULL){
          return right_tree;
     }
     else{
          return left_tree;
     }
}
int main(){
node *root=new node(1);
root->left=new node(2);
root->right=new node(5);
root->right->right=new node(9);
root->left->left=new node(4);
root->left->right=new node(3);
root->right->left=new node(6);
node*test=ANCESTOR(root,2,99);
 if(test!=NULL)
 cout<<test->data<<endl;
 else{
      cout<<"test has failed"<< " ";
 }
}