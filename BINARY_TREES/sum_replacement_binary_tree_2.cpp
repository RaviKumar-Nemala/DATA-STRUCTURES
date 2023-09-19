#include<iostream>
using namespace std ; 


class node 
{
     public : 
     node * left ;
     node * right ;
     int data ;      

  node ( int data ) 
  {
       this -> data =  data ;
       left  =  nullptr ;
       right = nullptr ; 
  }

};


void sumReplacement (  node * root )
{
    // sumUtil  ( root  ) ;
}

void inorder ( node* root )

{

     if ( root == nullptr )
     return  ;

     inorder ( root -> left  ) ;

     cout<<root->data << " " ;

     inorder ( root  -> right ) ;

}

bool is_leaf ( node *root )
{
     if( root and !root -> left and !root-> right)
     return true; 

     return false; 
}
int  sumUtil( node * root )
{    
     if( is_leaf( root )) 
     {
          int temp  =  root -> data;  
          root  -> data = 0 ;
          return temp;
     }
     
     int left_val = sumUtil ( root  -> left ) ; 

     int right_val  = sumUtil ( root  -> right );

     int temp   = left_val + right_val + root -> data ;

     root -> data = ( left_val + right_val ) ;

     return temp; 
 
}


int main() 
{

     node *root = new node ( 10 ) ;
     root-> left = new node ( -2 ) ;
     root -> right = new node ( 6) ;
     root -> left -> left  = new node (8 ) ;
     root -> left -> right = new node ( -4);
     root -> right -> left   = new node ( 7 ) ;
     root -> right -> right = new node ( 5 ) ; 
          
     sumUtil(root ) ;

     inorder ( root ) ; 

     
          //input :
            /* 10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5
     */

//Convert this to a tree where each node contains
//the sum of the left and right sub trees 
//of the original tree. 
//The values of leaf nodes are changed to 0.

//output 
          /*  20
          /    \
        4        12
       /  \     /  \
     0     0   0    0
     */

}