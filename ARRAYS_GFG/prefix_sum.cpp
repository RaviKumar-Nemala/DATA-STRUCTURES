#include<bits/stdc++.h>
using namespace std ;

int get_sum ( int arr[] , int  start , int end )
{
     int sum = 0 ;

     for ( int idx =  start  ; idx <= end; idx++ ) 
     {
          sum += arr [ idx ]  ;
     }

     return sum ;
}


int main ()
{
     int arr[]  = { 1 ,2 ,3, 4, 5, 6  } ;

     cout << get_sum( arr , 0 , 2 ) << endl;

     cout << get_sum( arr , 1 , 3 ) << endl;

     cout << get_sum ( arr , 2 , 4 ) << endl;

     return 0;
}