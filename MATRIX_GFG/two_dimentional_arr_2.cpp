#include<bits/stdc++.h>
using namespace std ;

void way_2( int row_size )
{
     vector<vector< int > > arr ;

     for ( int idx = 0 ; idx < row_size ; idx ++ )
     {
          vector<int > temp ;
          int col_size ;
          cin>> col_size ;
          while( col_size --)
          {
               int ele ;
               cin>> ele;
               temp.push_back (ele ) ;
          }
          arr.push_back ( temp ) ;
     }
     for( auto it : arr )
     {
          for ( auto it2 : it )
          {
               cout << it2 <<" ";
          }cout << endl; 
     }
     return;
}
int main ()
{
     int row_size ; 
     cin >>  row_size ;
     way_2( row_size ) ;
     return 0 ; 
     
     vector<int > arr [row_size ] ;

     for ( int idx = 0 ; idx  < row_size;  idx ++ )
     {
          int col_size ;
          cin>> col_size ;
          while ( col_size--)
          {
               int ele ;
               cin>> ele;
               arr [ idx ].push_back ( ele ) ;
          }
     }
     
     for( auto it : arr )
     {
          for ( auto it2 : it )
          {
               cout << it2 <<" ";
          }cout << endl; 
     }
     return 0; 
}