 #include<iostream>
 #include<stack>
 using namespace std;
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

void zig_zag_traversal(node*root){
     if(root==NULL){
          return ;
     }
     bool left_to_right=true;
     stack<node*>current;
     stack<node*>next_level;
     current.push(root);
     while(!current.empty()){
          node*temp=current.top();
          current.pop();
          if(temp){
               cout<<temp->data<<" ";
          if(left_to_right){
               if(temp->left){
               next_level.push(temp->left);
               }
               if(temp->right){
               next_level.push(temp->right);
          }
     }
          else{
               if(temp->right){
              next_level.push(temp->right);
               }
               if(temp->left){
               next_level.push(temp->left);
          }
     }
}
     if(current.empty()){
          left_to_right=!left_to_right;
          swap(current,next_level);
     }
}
}
int main(){
     node*root = new node(1);
     root->left= new  node(2);
     root->right= new node(3);
     root->left->left= new node(5);
      root->left->right= new node(6);
     zig_zag_traversal(root);
}