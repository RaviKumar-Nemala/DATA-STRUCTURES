#include <bits/stdc++.h>
using  namespace std ; 

int preorder[100] ; 


struct Node 
{
     int data ; 
     Node *left ; 
     Node *right  ; 
     Node  ( int  t )
     {
          this -> data =  t ; 
          left = right =  nullptr ; 

     }

};

static int idx = 0 ; 

void preorder_traversal  ( Node *root )
{

     if ( root == nullptr )
     return ;  

     preorder_traversal ( root -> left ) ; 

     preorder_traversal ( root -> right )  ; 

     preorder[  idx ++ ] =  root -> data ; 


}

Node *util ( int preorder [ ] , int &idx , int upr_bound  , int n )
{
     if ( idx >= n or preorder [ idx ] >  upr_bound )
     {
          return nullptr ; 
     }

     
     Node *root  = new Node ( preorder [ idx ++ ] ) ; 
     
     root -> left = util  ( preorder , idx , root -> data , n ) ; 

     root ->  right = util ( preorder , idx , upr_bound , n ) ;

     return root ; 

}
Node * buildTree ( int preorder []  , int n  ) 
{


     int idx =  0 ; 
     int upr_bound =  INT_MAX ;  
     return util  ( preorder , idx  , upr_bound , n) ;


}
void inorder  ( Node *root )
{

     if ( root == nullptr )
     return ;  

     inorder ( root -> left ) ; 
     
     cout << root -> data << " " ;

     inorder ( root -> right )  ; 


}
          


int main (  ) 
{

int preorder [5]  = { 2 , 4 , 3 ,7 , 5 } ;

Node*root = buildTree(preorder , 5 );

inorder ( root );



 }