#include<iostream>
using namespace std;
#include<climits>

struct node{
     int data;
     node*left;
     node*right;
     node(int dup_data){
          data = dup_data;
          left=NULL;
          right= NULL;
     }
};
struct info_of_node{
     int size;
     int min_size;
     int max_size;
     bool is_bst;
     int ans;//(largest bst size);
};

typedef info_of_node info;

info large_bst(node*root)
{
     if(root==NULL){
          return {0,INT_MAX,INT_MIN,true,0};
     }
     if(root->left==NULL&&root->right==NULL){
          return {1,root->data,root->data,true,1};
     }
     info left=large_bst(root->left);
     info right=large_bst(root->right);
     info current;
     current.size=1+left.size+right.size;
     if(left.is_bst&&right.is_bst&&left.max_size<root->data&&right.min_size>root->data){
          current.min_size=min(left.min_size,min(right.min_size,root->data));
          current.max_size= max(right.max_size,max(left.max_size,root->data));
          current.is_bst=true;
          current.ans=current.size;
          return current;
     }
     else{
     current.ans=max(left.ans,right.ans);
     current.is_bst=false;
     return current;
}
}


int main(){
     info obj;
     node*root= new node(1);
     root->left= new node(2);
     root->right = new node(30);
     root->left->left = new node(1);
     root->left->right= new node(3);
     cout<<large_bst(root).ans<<endl;
}