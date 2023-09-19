#include<bits/stdc++.h>
using namespace std;

//PEAK ELEMENT IS GRETER THEN THE LEFT ELEMENT AND THE RIGHT ELEMENT 

int find_peak ( int arr [ ] , int  n )
{
     int low =  0 ;

     int high = n -1 ;

     while ( low <= high)
     {
          int mid_idx = ( low + high)/2;

          int mid_val  = arr[ mid_idx];

          if ( ( mid_idx==0 || mid_val > arr [ mid_idx -1] ) and  ( mid_idx == n-1 || mid_val > arr [ mid_idx +1 ]))
          {
               return mid_idx;
          }    

          else if ( mid_idx > 0 and mid_val > arr[ mid_idx -1 ] )
          {
               high = mid_idx -1;
          }
          else
               low = mid_idx + 1 ;

     }
     return -1;
}



int main ()
{
     int arr[] = { 10,20,30,4,5};

     int n = 5 ;

     int res = find_peak( arr , n ) ;

     if ( res != -1)
     {
          cout<< arr[res]<< endl;
     }
     return 0;
}