#include "tree_code.h"


vector <int > ans ; 

bool node_to_root ( Node *root , int key )
{

     if ( root == nullptr)
          return false; 

     if ( root -> data == key )
     {
          ans.push_back ( root -> data ) ;  //in node to root first element in the ans vector should be the leaf or the key element next element is its parent like this and the last element is going to be the root element
         return true ; 
     }

     bool left = node_to_root ( root -> left , key ) ; 
     
     if ( left == true  )
     {
          ans.push_back ( root -> data  );
          return true ;
     }

     bool right  = node_to_root ( root ->right , key ); 

     if ( right  == true  )
     {
          ans.push_back ( root -> data  );
          return true ;
     }

     return false ;
     

}


void print_values (  vector < int >  ans )
{
     
     for ( auto it : ans )
     {
          cout << it <<" " ;
     }
     return ; 


}
int main () 
{

     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4) ;

     root -> left -> right = new Node  ( 5 ) ;


     if ( node_to_root ( root ,  5 ) )
     {
          print_values ( ans ) ; 
     }
     else
     {
          cout << "KEY IS NOT FOUND IN THE TREE " << endl ;
          
     }


return 0 ; 

     /*
          1

       2       3   

     4   5  

*/


}