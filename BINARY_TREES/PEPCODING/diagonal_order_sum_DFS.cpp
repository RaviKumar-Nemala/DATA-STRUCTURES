#include "tree_code.h"

void solve ( Node *root , map<int  , int > &mp , int level )
{
     if ( root ==  NULL )
     return  ; 

     mp [ level ]  += root -> data ; 

     solve ( root -> left , mp ,  level - 1  ) ; 

     solve ( root -> right , mp ,  level ) ; 


}

void print_val ( map < int, int >   mp )
{

     for   ( auto it :  mp )
     {

          cout << it.first <<"  DIAGONAL SUM   = "<< it.second  << endl  ; 
     
     }

     return ; 

}


int main ()

{

Node *root =  new  Node ( 1) ; 

root  -> left = new Node ( 2 ) ; 

root -> right = new Node ( 3 ) ; 

root -> left -> left = new Node ( 4)  ; 

root -> left -> right = new Node  ( 5 ) ; 

root -> right -> left = new Node ( 6 ) ;

root -> left -> right ->left = new Node ( 7) ;
map < int, int > mp ; 

solve( root , mp , 0  ) ; 
print_val (mp ); 

 
/**
 *                    1
 *               
 *               2          3
 *             
 *             4    5     6   
 *                    
 *                7          
 
 op - >
1 + 3  = 4 

2 + 5 +6 = 13 

4 + 7 =  11 

 
 
 */



     




}