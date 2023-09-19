#include<bits/stdc++.h>
using namespace std ;

void display( int arr[] , int n )
{
     for ( int i  = 0 ; i < n ;i ++ )
     {
          cout << arr [ i ] << " " ; 
     }
     cout << endl;
}

void k_sort_array ( int arr[] , int n , int k )
{
     priority_queue < int , vector < int >  , greater < int > > min_heap ; 

     //tc = O(klogk)
     for ( int idx = 0 ; idx <=k ; idx++)
     {
          min_heap.push( arr [ idx ] ) ; 
     }

     int index = 0;

     //tc =O((n-k)(logk))
     for (  int idx = k + 1 ; idx < n ;idx ++ ) 
     {
          arr[ index ++] =  min_heap.top();
          min_heap.pop();
          min_heap.push( arr [ idx ]) ;
     }

     //tc = O(klogk)
     while ( !min_heap.empty() ) 
     {
          arr[index ++] =  min_heap.top();
          min_heap.pop();
     } 

     //overall tc is O(klogk) + O(n-k)logk + O(klogk) = O(N +kLOGK)
     display( arr , n);

}

int main ()
{
     int k = 2 ; 
     
     int arr [] = { 9,8,7,19,18};

     k_sort_array ( arr ,5 , k ) ;

     return 0 ;
}