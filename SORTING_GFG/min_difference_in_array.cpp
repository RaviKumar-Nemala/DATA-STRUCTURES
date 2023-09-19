#include<bits/stdc++.h>
using namespace std;

//TC = 0(N^2)
int get_min_differ_naive( int arr[] , int  n )
{
     int i , j;
     int min_differ = INT_MAX;

     for ( i = 1 ; i < n ; i ++ )
     {
          for ( j = 0 ; j < i ; j ++)
          {
               min_differ  = min( min_differ , abs( arr[i] - arr[j ]));
          }
     }
     return min_differ;
}

//TC O(nlogn)
int get_min_differ ( int arr[]  , int n )
{

     sort( arr , arr +n);
     int min_differ = INT_MAX;
     for ( int i = 1 ; i  < n ; i ++ )
     {
          min_differ = min ( min_differ , abs( arr[i-1] - arr[ i ] ));
     }
     return min_differ;
}
int main ()
{

     int arr[] = { 2,6,5,9};
     int n = 4 ;
     cout << get_min_differ( arr , n );
     return 0 ;
}