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
node * LCA(node*root,int n1,int n2){
     if(root==NULL){
          return NULL;
     }
     if(root->data==n1||root->data==n2){
          return root;
     }
    node*left_check=LCA(root->left,n1,n2);
    node*right_check=LCA(root->right,n1,n2);
    if(left_check&&right_check){
         return root;
    }
    if(left_check==NULL&& right_check==NULL){
         return NULL;
    }
    if(left_check==NULL){
         return root->right ; //recursively call avutundi last nundifirst ki vastundi so root -> null aithe left side chedakarledhu only right side chuste chalu
    }
    else{
         return root->left;
    }
}
int find_distance(node*root,int k,int level){
     if(root==NULL){
          return -1;
     }
     if(root->data==k){
          return level;
     }
     int left_distance=find_distance(root->left,k,level+1);
     if(left_distance!=-1){
          return left_distance;
     }
     return find_distance(root->right,k,level+1);
}
int shortest_distance(node*root,int n1,int n2){
     node*temp=LCA(root,n1,n2);
     int d1=find_distance(temp,n1,0);
     int d2= find_distance(temp,n2,0);
     return (d1+d2);
}
int main(){
     system("cls");
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     cout<<shortest_distance(root,4,3);
           /*1
          /    \
         2      3
        /  \     
        4   5         
        */
}
