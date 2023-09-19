#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int max_sub(int arr[] , int n)
{
     int i,j;
     int max_sum = 0;
     int original_sum = INT_MIN;
     for( i =0 ; i < n ;i ++)
     {
          max_sum +=arr[i];
          //if(max_sum == 0)
          //continue;
          if(original_sum <= max_sum)
          original_sum = max_sum;
     }
     return original_sum;
}

int main()
{
     int arr[] = {-1,-1,-1,2,3};
     cout<<max_sub(arr,5);
}