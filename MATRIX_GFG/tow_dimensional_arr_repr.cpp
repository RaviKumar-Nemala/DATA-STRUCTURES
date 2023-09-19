#include<bits/stdc++.h>
using namespace std ;


void pass_param_2( int **arr, int row_size , int col_size )
{

     int i , j ;
     for (  i = 0 ;  i <  row_size ; i ++ )
     {
          for ( j  = 0  ; j < col_size ; j ++)
          {
               cout << arr [ i ] [ j ] << " ";
          }cout << endl;
     }
}

#define default_row_size 3
// in c++ we can omit the row size and  the col size should be the specified
void pass_param(   int row_size  , int arr [] [ default_row_size]  )
{
      int i , j ;
      for ( i  =  0 ; i <  row_size ; i ++)
      {
          for ( j = 0 ; j  < 3 ; j ++ )
          {
               cout << arr [ i ] [ j ] << " " ; 
          }cout << endl;
      }
     return;
}


void second_way() 
{
     int row_size = 3 ;
     int col_size = 3 ;

     int *arr [  row_size ] ;     

     for  ( int idx  =  0 ; idx < row_size ; idx ++ )
     {
          arr[ idx ] = new int [ col_size] ;
     }

}

void config( const int row_size , const int col_size ) 
{        
          int arr [ row_size ][col_size ] ;
          int i , j ;
          for( i = 0 ;  i < row_size ; i ++)
          {
               for ( j = 0 ; j <  col_size ; j ++ )
               {
                    cin >> arr [ i ] [ j ] ;
               }
          }
          // pass_param( row_size , arr ) ;
}

int main () 
{
     int **arr ; 
     int row_size  =  3 ;
     int col_size = 3 ;


     config (row_size , col_size ) ; 
     
     return  0;

     arr = new int*[ row_size ]  ;

     for ( int idx = 0 ; idx < row_size ; idx ++ )
     {
          arr [ idx ] = new  int [  col_size ] ;
     }
     
     int i , j;
 
     for ( i =  0 ; i < row_size;  i ++ )
     {
          for ( j = 0 ;  j <  col_size ; j ++ )
          {
               cin >> arr [ i ] [ j ] ; 
          }
     }

     pass_param_2 ( arr , row_size  , col_size) ;

     return 0 ;
}