#include<bits/stdc++.h>
using namespace std ;

//returns -ve if the pattern is existed on the txt
// return +ve(last un-matched index ) if the  some chars are matched 

//here all the elements in the pattern are  distinct
//when ever entire pattern is not matched with text then we simply found the last un-matched character
// then ( last unmatched char idx will be returned since pattern is distinct so from the next iteration we start from last unmatched character index only)

int is_existed ( string txt , string pattern , int start ) 
{    
     int  k = 0 ;

     for ( int idx = start ; idx < ( start + pattern.size () ) ; idx ++) 
     {
          if ( txt [ idx ] != pattern [ k++] )
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
     //the above implementation works for distinct elements in the pattern
     search_pattern( txt , pattern) ; 
     

     return 0 ;     
}