#include<bits/stdc++.h>
using namespace std ;

bool is_existed( string txt , string pattern , int start )
{
     int i = 0 ;

     for( int idx = start ; idx < (start+pattern.size ()) ; idx ++ ) 
     {
          if ( txt [ idx ]  != pattern [ i ++ ])
          {
               return false; 
          }

     }
          return true;

}


// TIME COMPLEXITY =O( N - M + 1 )*(O(M))
//where N IS THE TEXT LENGTH 
// M IS THE PATTERN LENGTH

void match_pattern( string txt , string pattern)
{
     for( int idx =  0 ; idx < txt.size ()-pattern.size ()+1 ; idx ++)
     {
          char curr_char = txt [ idx ] ;

          if ( curr_char == pattern [ 0 ] )
           {
               if (is_existed(txt , pattern , idx))
                    cout << idx << " " ;
           }

     }



}

int main ()
{
     string txt = "ABABABCD";
     string pattern = "ABAB";
     
     match_pattern( txt , pattern) ; 

     return 0;
}