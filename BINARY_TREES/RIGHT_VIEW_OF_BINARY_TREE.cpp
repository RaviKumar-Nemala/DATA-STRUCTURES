#include<iostream>
#include<queue>
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
void right_view(node *root){
     if(root==NULL){
          return ;
     }
     queue<node*>q;
     q.push(root);
     while(!q.empty()){
          int n=q.size();
          for(int i=0;i<n;i++){
                node *temp=q.front();
                q.pop();
               if(i==n-1){
                    cout<<temp->data<<endl;
               }
          if(temp->left!=NULL){
               q.push(temp->left);
          }
          if(temp->right!=NULL){
               q.push(temp->right);
          }
     }
}
}
int main(){
node *root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->right->right=new node(5);
root->left->left=new node(4);
root->left->right=new node(3);
root->left->right->right=new node(7);
right_view(root);




      /*     1
          /    \
         2      3
        /  \     \
        4   6     5 
            \
              7  
*/
}

