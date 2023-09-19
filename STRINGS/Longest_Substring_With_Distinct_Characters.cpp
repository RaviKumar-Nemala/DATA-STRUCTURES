#include<bits/stdc++.h>
using namespace std ;

void longest_substr_brute_force ( string str)
{
     int i ,j;
     int res = INT_MIN;
     int n = str.size ();
     //TC -> O(N^2)
     for ( i = 0 ; i <  n ; i ++)
     {
          vector < bool > visited ( 256 ,  false );

          for ( j = i ; j  < n  ;  j++)
          {
               if ( visited [ str [ j ] ]  )
               {
                    break;
               }
               else 
               {
                 res = max ( res , j - i +1 ) ;
                 visited [ str [ j ] ] =  true;
               }
          }
     }
     cout << res << endl;
}

//TC -> O(N);
void longest_substr_distinct_chars_optimal( string str ) 
{
     vector < int > prev ( 256 , -1 ); //this array is used to check if the current element is already appeared in  the before or not 
     int n = str.size();
     int res = INT_MIN;
     int i =0 ;  
     for ( int j  = 0 ; j < str.size () ; j ++ )
     {
          int curr_char = ( int ) (str [ j ]) ;

          i = max ( i , prev[curr_char ] + 1 ) ; //if the curr char already appeared in the before prev[ curr_char] gives index the last appearance of that element if the curr char is not apperead before then ( i value be the max value)

          res = max ( res , ( j - i  + 1 ) ) ; //FINDING THE LENGHT OF THE SUBSTRING HERE

          prev [ curr_char ] = j ;//STORING THE CURR CHAR WHICH IS USEFUL WHEN CURR CHAR APPEARED AFTER SOME TIME

     }

     cout << res <<  endl;

}


int main()
{
     string str = "abcadbd";

     //output = c a d b ( 4 ) is the longest substring with all distince characters 

     // longest_substr_brute_force ( str ) ;
     longest_substr_distinct_chars_optimal( str ) ;
}