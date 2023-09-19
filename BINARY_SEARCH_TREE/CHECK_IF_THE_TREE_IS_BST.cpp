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
bool is_bst(node*root,node*min,node*max){
     if(root==NULL){
          return true;
     }
     if(max!=NULL and root->data>=max->data){ //this is the condition if we pass the left part of the binary tree then the left node is always lesser than it s parent node it regulates that condition then we simply returns false 
          //cout<<"dd"<<" ";//maxis a node where we used to store the maximum limit of a binary tree inorder to insert on a particular pos//
          return false;
     }
     if(min!=NULL and root->data<=min->data){//this is essential for the passing the right sub part of the  binary tree//
          return false;
     }
     bool is_left_valid=is_bst(root->left,min,root);

     bool is_right_valid=is_bst(root->right,root,max);

     return is_left_valid and is_right_valid;

}
int main(){
     node*root= new node(1);  //in this case it returns false as the o/p becaz above nodes are not form a binary tree///
     root->left= new node(61);
     root->right= new node(8);
     if(is_bst(root,NULL,NULL)){//if it rturns true then our nodes form a bst otherwise not//
          cout<<"VALID"<<endl;
     }
     else{
          cout<<"INVALID";
     }
}