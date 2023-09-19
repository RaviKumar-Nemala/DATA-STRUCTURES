#include<bits/stdc++.h>
using namespace std ;

void print_val ( vector<int> arr  , int in )
{
     for ( auto  it : arr )   
          cout << it<<  " " ; 
     cout<< endl; 
     return;
}
int get_max_water  (  int arr []  , int  n )
{
     //used to find the max element on the left side of the current element 
     vector < int > prefix ( n ) ;
     
     int idx = 0 ; 
     int max_val =  arr [  0 ] ; 
     prefix[  0 ] = arr [  0 ] ; 
     for ( idx = 1 ; idx < n ; idx ++)
     {          
          prefix [ idx ] =  max_val ;

          max_val = max (max_val ,  arr[  idx ]) ;  
     } 

     print_val( prefix , n);

}


int main ()
{
     int arr[]  = { 3,0,1,2,5};
     int n = 5 ; 
     get_max_water( arr , n ) ; 

     return 0;
}