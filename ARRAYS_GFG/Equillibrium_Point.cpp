#include<bits/stdc++.h>
using namespace std ;

int get_total_sum ( int arr[] , int n )
{
     int sum = 0 ;
     for( int idx = 0 ; idx < n ;idx++ )
          sum += arr[  idx] ; 
     return sum ;
}

bool is_equi_existed (int arr[] , int n )
{
     int total_sum  = get_total_sum ( arr , n ) ;

     int before_sum = arr[  0  ];

     for ( int idx = 1 ; idx <  n ;idx ++ )
     {
          int curr_val = arr[ idx ] ; 

          int after_sum =  total_sum - before_sum -  curr_val ;

          if ( after_sum  == before_sum )
          {
               cout<<"EQUILLIBRIUM POINT FOUND = "<< curr_val << endl;
               return true;
          }

          before_sum += curr_val;
     }    

     return false ;

}


int main ()
{
     int arr [] = { 3 ,4, 8 , -9  , 20 ,6 } ;

     int n = 6 ;

     cout<< is_equi_existed( arr, n ) << endl;

     return 0 ;
} 