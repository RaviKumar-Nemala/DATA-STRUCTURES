#include<bits/stdc++.h>
using namespace std ;

int get_normal_sub_arr_sum ( int arr [] , int n ) 
{
     int max_sum = INT_MIN;

     for( int idx = 0 ; idx < n ;idx ++ )
     {
         int sum =  0 ;
          for ( int j  = idx ;  j < n ; j ++)
          {
               sum += arr[  j ] ;
               if (  sum >  max_sum )
                    max_sum = sum;
          }

     }
     return max_sum;     

}

int get_max_sum ( int arr []  , int n )
{
     int res = INT_MIN;

     int nrml_sub_arr_max_sum = get_normal_sub_arr_sum ( arr , n ) ; 

     // if our normal sub arr sum is -ve means no element is +ve in the array
     // then simply return then max element no need to do the cirucular fassion
     if ( nrml_sub_arr_max_sum < 0 )
     {
          return nrml_sub_arr_max_sum ; 
     }

     int arr_sum = 0 ;

     for ( int idx = 0 ; idx < n ; idx ++ )
     {
          arr_sum += arr [ idx ] ;
          arr [ idx ] = - arr[ idx ] ; //helpful for finding the min_subarr sum in circular arr ( reference = gfg selfpaced)
     }
     /**
      * inorder to obtain the max sub array sum in the circular array  initially we find the total sum of the all elements in the array 
      * then toggle +ve and -ve values 
      * then find the max_sub arr sum in that 
      * obtained max_sub_arr sum become the minimum sub arr sum( because we changed the toggle the +ve and the -ve values)
      * then add the minimum  sub arr sum to  array sum then we get  the max_sub arr sum in the cirular array 
      */

     int circular_sub_arr_max_sum = arr_sum  +   ( get_normal_sub_arr_sum ( arr ,  n ) ) ; 

     res =  max (nrml_sub_arr_max_sum , circular_sub_arr_max_sum ) ;

     return res;

}


int main ()
{
     // int arr[]  = { 5,  -2 , 3 , 4} ;
     int arr[] = { 2,3,-3};

     int n = 3 ;

     cout<<get_max_sum ( arr , n ) << endl;

     return 0 ; 
}