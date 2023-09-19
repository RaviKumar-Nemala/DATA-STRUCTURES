#include<bits/stdc++.h>
using namespace std;

int get_sum ( int arr[] , int start, int end)
{
     int sum = 0 ;

     for ( int idx = start ;idx<= end; idx++)
     {    
          sum += arr[ idx];
     }
     return sum;
}

int get_max_sum ( int arr[ ] ,int n , int k )
{
     int sum = 0;
     int max_sum = INT_MIN; 
     for ( int idx = 0 ; idx <( n - k +1 ) ; idx++)
     {
          sum = get_sum( arr , idx , idx + k -1  );    
          max_sum = max( max_sum , sum);
     }
     return max_sum;
}


int get_max_sum_optimal ( int arr[] , int k , int n ) 
{    
     int max_sum   = INT_MIN;

     int sum = 0 ;
     int prev_idx =  0 ;
     for (int idx =  0 ; idx < k ; idx ++ )
     {
          sum +=  arr [ idx ] ; 
     }
     
     max_sum = sum; 

     for( int idx = k ; idx< ( n - k + 1 ) ; idx ++ )
     {

          int curr_val = arr [ idx ] ; 
          sum =  (sum -  arr[ prev_idx ] )+ curr_val ; 
          prev_idx = prev_idx + 1; 
          max_sum = max( sum, max_sum );
     }
     return max_sum ;

}


int main ()
{
     // int arr[] = { 1,8,30,-5,20,7};
     int arr [] = { 5 , -10 ,  6, 90 ,3};
     int n = 5;
     int k  = 2 ; 

     cout << get_max_sum( arr  , n , k )  << endl;
     cout<< get_max_sum_optimal ( arr , k , n ) << endl;
     return 0 ;
}