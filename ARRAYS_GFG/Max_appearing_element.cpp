#include<bits/stdc++.h>
using namespace std ;

void find_max_appear_element( int left []  , int right []   , int  n )
{

     int freq [ 101 ] =  { 0 } ;

     for ( int idx = 0 ; idx<  n ; idx++ )
     {
          freq [ left[ idx ]]++;
          freq [ right[ idx] + 1 ]  = -1;
     }

     int sum = 0 ;
     int max_sum = INT_MIN;
     int res = -1;
     for ( int idx =  0 ; idx < 101 ; idx ++ )
     {
          sum +=  freq [ idx ] ;
          if( sum > max_sum )
          {    
               max_sum = sum ; 
               res = idx;
          }
     }

     cout <<"PRINTING THE MOST FREQUENT ELEMENT =  "<<  res<< endl;

}

int main ()
{
     int left [ ]=  { 1 ,2,4 } ;

     int right [ ] = { 4 ,5, 7 } ;

     int n = 3;

     /**
      * given the left and the right ranges we need to find the most appearing element 
      * left[0]to right[ 0] means elements between the left[0] to right[ 0 ]
      * 
      */
     find_max_appear_element( left , right , n  ) ;

     return 0; 
}