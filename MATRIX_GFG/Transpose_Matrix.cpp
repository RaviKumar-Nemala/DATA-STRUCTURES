#include<bits/stdc++.h>
using namespace std ;



void print_mat( vector < vector< int > > arr , int row_size , int col_size )
{
     int i , j ;
     for ( i   = 0 ; i < row_size ; i ++ )
     {
          for ( j = 0; j < col_size; j ++ )
          {
               cout<< arr[ i ] [ j ] <<"  " ; 
          }cout << endl;
     }
     
}

void transpose ( vector<vector< int > > arr , int row_size  , int col_size )
{
     int i , j ;
     for (  i = 0 ;  i < row_size ; i ++ )
     {
          for (  j = 0 ; j  < col_size ; j ++ )
          {
               // cout << arr [ i ] [  j ] <<" " ; 
               
               if ( i == j )
               {
                    cout << arr [ i ] [ j ]  << " " ; 
               }
               else {
                    cout << arr [  j ] [ i ] << " " ; 
               }
          }cout << endl;
     }
     return ;
}
     
int main ()
{

     // print_mat( arr , row_size , col_size ) ;

     // cout <<  endl; 

     transpose( arr , row_size,  col_size ) ; 
     return 0 ; 
}    