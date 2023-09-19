#include "tree_code.h"

bool isLeaf (  Node *root ) 
{
     if ( root  != NULL and root -> left == nullptr and root -> right == nullptr )
          return  true ;
     else 
          return false ; 

}
Node * removeLeaves (  Node *root )
{
     if ( root == nullptr )
          return  nullptr  ;
     if ( isLeaf ( root  ) )
     {
               return  nullptr ;  //if the root is the leaf node then simply remove that node and returns the nullptr
               // then the leaf node parent is points to the nullptr instead of the reference of the leaf   node 
                
               
     }
 

     root -> left = removeLeaves ( root -> left ) ; 

     root -> right  = removeLeaves ( root -> right ) ;

     return root; 

}


void preOrder ( Node *root )
{
     if ( root == nullptr )
     return ; 

     cout << root -> data <<" " ;

     preOrder ( root ->left );

     preOrder ( root -> right ) ;

     
     
}

int main ( ) 
{




      Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4) ;

     root -> left -> right = new Node  ( 5 ) ;

     root -> right ->left = new Node ( 6 ) ;

     root -> right -> right  = new Node (  7 ) ;

     cout<<" WITH LEAF NODES :  " ; 

     preOrder ( root ) ;

     root = removeLeaves ( root ) ; 

     cout <<" WITHOUT LEAF NODES  : "  ; 

     preOrder ( root ) ;

 /*
          1

       2       3   

     4   5    6   7
     */
}