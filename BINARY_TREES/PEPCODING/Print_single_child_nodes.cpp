#include "tree_code.h"


bool hasSingleChild ( Node *node  )
{
     bool case_1 =  ( node != nullptr and node -> left !=nullptr and node -> right == nullptr  ) ? true : false ; 

     bool case_2 =  ( node != nullptr and node-> right != nullptr and node -> left ==  nullptr ) ?  true  : false ; 

          if ( case_1  or case_2 ) 

          {
               return true ; 
          }
          else 
               return false ;

}

void print_single_child_nodes ( Node *root  , Node * parent )
{
     if ( root == nullptr )
     {
          return ; 
     }

     if ( hasSingleChild ( parent ) ) 
     {

               cout <<  root -> data  <<  "  " ; 
               

               return  ; 

     }

     print_single_child_nodes ( root -> left   , root ) ;

     print_single_child_nodes ( root -> right , root  ) ;

     return ;  

}

int main ( ) 
{




      Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4) ;
     
     root -> right ->left = new Node ( 6  )  ;

     
     print_single_child_nodes ( root ,  nullptr  ) ;

     return 0; 
}
     
 /*
          1

       2       3   

     4       6  
     
     */