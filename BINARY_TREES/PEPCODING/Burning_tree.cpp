#include "tree_code.h"

int  min_burn_time = 0 ; 

void find_max_burn_from_this_point ( Node *root  ,Node *blocknode ,  int time )
{
     if ( root == nullptr  or root == blocknode )
          return ; 
     
     min_burn_time =  max ( min_burn_time , time ) ;


     find_max_burn_from_this_point ( root -> left , blocknode ,  time + 1 ) ; 
     
     find_max_burn_from_this_point(  root -> right , blocknode  , time +1 ) ;

}

int burnTree ( Node *root,  Node *target )
{

     if ( root == nullptr )
          return  -1; 
     
     if   ( root -> data == target -> data )
     {
          find_max_burn_from_this_point ( root , nullptr ,  0  ) ; 
          return 1 ; 
     }

     int left  =  burnTree ( root -> left , target ) ; 

     if  ( left != -1 )
     {
     
          cout << left << " ";
          find_max_burn_from_this_point ( root , root -> left , left + 1 )  ; 

          return left + 1 ; 

     }

     int right = burnTree ( root -> right , target ) ; 

     if  ( right != -1 )
     {
          find_max_burn_from_this_point ( root ,root -> right ,right );

          return right + 1 ; 
     
     }

     return  -1 ; 

}

Node * deserialize ( string src )
{
     int idx = 0 ; 

     Node *root = new Node  ( ( src [  idx ] - '0' ) ) ; 

     queue < Node * > q ; 

     q.push  ( root ) ; 

     int ele ; 

     int n  = src.size ()  ; 

     idx ++;

     while ( !q.empty () and idx < n ) 
     {

          Node *curr  = q.front () ; 

          q.pop ( ) ; 

          

          if ( src [ idx ] != '#' and idx < n ) 
          {
               
                ele =  ( src [ idx ] - '0' ); 

               Node *leftnode =  new Node ( ele  ) ; 
               
               curr -> left = leftnode ; 

               q.push ( leftnode ) ; 

          }         

          else 
          {
               curr -> left = nullptr ; 

          }
          idx ++ ; 

          
          if ( src [ idx ] != '#' and  idx < n  ) 
          {
               
                ele =  ( src [ idx ] - '0' ); 

               Node *rightnode =  new Node ( ele  ) ; 

               q.push ( rightnode ) ; 

               
               curr -> right = rightnode ; 

          }         

          else 
          {

               curr -> right = nullptr ; 

          }

          idx ++; 

          if  ( idx >= n )
          return root ; 

     }
     return root ; 

}


void inorder ( Node *root )
{

     if ( root == nullptr )
          return ;
     inorder ( root -> left ) ;

     cout << root -> data  <<  "  " ; 

     inorder ( root -> right ) ; 



}

int main ()
{

    

     string str  =  "123##45##67####" ; 



     Node *root = deserialize   ( str ) ;

     inorder ( root ) ; 

     Node *target_node = new Node  ( 5 );


     burnTree ( root , target_node )  ; 


     cout << "MINIMUM TIME TO BURN THE TREE : "<< min_burn_time  << endl ; 


     /**
      *                      1
      *
      *                 2          3
      * 
      *                          4      5 
      * 
      *                                6     7
      * 
      * 
      *        123##45##67####
      */

}    