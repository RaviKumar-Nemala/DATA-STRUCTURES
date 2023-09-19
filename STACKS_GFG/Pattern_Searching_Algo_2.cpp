#include<bits/stdc++.h>
using namespace std ;

//returns -ve if the pattern is existed on the txt
// return +ve(last un-matched index ) if the  some chars are matched 
int is_existed ( string txt , string pattern , int start ) 
{    
     int  k = 0 ;

     for ( int idx = start ; idx < ( start + pattern.size () ) ; idx ++) 
     {
          if ( txt [ idx ] != pattern [ k ] )
          {
               return idx ;
          }     
     }

     return -1;
}

void search_pattern ( string txt , string pattern)
{
     int idx = 0 ; 

     int n  = txt.length() ;
     
     int m = pattern.size (); 

     while ( idx <= ( n-m))
     {
          char curr_char = txt [ idx] ;

          if ( curr_char == pattern [ 0 ] ) 
          {
               int temp = is_existed( txt , pattern , idx);
               if( temp == -1 )
               {
                    cout << idx <<  " " ; 
                    idx = idx + pattern.size () ; 
               }
               else
               {
                    idx =  temp;
               }
          }
          else
          {
               idx ++;
          }

     }

}


int main ()
{
     string txt = "ABCDABC";
     string pattern ="ABC";

     search_pattern( txt , pattern) ; 
     

     return 0 ;     
}