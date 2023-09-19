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
int cal_height(node*root){
     if(root==NULL){
          return 0;
     }
     int left_height=cal_height(root->left);
     int right_height=cal_height(root->right);
     return max(left_height, right_height)+1;
}
int main(){
     system("cls");
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->left->left->left=new node(6);
     root->left->left->left->left=new node(7);
     root->left->left->left->left->left=new node(8);
     cout<<cal_height(root)<<" ";
     /*      1
          /    \
         2      3
        /        \
        4         5   in this case the height becomes 
       / 
       6
      /
     7
    /
   8
*/
}

