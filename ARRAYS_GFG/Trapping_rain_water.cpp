#include<bits/stdc++.h>
using namespace std ;

void print_val ( vector<int> arr  , int in )
{
     for ( auto  it : arr )   
          cout << it<<  " " ; 
     cout<< endl; 
     return;
}

void handle_sufix (  vector <int >&sufix  , int  arr []  , int n )
{
     int max_val  = arr [ n -1 ] ; 
     sufix[ n -1 ] =  max_val ; 
     for ( int idx  = n -2 ; idx >= 0 ; idx -- )
     {
          sufix[ idx ] = max_val ;

          max_val = max ( max_val , arr [ idx ] ) ;

     }
     
     print_val ( sufix , n ) ; 
}

void hanlde_prefix ( vector < int > &prefix , int arr [] , int n ) 
{
     int idx  = 0 ; 

     int max_val =  arr [  0 ] ; 
     prefix[  0 ] = arr [  0 ] ; 
     for ( idx = 1 ; idx < n ; idx ++)
     {          
          prefix [ idx ] =  max_val ;

          max_val = max (max_val ,  arr[  idx ]) ;  
     }
     print_val( prefix ,  n ) ; 
     return;
}

int get_max_water  (  int arr []  , int  n )
{
     //used to find the max element on the left side of the current element 
     vector < int > prefix ( n ) ;
     
     vector < int > suffix  ( n ) ;  
     
     hanlde_prefix ( prefix,  arr , n  ) ;

     handle_sufix ( suffix  ,arr,   n ) ;

     int max_stored_water  = 0 ; 

     for ( int idx = 1 ; idx < n-1 ; idx ++ ) 
     {              
          int curr_val = arr[  idx ]  ;

          int left_max = prefix [idx] ; 
          
          int right_max = suffix[ idx ];

          max_stored_water +=  ( min( left_max , right_max) -  curr_val ) ;

     }

     cout  << max_stored_water<< endl;

}


int main ()
{
     int arr[]  = { 3,0 , 0 , 2 ,  0  ,  4 } ;
     int n = 6 ; 
     get_max_water( arr , n ) ; 

     return 0;
}