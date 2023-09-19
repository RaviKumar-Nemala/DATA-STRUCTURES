#include<bits/stdc++.h>
using namespace std ;

void print_val ( vector < int > arr ) 
{
     for( auto it : arr ) 
     {
          cout << it <<" " ; 
     }
     cout << endl;
}



vector< int > fill_next_smaller( int arr[] , int n ) 
{
     vector< int >next_smaller( n  ,  INT_MAX);
     
     next_smaller[ n -1 ] =  -1 ; 

     int res ;      

     stack < int > st ; 

     for ( int idx =  n-2 ; idx >=0  ; idx -- ) 
     {
          int curr_val = arr [ idx ] ; 

          while ( !st.empty () and arr[ st.top () ]  > curr_val)
          {
               st.pop();
          }     

          if ( st.empty() )
          {
               next_smaller [ idx] =  -1;
          }
          else 
          {
               next_smaller [ idx ] = st.top ();
          }
          st.push ( idx ) ; 

     }

     return next_smaller ;

}


vector < int > fill_prev_smaller( int arr[] , int  n  ) 
{
     stack < int > st ; 

     vector < int > prev_smaller ;

     prev_smaller.push_back ( -1 ) ;
     int res ; 
     for ( int idx = 1 ; idx < n ; idx ++ ) 
     {
          int curr_val = arr [ idx ]  ; 

          while ( !st.empty() and curr_val <  arr[ st.top () ]  )
          {
               st.pop();
          }     
          if ( st.empty()) res =  -1 ;
          else  res =  st.top () ;
          st.push ( idx ) ;
          prev_smaller.push_back(res);

     }

     return prev_smaller ; 

}


void largest_histogram_size_optimal ( int arr[]  , int n ) 
{
     stack< int > st; 
     int max_val =INT_MIN;
     for ( int idx = 0 ;  idx <  n ; idx ++ )
     {
          int curr_val = arr [  idx ] ; 

          while ( !st.empty() and arr[ st.top ()] >= curr_val ) 
          {
               //now here finding the largest histo area for the top_idx
               //for top idx next element in the stack is the left smaller element'
               //current idx is the right smaller elemnt 
               //by using this we can find the area of that element
               int top_idx = st.top();
               st.pop();
               int left_smaller_idx =  st.empty() ? idx  : st.top();
               int right_smaller_idx = idx ; 
               int total_size = arr[top_idx] * ( right_smaller_idx - left_smaller_idx  -1 );
               max_val = max ( max_val , total_size );
          }

          st.push ( idx )  ; 
     }
     
     //after completion of the loop if in case we have elments in the stack need to process again

     while( !st.empty() ) 
     {
          int top_idx =  st.top(); st.pop();
          int total_size = arr[ top_idx]* ( st.empty() ) ? n  :( n - st.top() -1 ) ;
          max_val = max ( max_val , total_size);
     }

     cout << "MAX AREA = " << max_val << endl;
     return;
}



void largest_histogram_size( int arr[] , int n ) 
{
     
     vector<int > prev_smaller  = fill_prev_smaller( arr , n  );

     vector < int > next_smaller = fill_next_smaller ( arr , n ) ; 

     // print_val( prev_smaller ) ;

     // print_val( next_smaller ); 

     int max_val = 0 ; 
     //in the left side find out the value which is lesser then the curr_val 
     //in the righ side find out the value which is lesser then the curr_ val 
     for ( int idx = 0 ; idx < n ; idx ++ )
     {
          int curr_sum =  0;
          
          if( prev_smaller [ idx ] != -1 )
          {
               curr_sum += ( idx -  prev_smaller[idx] - 1 ) * arr[ idx] ; 
          }
          else 
          {
               curr_sum = arr[ idx ] ; 
          }

          if ( next_smaller [ idx ] != -1 )
          {
               curr_sum +=  ( idx - next_smaller[ idx ] - 1 ) * arr[ idx ]  ; 
          }
          else 
          {
               curr_sum = arr [ idx ];  
          }

          max_val = max ( curr_sum , max_val ) ;

     }

     cout << max_val << " "  << endl;

}


int main ()
{
     int arr[] = { 6 ,2,5,4,1,5,6} ;
     
     int n =  7 ; 

     largest_histogram_size ( arr,  n ) ;   
     
     return  0; 
}