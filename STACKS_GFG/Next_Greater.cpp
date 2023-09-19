#include<bits/stdc++.h>
using namespace std ;


void next_greater ( int arr[] , int n ) 
{
     stack< int  > st ;

     cout << -1  <<" ";

     st.push ( arr [ n-1 ]  ) ; 
      
     for ( int idx = n -2 ; idx >= 0 ; idx -- )
     {
          int curr_val = arr[ idx ] ; 

          while (  !st.empty()  and  st.top() < curr_val )
         {
               st.pop();
         } 

          if ( st.empty() )
          {
               cout <<  -1 << " " ; 
          }
          else 
          {
               cout << st.top() << " " ; 
          }
          st.push( curr_val);
     }
      
}



int main () 
{    

     // int arr[] = {  5 , 15 , 10 , 8  , 6 , 12 , 9, 18 }  ; 
     
     // int arr[] = {  10 ,  15 ,20 , 25} ; 
     int arr[ ]  = {  25 ,20 , 15 ,10 } ;
     int n  = 4  ; 

     next_greater ( arr , n ) ; 

     return  0 ;
}