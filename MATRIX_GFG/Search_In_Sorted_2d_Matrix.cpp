#include<bits/stdc++.h>
using namespace std ;

bool is_existed( vector< vector< int  >  > arr  , int target )
{
     int row_size = arr.size () ;

     int col_size = arr [ 0 ] .size () ; 

     int i = 0 ;
     int j = col_size - 1 ; 

     while ( i < row_size and  j >=  0 )
     {
          int curr_val = arr  [ i ] [ j ] ;

          if ( curr_val > target )
          {
               j --;
          }
          else if ( curr_val = target )
          {
               cout << "row = " << i << "col =  " << j << endl;
               return true; 
          }
          else 
          {
               i ++;
          }
     }
     return false; 

}

int main ()
{
     int row_size = 4 ;
     int col_size = 4 ;

     vector < vector < int >  > arr = { { 1, 2,3  , 4  }  ,  { 5 , 6, 7, 8} , {  9 , 10 , 11 , 12 } , { 13 , 14 , 15 , 16 } } ;

     if ( is_existed ( arr , 9 ) )
     {
          cout <<"ELEMENT IS EXISTED " << endl;
     }
     else 
     {
          cout <<"ELEMENET IS NOT EXISTED " <<endl;
     }

     return 0 ;
} 