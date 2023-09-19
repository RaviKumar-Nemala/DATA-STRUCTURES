#include<bits/stdc++.h>
using namespace std;


int get_no_of_occr ( int arr[]  , int  low ,int high )
{

     int n =  high + 1;  

     while ( low <= high)
     {
          int mid_idx = ( low + high )/2;
    
          int mid_val = arr [ mid_idx];

          if (mid_val == 0 )
               low =  mid_idx + 1;

          else if(mid_idx == 0 ||  mid_val  !=  arr [ mid_idx -1 ]) 
          {
               return ( n -  mid_idx );
          }         
          else 
          {
               high =  mid_idx -1;
          }

     }

     return -1;

}



int main () 
{
     int arr[] = { 0 , 0 , 0 , 1 ,1,1,};
     
     int low = 0 , high = 5 , target =  1;

     int res = get_no_of_occr(arr , low , high);

     if ( res != -1 )
     {
          cout<<"NO OF OCCURANCES "<< res << endl;
     }
     

     return 0;
}