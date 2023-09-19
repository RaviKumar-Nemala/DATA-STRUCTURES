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

void  sum_at_kth_level(node*root,int k){
     if(root==NULL)
     {
          return ;
     }
   queue<node*>q;
   q.push(root);


   int level=0,sum=0;
   
   while(!q.empty()){
       
       int n  = q.size ( ) ;

       for  (int  i = 0 ;i  < n   ; i  ++ )
       {

          node * curr_node = q.front () ;

          if ( level == k )
          {
               sum += curr_node->data;
          }

          q.pop() ;

          if( curr_node -> left )
               q.push ( curr_node -> left );
          if ( curr_node -> right  ) 
               q.push ( curr_node -> right );
          

       }
       level ++;

   }
   cout<<sum<<endl;
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
    sum_at_kth_level(root,2);
}