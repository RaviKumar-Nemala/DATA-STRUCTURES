#include<bits/stdc++.h>
using namespace std;

bool is_pair_found( int arr[] , int low, int high , int target_sum)
{
     while ( low < high)
     {

          int curr_sum = arr [ low ] + arr[ high ] ;

          if( target_sum == curr_sum)
          {
               return true;
          }

          if( curr_sum > target_sum)
               high --;
          else     
               low ++;
     }

     return false;

}

bool is_triplet_found ( int arr[] , int n , int target_sum)
{
     int high  = n -1;

     for ( int idx = 0 ;idx <n-2 ; idx++)
     {
          int low = idx+1;
          if( is_pair_found(arr,low,high,target_sum-arr[idx]))
          {
               return true;
          }
     }
     return false;

}


int main ()
{

     int arr[] = { 10,20,30,40,50};

     int target_sum = 100;

     if( is_triplet_found(arr,5,target_sum))
          cout <<"FOUND ";
     else  cout<<"NOT FOUND";
     
     return 0;
}