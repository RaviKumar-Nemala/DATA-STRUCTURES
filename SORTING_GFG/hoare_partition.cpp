#include<bits/stdc++.h>
using namespace std ;


int hoare_partition( int arr[]  , int low , int high )
{

     int  i =  low -1 ;
     int  j = high +1 ;
     int pivot = arr [low]; //assuming the  first element is the pivot element 

while ( true ) {
     do 
     {    
          i++;
     }while( arr [ i ] < pivot ); //should not use arr[i]<=pivot it gives wrong results

     do
     {
          j--;
     } while (arr [j ] > pivot);

     if ( i >= j )
     {
          return j;
     }    
     swap( arr[i] , arr[j]);
}

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
     int arr[] = { 5,3,8,4,2,7,1,10};
     int n = 8;
     int idx = hoare_partition(arr,0,n-1);
     cout << idx <<endl;
     print_val(arr , n);

     return 0;
}