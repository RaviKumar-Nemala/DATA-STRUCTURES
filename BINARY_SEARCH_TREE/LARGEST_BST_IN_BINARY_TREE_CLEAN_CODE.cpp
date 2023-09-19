#include "tree_config.h"

struct node_info
{
     int min_val; 

     int max_val ;

     int bst_size ;

     node_info ( int min_val , int max_val , int bst_size  )
     {

               this -> min_val = min_val ;

               this -> max_val = max_val ;

               this -> bst_size =  bst_size ;

     }

};


node_info  largestBst( node * root )
{

     if ( !root )
     {
          return  node_info ( INT_MAX,  INT_MIN ,  0 );
     }


     auto left = largestBst ( root -> left ) ;

     auto right = largestBst ( root -> right ) ;

     int current_node_val = root -> val ;

     if(  current_node_val > left.max_val  and  current_node_val < right.min_val  )
     {
          int size = left.bst_size + right.bst_size + 1 ;
         
          return  node_info ( min( current_node_val , left.min_val ) ,  max( current_node_val , right.max_val ) , size );

     }

     else
     {

          return node_info( INT_MAX , INT_MIN , max( left.bst_size , right.bst_size) ) ;

     }

}


int main () 
{


     node * root  = new node( 10 ) ;

     root -> left = new node ( 9 );

     root -> right = new node ( 15 ) ;

     root -> right -> left =  new node( 11 ) ;

     root -> right -> right= new node( 16) ;

     node_info temp = largestBst ( root ) ;

     cout << "LARGEST BST SIZE =  "<< temp.bst_size << endl;

     return  0 ;

}





