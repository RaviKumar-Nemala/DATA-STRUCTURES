#include "tree_code.h"
// given a binary search tree in the BST two nodes are swapped then find the nodes and correct it to satisfy the BST PROPERTY

class Solution 
{
     public :


     Node *prev  ; 

     Node *first ; 

     Node *last ;

     Node *middle ; 

     void inorder ( Node *root )
     {

               if ( root == nullptr )
               return ; 

               if ( prev != nullptr  and prev -> data  > root -> data )
               {

                    if ( first == nullptr )
                    {

                         first = prev ; 

                         middle = root ;

                    }

                    else 
                    {

                         last = prev ;

                    }


               }

               prev = root ;

               inorder ( root -> right ) ;

     }

     void solve ( Node *root ) 
     {

          inorder ( root ) ;

          if ( last == nullptr  )
          {
               swap ( first-> data   , middle -> data  ); 
          }
          else{

               swap ( first -> data , last -> data ) ;
          }

     }

};

int main () 
{

     



}