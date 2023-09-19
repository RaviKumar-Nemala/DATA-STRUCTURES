#include"tree_code.h"

static int max_sum  = INT_MIN; 

bool isLeaf (  Node *root )
{
     if ( root  and !root -> left and !root -> right )
          return true ; 
     else 
          return false ; 
}


int max_path_sum  ( Node *root )
{
     if ( root == NULL)
     {
          return INT_MIN ; 
     }
     if ( isLeaf  ( root ))  // if the node is a  leaf just simply return its value
     {
          return root -> data ; 

     }
     
     int left =  max_path_sum ( root -> left ) ;  // ee value root-> left nundi leaf node varaku vunna max_value store chestundi 

     int right = max_path_sum   ( root -> right ) ; // ee value root -> right nundi lefa node varaku vunna max_value store chestudi


     //oka leaf nundi anoter leaf ki path sum kavali ante madyalo root node undali 
     // for suppose  root node left side undi but root node right side ledu anukunte aa situation lo manam leaf to leaf path find out cheyyalemu 
     // so anduke mundu check chestunnam root node ki left and right side nodes vunnaya leda ani 

     if ( root -> left and root -> right )
     {
          
          max_sum = max ( max_sum ,  ( left + right +  root -> data ) )  ; 
          // here i am calculating the max_sum

     }

     return max ( left , right ) + root -> data ; 

     // root -> left side nundi leaf varaku vunnna max value and root -> right side nundi leaf varaku vunna max value lo ni aa value ithe maximum vuntundo aa value return avutundi 
     
}





int main (  )
{


     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 88 )  ;

     root -> left -> left = new Node  ( 4) ;

     root -> left -> right = new Node  ( 5 ) ;

     max_path_sum   ( root ) ; 

     cout << max_sum <<endl ; 


/*
          1

       2       0   

     4   5  

*/

/**
 * HERE FOR NODE 2  MAX_PATH_BETWEEN TWO LEAVES =  4 + 5 +  2 = 11
 * 
 * FOR NODE  1 MAX_PATH_BETWEEN TWO LEAVES  = ( 2 + 5 + 1 ) + 0 = 8
 * 
 * so the max path between two leaves =  11 
 * 
 */

}