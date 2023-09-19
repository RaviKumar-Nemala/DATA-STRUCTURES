#include<bits/stdc++.h>
using namespace std;

int lamuto_partition ( int arr[]  , int low , int high)
{
     //according to this partition it takes the pivot element as the last  element 
     //it shifts the elements which are lesser then the pivot element on the left side
     //it shifts the elements which are greater then the pivot element on the right side

     int pivot = arr [ high ] ;
     int  i   = -1 ;
     for( int j  = low ; j <=high-1 ;j ++ )
     {
          if ( arr[j] <= pivot)
          {
               i++;
               swap( arr[ i ] , arr[ j ]);
          }
     }

     swap( arr [ high ] ,  arr[i+1]);

     return  ( i +1 ) ;
}

void print_val (int arr[] , int n )
{
     for ( int idx = 0 ;idx < n ; idx++ )
     {
          cout << arr [ idx ] <<" " ;
     }
     cout << endl;
}

int main ()
{
     int arr[] = { 10,80,30,90,40,50,70};

     cout <<"BEFORE PARTITIONING" << endl;
     print_val (arr , 7 );
     lamuto_partition(arr , 0,6);
     cout << "AFTER PARTITIONING"<< endl;
     print_val( arr, 7 );
     return 0;
}