#include"tree_code.h"


bool is_bst ( Node *root , Node *prev )
{

     Node *curr =  root ; 

     while ( curr != nullptr )
     {
          
          if ( curr -> left == nullptr )
          {
               
               if ( prev == nullptr )
               {

                    prev = curr ;

               }
               //if the left node data is greater then the current node then return false 
               
               else if ( prev -> data >  curr -> data )
                    return false ;

               curr = curr -> right ; //this will help you to process the next node 
               //if the node does not have any left and right then it curr -> right is goes to its parent 
               
          }

          else
          {

               Node *predec = curr -> left ;

               while (  predec -> right != nullptr and predec -> right != curr )
               {

                         predec = predec -> right ;

               }
               //if the node is not processed yet 
               
               if ( predec -> right == nullptr ) 
               {
                    predec -> right = curr ;

                    curr = curr -> left ; 
               }

               //if node is already processed 
               else 
               {

                    if ( prev -> data > curr -> data )

                    {

                         return false ; 

                    }

                    predec -> right = NULL;

                    prev = curr ; // it  is used to when we are checking bst condition for the right side then the prev value becomes the root node and curr is pointig to the right side of the tree 

                    curr = curr -> right ;

               }

          }


     }

     return true ;


}


int main()
{
  
 /*  Node *root = new Node  ( 5 ) ;

     root -> left = new Node  ( 3 ) ; 


     root -> right = new Node ( 8 )  ;

     root -> left -> left = new Node  ( 2 ) ;

     root -> left -> right = new Node  ( 4 ) ;
*/


     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 


     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4 ) ;

     root -> left -> right = new Node  ( 5 ) ;



     cout<< is_bst (root , nullptr );



}