#include<bits/stdc++.h>
using namespace std ;

int solve ( int arr[]  , int n  )
{
     int left_max [ n ] ; 

     int right_max [ n ] ; 

     int i , j ; 
     
     left_max [ 0 ] = arr [ 0 ] ; 

     for( i = 1  ; i < n ; i ++ ) 
     {
          left_max [ i ] =  min (  left_max [ i -1 ] ,  arr[ i ] ) ; 
     }

     right_max [ n -1 ] =  arr [ n  -1 ] ;

     for (  i = n  - 2 ; i >=0 ; i -- )
     {
          right_max [ i ] =  max( arr [i ] , right_max[  i + 1] ) ; 
     }


     // cout <<"LEFT MAX = "<< endl;

     // for ( i = 0 ;i  < n ; i ++ ) 
     // {
     //      cout << left_max [ i ]  << " " ;  
     // }
     // cout << endl; 

     // cout <<"RIGHT_MAX " <<  endl;

     // for ( i = 0 ; i < n ; i ++ )
     // {
     //      cout << right_max  [ i ]  << " " ;
     // }

     
     i = 0 ,  j = 0 ;
     int res = INT_MIN; 

     while(  i < n  && j < n )
     {
          if ( left_max[ i ]  <= right_max[ j ]  ) 
          {
               res =  max (  res , ( j - i ) ) ;
               j ++;
          }
          else 
          {
               i ++;
          }
     }
     cout << res << endl;
      return res ;
     

     // cout << res << endl; 

}

int main ()
{
     int arr [] =  { 65, 6 ,74, 94, 56, 89, 9, 63, 75, 25, 34, 68 ,93, 48, 16} ;

     int n =  15 ;

     solve ( arr , n ) ; 

          return 0 ;
}