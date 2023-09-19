#include"config.h"


class Solution 
{
public: 


int solve ( string s1 ,string s2 )
{

     int n1 = s1.size()  ; 
     
     int n2 = s2.size() ;  


     int dp [ n1  +1  ] [  n2 + 1 ]  ; 

     int i , j ;

     for ( i = 0 ;i  <= n1 ; i ++ )
     {

          for (  j = 0  ; j <= n2 ; j ++ )
          {

               if( i  ==  0 or j == 0 )
                    dp [ i ] [ j ] = 0 ;
               
               else if( s1 [ i -1 ]  == s2 [ j - 1 ]  )
               {
                    dp [ i ] [ j ] =  1 + dp [ i -1 ] [ j - 1 ] ;
               }

               else
               {
                    dp [ i ] [ j ] = max ( dp [ i -1 ] [ j ] , dp [ i ] [ j - 1 ] ) ; 
               }

          }


     }
     
     return dp [  n1] [ n2 ] ;

}


};

int main () 
{

string s1 = "abcdef";

string s2 = "abghkef";

Solution obj ;

cout << obj.solve(s1 , s2  ) <<endl;

}