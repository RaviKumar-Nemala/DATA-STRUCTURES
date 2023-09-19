#include <bits/stdc++.h>
using  namespace std ; 

int inorder[100] ; 


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

void inorder_traversal  ( Node *root )
{

     if ( root == nullptr )
     return ;  

     inorder_traversal ( root -> left ) ; 
     
     inorder [  idx ++ ]  = root -> data ; 

     inorder_traversal ( root -> right )  ; 


}
Node * Util ( int inorder [] , int start , int end )
{
     if  ( start > end  )
     return nullptr ;

     int mid =  ( start +  end ) / 2 ; 

     Node * root =  new Node ( inorder [ mid ] ) ; 
     
     if ( start == end )
          {
               return root  ; 
          }

     root -> left =  Util ( inorder , start , mid -1 ) ; 

     root -> right = Util ( inorder , mid + 1 , end ) ;
     
     return root ;

}

Node *BuildTree  ( int inorder [] , int  n  )
{

     int start = 0 ; 

     int end =  n -1 ; 

     return Util ( inorder,  start , end )  ; 

}

void printNodes ( Node * ) ; 

int main (  )
{

     Node *root = new Node   ( 5 ) ; 

     root -> left = new Node ( 3 ) ; 

     root -> right =  new Node ( 7 ) ;

     root -> left -> left = new Node ( 2) ;

     root -> left -> right = new Node ( 4 );
     inorder_traversal ( root );
      
     root = BuildTree (  inorder , 5 )  ; 

     printNodes ( root ) ; 

}

void printNodes ( Node * root )
{
     if ( root == nullptr )
     return ;

     printNodes ( root -> left ) ;
     cout << root -> data  << "  " ; 

     printNodes ( root -> right )  ; 

}