#include<bits/stdc++.h>
using namespace std ;

void print_val ( int arr [] , int n )
{
     for ( int i  = 0 ; i  < n ; i ++ )
     {
          cout  << arr [ i ]  << " " ; 
     }
     cout << endl; 

}

void solve (  int arr[]   , int n  )
{

     for ( int i = 0 ; i < n ; i  += 2 )
     {
          int j = i + 1 ;               
          if ( j >= n )
          {
               break;
          }

          swap ( arr [ i ] ,  arr [ j ] ) ; 

     }

     print_val ( arr, n ) ; 
}



int main ()
{
     int arr [] = { 1 ,2, 3, 4 , 5 };

     int n = 5 ; 
     solve( arr , n );
     return 0 ;
}