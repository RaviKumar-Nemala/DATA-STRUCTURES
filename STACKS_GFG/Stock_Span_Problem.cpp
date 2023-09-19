#include<bits/stdc++.h>
using namespace std ;

void stock_span_optimal ( int arr[]  , int  n ) 
{
     stack<int > st ;
     int span;
     st.push ( 0) ; 
     cout << 1  << " " ;
     for ( int  i = 1 ; i < n ; i ++  )
     {
          int curr_val = arr  [ i ] ; 
       
          while( !st.empty() and curr_val > arr[ st.top () ]  )
          {
               st.pop();
          }
          
          if( st.empty())
          {
               span  = i + 1; 
          }
          else 
          {
               span  =  i -  st.top ();
          }
          cout << span << " " ; 
          st.push ( i );
     }

}



void stock_span_naive( int arr[] , int  n ) 
{
     vector< int  > res ; 

     for ( int idx = 0 ; idx < n ; idx ++ )
     {
          int curr_val   = arr [ idx  ]; 

          int k =  idx -1 ; 
          int span_val = 1 ; 
          while ( k >= 0 )
          {    
               if ( arr [k] <  curr_val )
               {
                    span_val ++;
               }
               else 
               {
                    break;
               }
               k--;
          }
          res.push_back( span_val ) ;
     }

     for( auto it  : res )    cout << it <<" " ; 

}

int main ()
{
     int arr[] = { 10 , 20 ,30,40 , 60 ,50} ; 
                //  1 , 2 ,  3 , 4 , 5 , 1 
                //for the value 50 first left val is greater so we don't need to check for remaining values because element should be contiguosly smaller then the current element
     int n = 6 ;

     // given the array we need to find out the no of contiguoes values on the left_side which are smaleer then the curr element


     // stock_span_naive ( arr , n );

     stock_span_optimal ( arr , n ) ;

     return 0 ; 
}