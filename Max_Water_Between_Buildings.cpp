#include<iostream>
#include<limits.h>
using namespace std ;


int solve( int arr [] , int  n )
{
     int low =  0 ; 
     int high = n -1 ;

     int res  = INT_MIN; 

     while (  low < high ) 
     {
          int gaps  =  ( high - low ) -  1 ;

          res =  max ( res , min( arr [ low ] ,  arr[high] )* gaps);
          cout << " RES = " << res << endl ;
          if( arr[ low ] < arr [ high  ] ) 
          {
               low ++;
          }
          else{
               high --;
          }
     }

     cout << res << endl; 
}



int main ()
{
     int arr []  = { 2,1,3,4,6,5}  ; 
     
     int n =  6;

     solve ( arr , n ) ; 

     return 0 ; 
}