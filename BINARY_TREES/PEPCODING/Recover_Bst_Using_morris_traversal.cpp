#include "tree_code.h"

class Solution 
{
     public : 

     Node *first  = NULL ; 

     Node * last  = NULL ; 

     Node * prev  = NULL ; 


     void recover ( Node * root )
     {

          Node * curr = root ; 

          while ( curr != nullptr )
          
          {
               
               if ( curr -> left == nullptr )
               {
               
                    if ( prev != nullptr and prev -> data > curr -> data ) 
                    
                    {    

                              if ( first == nullptr)
                              {

                                   first =  prev ; 
                                   
                              }

                              last =  curr ; 

                    }

                    prev = curr  ; 
                    
                    curr = curr -> right; 


               }

               else 
               {

                    Node * predec =  curr -> left ; 

                    while ( predec -> right != nullptr and predec  -> right != curr )
                    {

                         predec = predec -> right ; 

                    }   

                    if ( predec -> right == nullptr )
                    {
                         predec -> right = curr ;
                         
                         curr = curr -> left ;

                    }

                    else 
                    {
                         predec -> right =  nullptr ; 

                         if  ( prev != nullptr and prev -> data >  curr -> data ) 
                         {
                              if ( first == nullptr )
                              
                              {
                                   first = prev  ; 

                              
                              }
                              last = curr ;

                         }
                         prev =  curr ; 

                         curr = curr -> right ; 
                    }

               }

          }
          return ; 

     }
          
     void inorder ( Node *root )
     {
          if ( root == nullptr )
               return ; 

          inorder  ( root -> left  ) ;

          cout << root -> data  << "   " ;  
          
          inorder ( root -> right ) ;

          return ;

     }
     void solve (  Node * root )
     {

          cout <<" BEFORE THE RECOVER : " << endl ; 

          inorder ( root ) ; cout << endl ;
          

          recover ( root ) ;

          if ( first and last )
          {
               swap   ( first -> data  , last -> data ) ; 

          }

          cout << "AFTER THE RECOVER   : " << endl; 

          inorder ( root ) ; 
          
          return ; 

     }
};




int main  ( )
{


     Node *root = new Node (  5) ; 


     root -> left = new Node  ( 3 ) ;


     root -> left -> left = new Node ( 9 ) ; 

     root -> left  -> right  = new Node ( 4  ) ;

     root -> right  = new Node ( 2 ) ;

     Solution obj ; 

     obj.solve (  root ) ; 





}