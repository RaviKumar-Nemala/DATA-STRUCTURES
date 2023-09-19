#include<bits/stdc++.h>
using namespace std;


int get_last_occr(  int arr[]  , int  target , int  low ,int high)
{
     int last_occr = -1 ;

     while ( low <= high )
     {
          int mid_idx =( low + high )/2;
          int mid_val = arr [ mid_idx ];

          if ( target  == mid_val)
          {
               last_occr = mid_idx;
          }
          if ( target < mid_val)
          {
               high =  mid_idx -1;
          }
          else 
          {
               low = mid_idx +1;
          }

     }

     return last_occr;


}


int main ()
{
     int arr[] = { 1 ,2 ,2 , 8 , 8 ,8 };
     int res = get_last_occr( arr , 2 , 0 , 5);
     if( res != -1)
     {
          cout <<"PRINTING THE ELEMENT INDEX = " << res<<endl;
     }
     else 
     {
          cout<<"ELEMENT IS NOT FOUND"<<endl;
     }
 


}