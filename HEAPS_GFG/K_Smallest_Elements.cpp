#include<bits/stdc++.h>
using namespace std;


void k_smallest_elements( int arr[] , int n , int k)
{

     priority_queue< int  > max_heap;

     int i = 0 ; 

     for( i  = 0 ; i < k ; i ++)
     {
          max_heap.push ( arr [ i ] ) ;
     }

     for ( i =  k ; i < n ;i ++  ) 
     {
          int curr_val  = arr [  i ];

          if ( curr_val  < max_heap.top() )
          {
               max_heap.pop () ;
               max_heap.push ( curr_val);
          }

     }

     while ( !max_heap.empty())
     {
          cout<< max_heap.top( ) <<" " ;
          max_heap.pop();
     }
     cout <<endl;
     return;
}

int main ()
{
     int arr[] = { 10 , 5 , 13 , 12 , 15};

     int  k =  2 ;

     k_smallest_elements ( arr , 5 , k );

     return 0;
}