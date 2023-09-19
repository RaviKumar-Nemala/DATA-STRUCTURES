#include "tree_code.h"


void diagonal_anti_clock (Node *root )
{

     if ( root == nullptr )
     {
          return ; 

     }

     queue < Node * >   q ;
     q.push ( root ) ; 
     
     vector < int > ans ; 

     while (  !q.empty () )
     {

          Node * curr = q.front ()  ; 

          q.pop();

          while ( curr != nullptr )
          {

               if ( curr -> right ) 
               {
                    q.push ( curr -> right  ) ; 

               }

               ans.push_back ( curr -> data ) ;

               curr = curr -> left ; 

          }

     }


     for ( auto it : ans  )
     {
          cout << it << "  "  ; 

     }
}


int main  () 
{

Node *root =  new  Node ( 1) ; 

root  -> left = new Node ( 2 ) ; 

root -> right = new Node ( 3 ) ; 

root -> left -> left = new Node ( 4)  ; 

root -> left -> right = new Node  ( 5 ) ; 

root -> right -> left = new Node ( 6 ) ;

root -> left -> right ->left = new Node ( 7) ;
diagonal_anti_clock ( root ) ;


/**
 *                    1
 *               
 *               2          3
 *             
 *             4    5     6   
 *                    
 *                7          
 */

//op  ->  1 2 4 3 5 

}