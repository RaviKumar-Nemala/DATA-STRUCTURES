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

void search_pattern  ( string txt , string pattern )
{
     
     //HERE WE USE THE SLIDING WINDOW APPROACH  
     // INITIALLY COMPUTE THE HASH OF THE PATTERN 
     // COMPUTE THE HASH VALUE IN THE TXT STRING for the window length( window length = pattern lenght)
     //IF THE HASH VALUE OF ( PATTERN AND THE TXT STRING ARE MATCHED THEN START COMPARE THE INDIVIDUAL CHARS)

     //let pattern = "abc" ;
     // for   a =  hash = 1 ;
     // for   b = 2 ;
     // for   c = 3 
     // hash value of the pattern =  ( a + b + c )  = ( 1 + 2 +3 ) = 6 

     int n  = txt.size() ;

     int m = pattern.size( ) ;

     int txt_hash_val = 0 ;

     int pattern_hash_val = 0 ; 

     int idx = 0 ;

     for( idx = 0 ; idx < m ; idx ++ )
     {
          char curr_char = pattern[ idx] ; 

          char txt_curr_char =txt[ idx]; 

          pattern_hash_val += ( int )(curr_char - 'a' +1 ) ; 

          txt_hash_val += ( int )( txt_curr_char - 'a' +1 );  
     }

     if ( pattern_hash_val == txt_hash_val )
     {
          if ( is_existed ( txt, pattern ,  0 ) )
          {
               cout << 0 << " " ; 
          }
     }

     int prev_sliding_idx = 0 ;
     for (  idx  = 1 ; idx <= (n - m ) ; idx ++ )
     {
          int curr_val = txt [ idx + m - 1] - 'a' + 1 ;

          int prev_sliding_val = txt[ prev_sliding_idx++] - 'a' + 1 ; 

          txt_hash_val =  ( txt_hash_val  - prev_sliding_val + curr_val ) ;

          if ( txt_hash_val == pattern_hash_val )
          {
               if( is_existed( txt , pattern , idx )  )
               {
                    cout<< idx <<" " ; 
               }
          } 
     }

}

int main ()
{

string txt = "aabbccddeeddff";

string pattern ="ddee";

search_pattern( txt , pattern) ; 

return 0 ;     
}