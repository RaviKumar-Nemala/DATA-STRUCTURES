#include<iostream>
using namespace std;
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

void print_target_subtree(node*root,int k){
     if(root==NULL){
          return ;
     }
     if(k==0){
          cout<<root->data<<" ";
          return;
     }
     print_target_subtree(root->left,k-1);
     print_target_subtree(root->right,k-1);
}
int distance_at_kth_level(node*root,node*target,int k){
     if(root==NULL){
          return -1;
     }
     if(root == target){
          print_target_subtree(root,k);
          return 0;
     }
     int dl=distance_at_kth_level(root->left,target,k);
     if(dl!=-1){
          if(dl+1==k){
               cout<<root->data<<" ";
          }
          else{
               distance_at_kth_level(root->right,target,k-dl-2);
           }
          return dl+1;
     }
     int dr=distance_at_kth_level(root->right,target,k);
     if(dr!=-1){
          if(dr+1==k){
               cout<<root->data<<" ";
          }
          else{
               distance_at_kth_level(root->left,target,k-dl-2);
          }
          return dr+1;
     }
     return -1;
}
int main(){
      //system("cls");
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->left->left->left= new node(55);
      root->right->left->left= new node(55);
     cout << distance_at_kth_level(root,root->left,1);

       /*   1
          /    \
         2      3
        /  \     
        4   5   
        */      
}