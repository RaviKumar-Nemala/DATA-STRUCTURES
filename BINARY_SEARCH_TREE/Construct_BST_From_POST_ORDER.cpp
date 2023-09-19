#include"config.h"


Node *util  ( int postorder [ ] , int  &idx,  int lower_bound , int upper_bound  )
{

     if   (   idx < 0  )
     {
          return nullptr ; 
     }

     int val = postorder [ idx ] ; 

     bool case_1 =  val > upper_bound ? true : false ; 
     bool case_2 =  val < lower_bound  ?  true : false ; 

     if ( case_1 or case_2 )
     return NULL ; 
     
     Node *root = new Node (  postorder [  idx --] ); 

     root -> right = util   ( postorder , idx ,  root-> data ,  upper_bound ) ; 

     root -> left = util  ( postorder ,  idx , lower_bound , root -> data ) ; 
     
     return root;

}


Node * buildTree ( int postorder [ ]  , int  n  )
{

     int idx = n -1 ; 

     int lower_bound =  INT_MIN  ; 

     int upper_bound = INT_MAX ;
     
     return util ( postorder    , idx  , lower_bound , upper_bound ) ; 

     
}




int main ( )  
{

     int postorder_ [ 5 ]  = {2 , 4 , 3 , 7 , 5  } ;

     int n =  5 ; 

     Node *root  =  buildTree  ( postorder_ , 5 )    ; 

     inorder ( root ) ;
     cout<< endl ; 

     postorder ( root );

     return  0 ; 

     


}