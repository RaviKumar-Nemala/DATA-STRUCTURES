#include<iostream>
using namespace std;
#include<algorithm>
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

int path_sum_finder(node*root, int &ans){
     if(root==NULL){
          return 0;
     }
     int left=path_sum_finder(root->left,ans);
     int right=path_sum_finder(root->right,ans);
int  curret_node_totalpath_sum=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
     int node_val=max(root->data,max(root->data+left,root->data+right));
     ans=max(ans,curret_node_totalpath_sum);
     return node_val;
}
int find_max_path_sum(node*root){
     if(root==NULL){
          return 0;
     }
     int ans;
     path_sum_finder(root,ans);
     return ans;
}
int main(){
     int ans=0;
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     cout<<find_max_path_sum(root);
     /*   1
        /   \
        2    3
       /  \      
      4    5    
      */

}