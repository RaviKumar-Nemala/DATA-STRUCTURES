#include<bits/stdc++.h>
using namespace std ;

int max_differ ( int arr[]  , int n )
{    
     int curr_min  = arr [ 0 ] ;

     int max_differ =INT_MIN; 

     for( int idx = 1; idx < n ; idx  ++)
     {    
          int curr_val = arr[ idx]  ; 

          max_differ = max(max_differ , curr_val  -curr_min ) ;

          if ( curr_val < curr_min)
               curr_min = curr_val;
     }

     return max_differ ;
     
}

int main ()
{
     int arr[] = { 2,3,10,6,4,8,1};
     int n =  7;    

     cout << max_differ( arr , n )  << endl;
     return 0;
}