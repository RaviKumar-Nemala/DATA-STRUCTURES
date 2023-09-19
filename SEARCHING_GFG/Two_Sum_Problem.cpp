#include<bits/stdc++.h>
using namespace std;


bool is_pair_existed( int arr[] ,int n , int sum_val)
{
     int low = 0;
     int high= n-1;

     while ( low <= high)
     {
          int curr_val = arr [ low ] + arr [ high];
          if ( curr_val == sum_val)     return true;

          if ( curr_val > sum_val)
          {
               high --;
          }
          else 
          {
               low ++;
          }
     }

     return false;
}

int main()
{
     int arr[] = { 10,20,30,40,50};
     int n = 5;
     int target_val= 60;
     bool res = is_pair_existed(arr,n,target_val);
     if ( res )    cout <<"PAIR FOUND WITH THE GIVEN VALUES";
     else cout <<"PAIR NOT FOUND WITH THE GIVEN VALUES";

     return 0;
}