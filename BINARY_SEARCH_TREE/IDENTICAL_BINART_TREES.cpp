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

bool is_bst_identical(node*root1,node*root2){
     if(root1==NULL&&root2==NULL){
          return true;
     }
     else if(root1==NULL){
          return false;
     }
     else if(root2==NULL){
          return false;
     }
    bool is_true= root1->data==root2->data;
     bool is_left_safe=is_bst_identical(root1->left,root2->left);
     bool is_right_safe=is_bst_identical(root1->right,root2->right);
     if(is_true and is_left_safe and is_right_safe){
          return true;
     }
     else{
     return false;
 }
}
int main(){
     node*root= new node(1);
     root->left= new node(2);
     root->right= new node(3);
      node*root1= new node(1);
     root1->left= new node(2);
     root1->right= new node(3);
     if(is_bst_identical(root,root1)){
          cout<<"bst_identical"<<endl;
     }
     else{
          cout<<"NOT IDENTICAL"<<endl;
     }
}