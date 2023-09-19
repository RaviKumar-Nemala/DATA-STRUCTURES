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

void level_order_traversal(node*root){
     if(root==NULL)
     return ;
     queue<node*>q;
     q.push(root);
     q.push(NULL);//initially we only push root and becaz in 0th level we only have one element after we push NULL here null indicates that level is ended at that point//
     while(!q.empty()){
          node* temp =q.front(); //it holds the reference of the queue front element
          q.pop();//after that we need to pop that element from the queue
          if(temp!=NULL){//what ever the value holds by the temp is not a null then we need to print that value if it becomes null then it simply indicates that level is over//
               cout<<temp->data<<" ";
               if(temp->left!=NULL){///here we are checking that if that varianle is exists or not//if it is exists then we need to store that on the stack//
                    q.push(temp->left);
               }
               if(temp->right!=NULL){//simiralry for the second//
                    q.push(temp->right);
               }
          }
          else if(!q.empty()){//it is useful to store a null value after the particular level is over//
                    q.push(NULL);
               
          }
}
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     level_order_traversal(root);

     /**
      *          1
      * 
      *       2      3 
      * 
      * 4       5
      * 
      * 
      */

}