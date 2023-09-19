#include<bits/stdc++.h>
using  namespace std;


vector< int > k_largest(  int arr[]  ,  int n  , int k)
{
     priority_queue<int  , vector<int > , greater<int > >  min_heap;

     for ( int idx = 0 ; idx < k ; idx ++ )
     {
          min_heap.push ( arr [idx ])  ;
     }

     for ( int idx = k; idx < n ; idx ++)
     {
          int curr_val = arr [ idx ];
          if ( curr_val > min_heap.top())
          {
               min_heap.pop();
               min_heap.push( curr_val);
          }
     }

     while ( !min_heap.empty())
     {
          cout << min_heap.top( )<<" " ;
          min_heap.pop();
     }


}


int main ()
{

     int arr[] = { 10 , 5 , 13 , 12 , 15};

     int  k =  2 ;

     k_largest(arr ,5 , k);


     return 0;
}