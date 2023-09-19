#include<iostream>
using namespace std;
#include<vector>
vector<int>ans;
struct node{
     int data;
     node*left;
     node*right;
     node(int dup_data)
     {
          data=dup_data;
          left=NULL;
          right=NULL;
     }
};
bool sum_check(int sum,node*root){
     if(root==NULL)return true;;
     if(root->left==NULL and root->right==NULL){
          if(root->data==sum){
          ans.push_back(root->data);
          return true;}
          else
          return false;
     }
     if(sum_check(sum-(root->data),root->left)||sum_check(sum-(root->data),root->right)){
     ans.push_back(root->data);
     return true;
     }
     else
     return false;
}
int main(){
     node *root=new node(1);
     root->left=new node(2);
     root->right= new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     sum_check(8,root);
     for(auto it:ans)
     cout<<it<<" ";
}