#include<bits/stdc++.h>
using namespace std ;

void left_by_one (int arr[] , int  n ) 
{
     int temp = arr [ 0 ] ;

     for ( int idx = 1 ; idx < n ; idx ++)
     {
          arr[ idx -1 ] = arr [ idx ] ;
     }

     arr [  n-1] = temp;

}
void print_val ( int arr[] , int n )
{
     for ( int idx = 0 ; idx <n ; idx ++ )    cout<< arr [ idx ] <<" "  ;
     cout<< endl;
}

void left_rotate_by_k ( int arr[] , int n , int k  )
{    
     if ( k >= n )
     {
          k = k % n; 
     }

     while( k--)
     {
          left_by_one ( arr,  n ) ;
     }
     return;
}


void reverse ( int arr[] , int  low , int high )
{
     while ( low < high)
     {    
          swap( arr[ low ]  , arr [ high]);
     }

     return;

}

void left_rotate_by_k_optimal( int arr[]  , int n , int k )
{
     
     reverse( arr , 0 , k-1);
     reverse(  arr , k , n-1);
     reverse ( arr,  0 , n-1);

}

int main ()
{
     int arr[] ={ 5,20,12,20};
     int k = 3; 
     int n = 4;
     // left_rotate_by_k( arr,n , k ) ; 
     left_rotate_by_k( arr,  n , k );
     print_val ( arr , 4);


     return 0;
}