#include "tree_code.h"



bool check_for_bst ( Node *root ,  int min ,int max )

{
     if ( root == nullptr )
          return true ; 
     
     int current_data = root ->data ;

    bool res= ( current_data > min and current_data <max )? true : false;

     if ( !res )
          return false;

     if ( ! check_for_bst ( root -> left  , min , current_data ) )
          return false;

     if( !check_for_bst ( root -> right , root ->data , current_data ) ) 
     {
               return false;
     }

     return true; 



}




int main() 
{
     
     Node *root = new Node  ( 5 ) ;

     root -> left = new Node  ( 3 ) ; 


     root -> right = new Node ( 8 )  ;

     root -> left -> left = new Node  ( 2 ) ;

     root -> left -> right = new Node  ( 4 ) ;

/*

     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 


     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4 ) ;

     root -> left -> right = new Node  ( 5 ) ;

*/
     Node *prev = nullptr ; 
     cout << check_for_bst ( root , INT_MIN , INT_MAX) << endl ;


}
