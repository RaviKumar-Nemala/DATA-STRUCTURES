#include<bits/stdc++.h>
using namespace std; 

void solve( int arr[ ] , int n )
{
     int low  =  0 , mid = 0 ; 
     int high  = n -1 ;

     while ( mid <= high)
     {
          if ( arr[ mid ] == 0 )
          {
               swap( arr [ low ] , arr [ mid ] ) ;
               low ++;
               mid ++;
          }
          else if ( arr[mid] ==1 )
          {
               mid ++;
          }
          else 
          {
               swap ( arr [ high] ,  arr [ mid ]);//only high is decremented here because we don't know element is 1 or 0 so mid has to process the at element again
               high--;
          }

     }

     return;
}

void sort_three_elemenets( int  arr[] , int  n )
{

     solve( arr , n );

     return;

}

void print_val ( int arr[] , int n )
{ 
     for ( int idx = 0 ; idx < n ; idx ++ )  
          cout << arr [idx ] <<" " ;
     cout <<endl ;

     return ;

}
int main ()
{
     int arr[] = {  0 ,1 ,0,2,1,2};
     int n =  6;
     sort_three_elemenets(arr,n);
     print_val ( arr , n ) ;
     return  0 ;
}