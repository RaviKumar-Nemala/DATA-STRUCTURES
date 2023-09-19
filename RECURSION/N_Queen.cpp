#include<bits/stdc++.h>
using namespace std ;

bool is_safe ( vector < vector < int > > &arr ,int curr_row , int curr_col , int n )
{
     int row  ,  col ;

     for ( row = 0 ; row < curr_row ; row ++ )
     {
           if ( arr [row][ curr_col] == 1 )
           {
                return false ;
           }
     }

     row = curr_row , col = curr_col ;

     while  ( row >=0 and col >=0 )
     {
          if ( arr [ row ] [ col ] == 1 )
          {
               return false ;
          }
          row --;
          col --;
     }

     row =  curr_row , col =  curr_col ;

     while ( row >=0 and col < n )
     {
           if ( arr [ row ][col] == 1 )
           {
                return false ;
           }
          row --;
          col ++;
     }
     return true ;
}

bool solve ( vector<vector< int > > &arr , int curr_row , int n ) 
{
          if ( curr_row >= n )
          {
                return true;
          }
          
          for( int col = 0  ; col < n ; col ++ )
          {
               if ( is_safe(arr , curr_row , col , n ) )
               {

                    arr[ curr_row ] [ col ] = 1 ;

                    if ( solve ( arr ,  curr_row + 1, n ) ) 
                    {
                         return true;
                    }
                    arr [ curr_row ] [ col ] = 0 ;
               }
          }

          return false ;
}

int main ()
{   
     int n = 4 ;

     vector< vector < int > > arr (  n , vector< int  > ( n ,  0 ) ) ;

     solve ( arr , 0 ,  n ) ;

     for( auto it : arr )
     {
           for ( auto  it2 : it )
           {
                cout << it2 << " ";
           }cout << endl;
     }


      
}