#include<bits/stdc++.h>
using namespace std ;

int get_median (vector <vector< int > > arr  ) 
{
     int i , j ; 
     int min_val = INT_MAX ; 
     int max_val = INT_MIN; 
     
     int row_size = arr.size ( ) ; 

     int col_size = arr [ 0 ] .size () ; 

     for ( int i = 0  ; i < row_size  ; i ++ )
     {
          min_val = min ( min_val , arr [ i ] [ 0 ] ) ;
          max_val  = max( max_val , arr [ i ] [ col_size -1 ] ) ;
     }

     // cout << "MIN_VAL = " << min_val << endl;
     // cout <<"MAX_VAL " << max_val << endl;

     int target_pos = ( row_size * col_size + 1 ) / 2 ; 

     while ( min_val < max_val ) 
     {
          int mid_val = ( min_val + max_val ) /2 ; 

          int mid_pos = 0 ;
          //calculate the position of the mid_val
          for ( int i = 0 ; i <  row_size ; i ++ )
          {
               mid_pos += lower_bound( arr [  i ].begin() , arr [ i ] .end() , mid_val ) - arr[i].begin() ; 
          } 

          // if the mid_val is lesser the target then increment the min_val  
          if( mid_pos < target_pos )
          {
               min_val = mid_val  +1; 
          }
          else 
          {
               max_val  = mid_val ;// max_val should not set to the mid_val -1 
          }

     }

     //after executing the above loop both minval and max val points to the same element i.e our median element so we need to remove that element
     return min_val; 
}    

int main ()
{
     vector < vector <int > >  arr  = { { 5, 10 , 20 , 30, 40 } ,
                                        { 1 , 2,  3,  4, 5 } , 
                                        { 11 , 13 , 15 , 16 , 17 } };
     
     cout << get_median( arr  )  << endl;

     return 0 ; 
}