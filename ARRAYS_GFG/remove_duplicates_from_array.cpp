#include<bits/stdc++.h>
using namespace std ;

void print_val ( int arr[]  , int n )
{
     for (  int i = 0 ; i < n; i ++ )
     {
          cout << arr [ i  ]<<" " ; 
     }
     cout << endl;
}

//the given array must be sorted
int remove_duplicates( int arr [] , int n )
{

     //this result value is the size of the unique elements found 
     // res-1 points to the idx of the last unique value
     int res = 1 ; 

     for ( int idx = 1 ;idx < n ; idx ++ )
     {
          if ( arr[ idx ]  != arr[  res -1] )
          {
               arr[ res ] = arr[ idx] ;
               res++;
          }
     }

    return res; 
}



int main ()
{
     int arr[] = { 10,20,20,30,40};

    int unq_size=  remove_duplicates (arr ,5);

     print_val( arr , unq_size) ;
     return 0;
}