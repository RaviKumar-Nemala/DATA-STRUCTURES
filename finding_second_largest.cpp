#include<bits/stdc++.h>
using namespace std; 

int get_second_largest ( int arr[] , int n )
{
     int second_large_ele_idx =  -1;

     int large_ele_idx = 0;

     for ( int idx = 1 ; idx < n ; idx ++)
     {
          int curr_val = arr [ idx ] ;

          if ( curr_val == arr[large_ele_idx ])
          {
               continue;
          }
          
          if ( curr_val > arr [ large_ele_idx ] )
               {
                    second_large_ele_idx = large_ele_idx;
                    large_ele_idx = idx ;
               }
          else if ( second_large_ele_idx == -1 or curr_val >  arr[ second_large_ele_idx])    
               {
                     second_large_ele_idx = idx;
               }
     }

     return second_large_ele_idx ;

}


int main ()
{
     int arr [] =  { 5 , 30, 20 , 4, 6} ;

     int n  = 5;

     cout << get_second_largest( arr , n )<< endl;

     return 0;
}