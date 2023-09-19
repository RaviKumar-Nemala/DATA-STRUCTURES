#include<bits/stdc++.h>
using namespace std ;

int is_valid ( int arr  [] , int n , int k , int max_pages ) 
{
     int sum = 0 ; 
     
     int i ; 
     int no_of_stu  = 1 ; 
     for ( i = 0 ; i < n ; i ++ )
     {
          sum += arr [ i ] ; 

          if  ( sum  > max_pages )
          {
               no_of_stu ++;
               sum = arr [  i ] ; 
               if ( no_of_stu > k )
               {
                    return false; 
               }
          }
     }
     if ( no_of_stu > k )
     {
          return false ;
     }
     else 
     {
          return true;
     }
}
int get_total ( int arr  [] , int n ) 
{
     int sum = 0 ;

     for ( int i = 0 ; i < n ; i ++ ) 
     {
          sum += arr [ i ] ; 
     }
     return sum ;

}


int solve ( int arr[]  , int n  , int  k )
{    

     int total =  get_total ( arr , n ) ;


     int low = 0 ; 

     int high = total ;

     int min_pages = INT_MAX;
     while (  low <= high )
     {
          int mid_val = ( low + high ) /2 ;
          
          if ( is_valid (  arr ,  n , k ,  mid_val)) 
          {
               min_pages = min ( min_pages,  mid_val ) ; 
               high =  mid_val  -1 ;
          }
          else 
          {
               low =  mid_val + 1 ; 
          }

     }

     cout << min_pages << endl;


}
int main()
{

int arr[] = {12,34,67,90};
int  M = 2 ; 
// Output:113
int n =  4 ;
 
     solve (  arr , n , M ) ;

     return 0 ;     
}