#include<bits/stdc++.h>
using namespace std;


void k_closest_elements ( int arr[] , int n , int k  , int ele)
{
     int idx = 0 ;

     priority_queue < int > max_heap ; 

     for ( idx = 0 ;idx < k ; idx ++)
     {
          // int abs_differ =  abs( arr [ idx ] - ele );
          max_heap.push ( arr [ idx ] ) ; 
     }
     
     for ( idx = k ; idx < n ; idx ++ )
     {
          int curr_abs = abs ( arr [ idx ] -   ele) ; 

          int existed_differ  = abs ( max_heap.top() - ele) ; 

          if ( curr_abs  < existed_differ) 
          {
               max_heap.pop();
               max_heap.push( arr[idx]);
          }

     }
     while ( !max_heap.empty())
     {
          cout<< max_heap.top()  <<  " " ; 
          max_heap.pop();
     }
     
     cout << endl;

     return;

}

int main ()
{

     int arr[] = { 10 , 5 , 13 , 12 , 15};

     int num  =  10 ;

     int k = 3 ;

     k_closest_elements ( arr , 5 , k , num ) ;
     
     return 0;
}