#include<bits/stdc++.h>
using namespace std ;


int get_subset_sum ( int arr[] , int idx, int curr_sum , int target_sum )
{
     if ( idx <  0 )    return 0 ;

     if ( arr [ idx ]  + curr_sum  == target_sum )     return 1 ;

     return get_subset_sum ( arr , idx - 1 ,  curr_sum + arr [ idx ] , target_sum ) + get_subset_sum( arr , idx-1 ,  curr_sum , target_sum );

}

int main ()
{

     int arr[] = { 10 , 5 , 2  , 3 , 6} ;
     
     int n = 5 ;

     int idx = n -1 ;
     
     int target_sum = 8 ; 

     cout << get_subset_sum( arr  , idx , 0 , target_sum ) ;
     
}