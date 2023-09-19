#include<bits/stdc++.h>
using namespace std ;

//store the first row in the map 
// from second row onwards check if those elements are in the map 
// if those elements found in the next row increase its frequency
//do the step 1 and step2  for all the rows 
// after that iterate through the map print the elements whose frequncey is equal to the row_size
//common element in all the rows having the frequncey equal to the row_size
// if duplicate elemets are in the same row increase its frequency only at once

void solve( int mat [ 4 ][ 5 ] )
{
     unordered_map< int ,  int >mp ;
     int row_size = 4 , col_size = 5  ; 
     int i , j ;
     
     for(  i = 0 ; i < row_size ; i ++ ){
          for (  j = 0 ; j < col_size ;  j ++ )
          {
               int ele = mat [ i ]  [ j ] ; 
               if ( i == 0 )
               {
                    mp [ele] =  1 ;
               }
               else 
               {
                    if( mp.find( ele ) != mp.end() )
                    { 
                         int freq = mp [ ele ] ;
                         if ( freq < (i +1) )
                         {
                              mp [ ele ] = freq + 1;
                         }
                    }
               }
          }
     }

     for( auto it : mp ){
          int ele = it .first ;
          int freq = it.second ;
          if ( freq == row_size )  {
               cout << ele << " " ; 
          }
     }

}

int main ()
{
     int mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

     solve (mat );
     
     return 0 ;
}