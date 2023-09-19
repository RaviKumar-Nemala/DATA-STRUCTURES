#include<bits/stdc++.h>
using namespace std ;


int main()
{
     int arr [4][4] ; 
     
     int row_size = 4 ,  col_size = 4;
     
     int i , j; 
     
     for( i = 0 ; i <  row_size ; i ++ )
     {
          for ( j = 0 ; j < col_size ; j ++ )
          {
               cin >> arr [  i ] [ j ] ; 
          } 
     }

     for( i = 0 ; i <  row_size ;  i ++)     
     {
          if( i% 2 == 0 )
          {
               for (  j = 0 ; j < col_size;   j ++)
               {
                    cout << arr [ i ] [ j ]   <<" " ; 
               }
          }     
          else 
          {
               for (  j = col_size -1 ; j >=0 ; j --)
               {
                    cout << arr [ i ] [ j ] << " " ;
               }
          }
          cout << endl;
     }

     return 0 ;
}