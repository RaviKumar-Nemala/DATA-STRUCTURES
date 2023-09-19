#include<bits/stdc++.h>
using namespace std ;

void move_zeros_to_end ( int arr []  , int n  )
{
     int non_zeros_idx = -1;

     for ( int idx = 0 ;idx < n ; idx ++ )
     {
          int curr_val  = arr[  idx ] ; 
          if ( curr_val != 0 )
          {
               non_zeros_idx ++;
               swap( arr[ non_zeros_idx ] , arr[ idx ]) ;
          } 
     }

}

void print_val ( int arr[] , int n )
{
     for ( int idx =  0 ; idx < n ; idx ++)
          cout << arr [ idx ] <<" " ;
     cout<< endl;
}
int main ()
{
     int arr[] = { 0 , 0 , 0 ,5,6,4 };

     move_zeros_to_end ( arr , 6);
     print_val ( arr ,   6);
     return 0;
}
