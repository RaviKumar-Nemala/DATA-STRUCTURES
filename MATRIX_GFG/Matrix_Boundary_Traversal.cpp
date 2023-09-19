#include<bits/stdc++.h>
using namespace std ;

int arr [4][4] ;

void boundary_traversal( int row_size , int col_size )
{
     
     int last_row = row_size - 1 ;

     int last_col = col_size -1 ;

     int i , j; 

     if ( row_size == 1 )
     {
          
     for ( j = 0 ; j < col_size ;  j ++ )
     {
          cout << arr [ 0 ] [ j ] << " " ; 
     }cout << endl;

     }
     else  if ( col_size ==1 )
     {
          for ( i = 0 ;  i < row_size ; i ++ )
          {
               cout << arr[ i ] [ 0 ] << " " ; 
          }cout << endl;
     }
     else {
     for ( j = 0 ; j < col_size ;  j ++ )
     {
          cout << arr [ 0 ] [ j ] << " " ; 
     }cout << endl;
     for ( i = 1 ; i < row_size ; i ++ )
     {
          cout << arr [ i ] [ last_col ] <<" " ;
     }cout<< endl;
     for ( j = last_col -1 ; j >=0 ; j -- )
     {
          cout << arr [  last_row ] [ j ] << " " ;
     }cout << endl;
     for ( i = last_row - 1 ; i >= 1 ; i -- )
     {
          cout << arr [ i ][ 0 ] << " " ;
     }cout << endl;
     }

     return;

}

int main()
{
      
     int row_size = 4 ,  col_size = 4;
     
     int i , j; 
     
     for( i = 0 ; i <  row_size ; i ++ )
     {
          for ( j = 0 ; j < col_size ; j ++ )
          {
               cin >> arr [  i ] [ j ] ; 
          } 
     }
     
     boundary_traversal( row_size,  col_size ) ; 
     
}