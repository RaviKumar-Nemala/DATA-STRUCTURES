#include"tree_code.h"



class house_robber 
{
     public :

     int without_robbery = 0;

     int with_robbery = 0 ;

     house_robber ( int a , int b )
     {
          this-> with_robbery = a ; 
          this-> without_robbery = b ;
     }

};
class Solution 
{

     public :

          house_robber solve ( Node *root )
          {
               
               if  ( root == nullptr )
                    {
                         house_robber temp ( 0 , 0 ) ;
                         return temp ;
                    }

               house_robber left = solve ( root -> left ) ;

               house_robber  right = solve ( root-> right );

               house_robber myans ( 0 , 0 ) ; 

               myans.with_robbery = left.without_robbery + right.without_robbery + root -> data  ;

               myans.without_robbery = max ( left.without_robbery , left.with_robbery ) +  max ( right.with_robbery , right.without_robbery ) ;

               return myans ; 

          }
};










int main()
{


     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4 ) ;

     root -> left -> right = new Node  ( 5 ) ;

     Solution obj ;

     house_robber  res = obj.solve( root );

     if( res.with_robbery > res.without_robbery )
     {
          cout << res.with_robbery << endl ;
     }
     else
     {
          cout <<  res.without_robbery << endl ; 

     }

     return 0 ; 


     /*
          1

       2       3   

     4   5  

*/

}