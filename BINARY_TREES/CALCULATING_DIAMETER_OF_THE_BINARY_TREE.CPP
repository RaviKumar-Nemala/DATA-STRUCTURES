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

int height(node*root){
     if(root==NULL)return 0;
     int left=height(root->left);
     int right=height(root->right);
     return max(left,right)+1;
}
int diameter(node*root)
{
     if(root==NULL)return 0;
     int left=height(root->left);
     int right=height(root->right);
     int current=left+right+1;  // if the diameter is passing through the root node  then the diameter would be the left_node + right_node +1 

     int left_dia=diameter(root->left);
     //if the diameter is passing through the any of the node on the left side then calcute diameter on the left side 
     int right_dia=diameter(root->right);
     //if the diameter is passing through the any of the node on the right side then calcute diameter on the right side 

     return max(current,max(left_dia,right_dia));
}
int main(){
     system("cls");
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->right->right=new node(6);
     root->right->left=new node(7);
     root->right->right->right=new node(8);
     root->left->left->left=new node(12);
     root->left->left->left->left=new node(13);
     root->left->left->left->left->left=new node(14);
     root->left->right->right=new node(77);
     root->left->right->right->right=new node(88);
     root->left->right->right->right->right=new node(99);
     root->left->right->right->right->right->right=new node(100);



     cout<<diameter(root)<<" ";
     /*  1 
      2     3
     4  5   7   6
    8   77        7
   9      88
          99
            100
  10   */
}
