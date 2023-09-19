#include<bits/stdc++.h>
using namespace std ;
void print_val ( vector < vector< int >  > &arr ,int row_size , int col_size )
{
     int i , j ;
     for ( i  = 0 ; i < row_size ;  i ++ )
     {
          for ( j  = 0 ;  j < col_size;  j ++)
          {
               cout << arr[  i ]  [ j ] << " " ;
          }cout << endl;
     }
     return; 
}

void transpose ( vector<vector< int > > &arr , int row_size  , int col_size )
{
     int i , j ;
     for (  i = 0 ;  i < row_size ; i ++ )
     {
          for (  j = i ; j  < col_size ; j ++ )
          {
               int temp = arr [ i ] [ j ] ;
               arr [  i ] [ j ] = arr[  j  ] [ i ] ;
               arr [  j ] [ i ] = temp ;
          }
     }
}
void rotate_matrix( vector < vector< int >  > &arr  ) 
{
     int row_size = arr.size () ;
     
     int col_size = arr [ 0 ] .size () ; 

     transpose( arr ,  arr.size () , arr [ 0 ].size () ) ; 

     // print_val ( arr , row_size, col_size ) ; 
     
     int low  , high ;

     for ( int j = 0 ; j < col_size ;  j ++ )
     {
          low =  0 , high = col_size -1 ;

          while ( low < high )
          {
               swap ( arr [ low ] [  j ] , arr [ high][j]);
               low ++;
               high --;
          }

     } 

     print_val ( arr ,  row_size , col_size ) ;
     
}

int main ()
{
     
     int row_size = 4 ,  col_size = 4;
     
     int i , j; 
     
     vector< vector< int > > arr  ;

     for( i = 0 ; i <  row_size ; i ++ )
     {
          vector< int > temp ; 
          for ( j = 0 ; j < col_size ; j ++ )
          {
               int ele ; 
               cin >> ele ;
               temp.push_back ( ele ) ;  
          } 
          arr.push_back ( temp ) ;
     }

     rotate_matrix( arr ) ; 
     
     return 0 ;

}