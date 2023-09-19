#include<bits/stdc++.h>
using namespace std;

int get_median ( int arr_1[] , int arr_2[] ,int n1 , int n2 )
{
     int low_1 =0;
     int high_1 = n1-1;

     while ( low_1 <= high_1)
     {
          int mid_idx_1 = (low_1 + high_1)/2;

          int right_min_1 = arr_1[mid_idx_1];
          int left_max_1 = arr_1[ mid_idx_1 - 1 ];

          int second_mid_idx = ( n1 + n2 )/2 - mid_idx_1;

          int right_min_2 = arr_2 [  second_mid_idx ];
          int right_max_2 = arr_2 [  second_mid_idx -1 ];

          if ( left_max_1 <= right_min_2  and 

          


     }


}


int main () {



     return 0 ;
}