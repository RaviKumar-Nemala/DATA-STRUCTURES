#include"tree_code.h"



void width_shadow ( Node *root )
{

     if  ( root  == nullptr )
          return ; 

     queue < pair < Node * , int > > q ; 

     unordered_map< int , int > mp ; 

     q.push ( make_pair ( root  , 0 )  ) ;


     while  ( !q.empty () ) 
     {

          Node *curr = q.front ().first; 
          
          int hd =  q.front ().second;
          
          q.pop () ; 

          int ele =  curr -> data ; 

          mp [  ele ]  = hd ; 

          if ( curr -> left )
          {
               q.push (  make_pair ( curr -> left ,  hd -1 ) ); 

          }

          if ( curr -> right )
          {
              
               q.push ( make_pair ( curr -> right ,  hd + 1  ) ) ; 

          }

     }

     int min_hd =  INT_MAX ; 

     int max_hd = INT_MIN ; 

     for ( auto it : mp )
     {
          int temp =  it.second ; 

          
          if ( temp < min_hd )
          {
               min_hd =  temp ; 
          }
          else if ( temp > min_hd )
          {
               max_hd = temp ;
          }

     }

     

     cout << "TOTAL SHADOW WIDTH IS : " << abs ( min_hd ) +  abs ( max_hd )  + 1  << endl ;


}

int main () 
{

Node *root =  new  Node ( 1) ; 

root  -> left = new Node ( 2 ) ; 

root -> right = new Node ( 3 ) ; 

root -> left -> left = new Node ( 4)  ; 

root -> left -> right = new Node  ( 5 ) ; 

width_shadow ( root ) ; 

return 0 ; 

/**
 *                  1
 *               
 *               2      3
 *             
 *             4    5     
 * 
 */

}



