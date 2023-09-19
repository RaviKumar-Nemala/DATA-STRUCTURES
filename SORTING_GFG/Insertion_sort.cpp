#include<bits/stdc++.h>
using namespace std;

void  insertion_sort ( int arr[ ] , int n )
{    
     for  (int i  = 1 ; i < n ; i++ )
     {
          int key   = arr [ i ] ;
          int j = i -1 ; 
          while ( j >= 0 and arr[j] > key )
          {
               arr [ j +1 ] = arr [ j ];
               j -- ;
          }

          arr [ j  + 1 ] = key;
     }
}

void print_val ( int arr[] , int n )
{
     for (int idx = 0 ; idx < n ; idx++ )
     {
          cout << arr [ idx ] <<" " ; 
     }
     cout << endl;
     return;
}

int main ()
{
     int arr [] = { 20,15,40,60,10,30};

     cout <<"BEFORE SORTING : "<< endl;
     print_val ( arr , 6 ) ;
     insertion_sort (arr , 6);
     cout <<"AFTER SORTING  : " << endl;
     print_val ( arr ,  6 ) ;
     return 0 ;
}