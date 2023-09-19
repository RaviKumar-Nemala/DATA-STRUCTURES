#include"config.h"

class Solution 
{
public : 


void solve ( string s1 , string s2  )
{

     int s1_idx = 0 ; 

     int s2_idx  = 0 ;

     int s1_len =  s1.size() ;

     int s2_len = s2.size() ;

     int prev_lcs_size = INT_MIN;


     int i , j ;

     int dp [ s1_len + 1  ] [  s2_len + 1 ] ; 


     for ( i = 0 ;i  <= s1_len ; i ++ )
     {

          for( j = 0; j <= s2_len ; j ++ ) 
          {

               if( i == 0 or j == 0 )
                    dp [ i ] [ j ] =  0 ;

               else if (s1 [  i-1 ]  == s2 [ j - 1 ] ) 
               {
                    

                    dp  [ i ] [ j ] = 1 + dp [ i - 1 ] [ j - 1 ] ;

                    if( prev_lcs_size  < dp [ i ] [ j ] ){
                    
                    s1_idx = i-1 ;

                    s2_idx = j-1 ; 
                    prev_lcs_size    = dp [ i ] [ j ];
                    }

               }

               else 
               {
                    dp [ i ] [ j ] = 0 ;
               }

          }


     }


     while ( s1_idx >=0 and s2_idx >= 0 )
     {

          if ( s1 [ s1_idx ] == s2 [ s2_idx ] )
          {
               cout << s1 [ s1_idx ] ;
               s1_idx --;
               s2_idx -- ;
          }
          else
          {
               break;
          }

     }





}







};


int main ( )
{

string s1 = "abcdgef";

string s2 = "abdgef";

Solution obj ;

 obj.solve(s1 , s2  ) ;



}