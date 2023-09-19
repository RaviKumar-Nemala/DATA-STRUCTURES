#include "tree_code.h"

int tiltOfTree  ( Node  *  ,  int & ) ;


int tiltOfTree ( Node * root )
{
     int tilt = 0 ; 

     tiltOfTree ( root  , tilt)  ;

     return tilt ; 


}

int tiltOfTree ( Node *root  , int &tilt  )
{

     if  ( root == nullptr )
     return 0 ;

     int left = tiltOfTree ( root  -> left , tilt ); 

     int right = tiltOfTree ( root  -> right , tilt ) ;

     tilt +=   ( abs ( left -right ) ) ;

     return  ( root -> data + left  + right ) ;

}

void printvec ( vector  <int>  ans )
{

     for ( auto it : ans )
     {
          cout << it  << " " ; 

     }
     return  ;

     
}


int main  (  ) 
{


     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4) ;

     root -> left -> right = new Node  ( 5 ) ;

     root -> right ->left = new Node ( 6 ) ;

     root -> right -> right  = new Node (  7 ) ;

     
     vector < int > ans  ; 


     int res  = tiltOfTree ( root  )  ;

     cout << "TOTAL TILT : " << res  ; 


     /*
          1

       2       3   

     4   5    6   7   
     
     */


    /*
     tilt =  0  ; 

     node = 4 ->.     tilt =  0 ( for  4 there is no left and right ) 

     node =  5 ->     tilt =  0 

     node = 2 ->      tilt  = ( | 4 -5 | ) = 1 

     node  = 6 - >      tilt = 0

     node = 7 ->         tilt = 0

     node  = 3 - >      tilt = ( abs ( 6 - 7 ) ) = 1 

     node =1        tilt (  | 11 - 16 | )  = 5




     */
}