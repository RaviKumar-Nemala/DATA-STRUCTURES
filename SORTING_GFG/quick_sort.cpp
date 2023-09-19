#include<bits/stdc++.h>
using namespace std ;

int lamuto_partition ( int * , int , int ) ;

int hoare_partition ( int * , int , int ) ; 

void qsort( int arr [] , int low , int high)
{
     if ( low < high )
     {
          int partition_index = lamuto_partition( arr , low ,high);

          qsort(arr , low , partition_index - 1 ) ;
          
          qsort( arr ,  partition_index + 1 , high );
     }
     return;
}

int lamuto_partition ( int arr []  , int low , int high )
{
     int i = low -1;

     int j = low ;

     int pivot = arr[high];

     for( j = low ; j <= high-1 ;j ++ )
     {

          if ( arr[ j ] <= pivot )
          {
               i ++;
               swap( arr [ i ] , arr [ j ] ) ;
          }
     }

     swap( arr[i +1 ]  , arr[high]);

     return ( i +1 ) ;
}


int hoare_partition ( int arr[] , int low, int high )
{
     int i = low -1 ;
     int  j= high +1 ;
     int pivot = arr [ low ] ;

while (true){
     do 
     {
          i++; 
     }while(arr[ i ] < pivot);
     
     do
     {
          j--;
     }while ( arr[j] > pivot);

     if ( i >= j )
     {

          return j ;
     }    

     swap( arr[ i ] , arr[j]);

}

}


void print_val( int arr[]  , int n )
{
     for( int idx = 0 ; idx < n ; idx ++ )
     {
          cout << arr[ idx ]<<" " ; 
     }
     cout << endl; 
}

int main ()
{
    
    int n ; 
    cout <<"ENTER THE SIZE OF THE ARRAY : " <<  endl ;
    cin >> n ;
    int arr[n];     

     for (int idx = 0 ; idx < n ; idx ++ )
     {
          cin >> arr[ idx ] ;
     }

     qsort(arr, 0 ,  n-1);
     print_val(arr , n ) ;
     return 0;
}