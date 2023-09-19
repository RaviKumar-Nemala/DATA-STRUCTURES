#include<bits/stdc++.h>
using namespace std ;

int get_max_pair_val( vector < vector < int > > arr ) { 
     int row_size =  arr.size () ; 
     int col_size = arr[ 0 ].size () ;
     int i , j ;

     //this stores the max value in that region from  rigth and bottom
     vector< vector< int > > copy ( row_size,  vector<int>(col_size -1));
     
     int last_row =   row_size -1 ;
     int last_col = col_size -1;
     copy [ last_row ][ last_col ]  = arr[ last_row][ last_col ]; 

     for( i = last_row-1 ; i>= 0 ; i -- )
     { 
          int curr_left = arr [ last_row] [ i ]  ; 
          int curr_top =  arr [ i ] [ last_col];
          copy[last_row][i] =  max( curr_left , copy[last_row][ i +1 ] );
          copy[ i ][last_col] = max( curr_top , copy [i+1][last_col]);
     }

     for( i = last_row -1 ; i >=0  ; i -- ){
          for (  j = last_col -1 ; j >=0 ; j -- )
          {
               int curr_val = arr [ i ] [ j ];
               int right_max =  copy[ i ] [ j +1 ];
               int bottom_max = copy [ i +1 ][ j ];
               copy[i][j ] = max( curr_val , max( right_max , bottom_max));
          }
     }

     int max_val  = INT_MIN;

     for( i = 0 ; i < row_size -1  ; i ++ )
     {
          for ( j = 0 ; j < col_size-1 ; j ++ )
          {   
               int curr_val = arr [ i ] [ j ] ;
               
               int region_max = max(  copy [ i +1 ][ j ] , copy [ i ] [ j +1 ]) ;

               int curr_differ = region_max - curr_val ; 

               max_val = max( max_val , curr_differ ) ;
          }
     }

     return max_val;

}

int main () {
     
     vector < vector < int > >  arr = 
      { 
          { 1 , 2 , 3  , 4 } , 
          { 5 , 6 , 7 , -10 },
          { -8 , 9 , 12 , 3 } , 
          { 7 , 6 , 5 , 20 } 
     };
     cout << get_max_pair_val ( arr ) << endl;
     return 0 ;
}