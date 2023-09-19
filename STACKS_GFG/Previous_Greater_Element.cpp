#include<bits/stdc++.h>
using namespace std ;

void  prev_greater ( int arr[] , int n ) 
{
     stack < int > st;  
     cout  << -1 << " " ; 
     for ( int i = 1 ; i < n ; i ++ ) 
     {    
          int curr_val = arr [ i ]  ; 
          while ( st.empty() == false and ( curr_val >= st.top()))
          {
               st.pop();
          }

          if( st.empty() )
          {
               cout << -1 <<"  " ; 
          }
          else
          {
               cout << st.top() <<" " ; 
          }
          st.push ( curr_val ) ; 
     }     



} 




int main ()
{
     int n = 7 ;
     int arr[] = { 15  ,  10 , 18 , 12 , 4 , 6  , 2 , 8 } ; 
//output=        //-1 ,   15 ,  -1 , 18 , 12 ,12, 6, 12

     return 0 ;
}