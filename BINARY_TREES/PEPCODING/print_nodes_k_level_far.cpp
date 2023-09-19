#include "tree_code.h"


vector < Node * > ans ; 

bool node_to_root ( Node *root , int key )
{

     if ( root == nullptr)
          return false; 

     if ( root -> data == key )
     {
          ans.push_back ( root  ) ;  //in node to root first element in the ans vector should be the leaf or the key element next element is its parent like this and the last element is going to be the root element
         return true ; 
     }

     bool left = node_to_root ( root -> left , key ) ; 
     
     if ( left == true  )
     {
          ans.push_back ( root   );
          return true ;
     }

     bool right  = node_to_root ( root ->right , key ); 

     if ( right  == true  )
     {
          ans.push_back ( root  );
          return true ;
     }

     return false ;
     

}



void print_K_levels_down  ( Node *root , int k , Node*blocked_root )
{

     if ( root == nullptr or k < 0   or root == blocked_root)
     return ; 
     if ( k == 0 )
     {
          cout << root -> data << " " ; 
     }

     print_K_levels_down( root -> left , k -1 , blocked_root ) ;

     print_K_levels_down( root -> right , k -1  , blocked_root ) ; 

}



void print_nodes_k_far ( Node *root , int key  , int  k ) 
{
     if ( root == nullptr )
     return ; 

     bool res = node_to_root ( root ,  key ) ; 

     // if the key does not exist in the tree 
     if ( !res )  
          return ;
     
     for ( int  i = 0 ;i < ans.size() and i <= k  ;  i ++ )
     {    

               print_K_levels_down ( ans [ i ] , k - i , i ==0 ? nullptr : ans [ i -1 ]  )  ; 

     }

     return  ; 

}

     int main () 
{

     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4) ;

     root -> left -> right = new Node  ( 5 ) ;

     root -> right -> left = new Node ( 6 ) ;

     root -> right -> right = new Node ( 7  ) ;

     root -> right -> left -> left = new Node ( 8 ) ;

     root -> right -> left -> right = new Node ( 9 ) ;

     int key = 6;

     int k = 2 ;

     print_nodes_k_far ( root , key  , k ) ;


     //this will print the elements of two levels down from the root node 

/*
          1

       2       3   
              
     4   5    6    7

             8      9

*/
     


}