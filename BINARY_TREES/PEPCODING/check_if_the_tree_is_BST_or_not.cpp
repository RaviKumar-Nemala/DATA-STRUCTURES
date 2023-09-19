#include "tree_code.h"

bool isBst ( Node *root , int min ,  int max ) 
{
     if ( root == nullptr )
          return true  ; 
     
     if ( root -> data <=min or root -> data >= max )
          return  false ; 
     
     bool left = isBst ( root -> left ,  min , root -> data ) ;
     
     bool right = isBst ( root -> right , root -> data ,  max ) ;

     return ( left and right ) ;


}



int main () 
{

     


}