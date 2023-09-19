#include<bits/stdc++.h>
using namespace std ;

int get_smaller_ele_len ( string str,  int target_char ,  int start ) 
{
     int lesser_count = 0 ; 

     for ( int idx  = start ; idx < str.size  () ;   idx ++ ) 
     {
          if( str [ idx ]  < target_char ) 
          {
               lesser_count ++;
          }
     }
          return lesser_count ; 

}

int fact ( int val )
{
     int res = 1 ;

     int idx = 1 ;

     while ( idx <= val)
     {
          res = res * idx ; 

          idx ++;
     }
     return res ;
}

void find_lexo_rank ( string str )
{

     /**
      * try to find the how many element which are lexogrphically smaller then the current string  
      * 
      */

     int n = str.size ();

     int idx = 0 ;
     int count = 0 ; 
     int remaining_pos = 0 ; 
     for( idx  =  0 ; idx < n;  idx ++ ) 
     {
          char  curr_char = str [ idx ] ; 
          
          int lesser_count = get_smaller_ele_len( str , curr_char , idx+1) ; 
          int remaining_pos = n - idx -1 ; 
          int fact_val = fact ( remaining_pos ) ; 
          count += ( lesser_count * fact_val ) ;
     }

     cout << count +1 << endl;
}



int main ()
{
     string str = "dcba";

     find_lexo_rank ( str ) ;

     /**
      * example  => str = abc
      * 
      * lexo permutations = 
      * 
      *            abc   =  1
      *            acb   = 2 
      *            bac  = 3 
      *            bca   =  4 
      *            cab   =  5
      *            cba  = 6 
      * 
      * when input = bca then return rank of lexo order  = 4             
      */

     return  0;
}