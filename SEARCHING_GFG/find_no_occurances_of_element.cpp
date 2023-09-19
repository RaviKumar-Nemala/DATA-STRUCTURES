#include<bits/stdc++.h>
using namespace std;

int get_first_occr ( int arr[]  , int target , int low,  int high)
{
     int first_occr = INT_MAX;

     while ( low <= high)
     {
          int mid_idx = ( low + high )/2;

          int mid_val = arr [ mid_idx ] ; 

          if ( target == mid_val)
          { 
               if (  mid_idx <   first_occr )     
                    first_occr =  mid_idx;
          }

          if ( target <= mid_val )
          {
               high =  mid_idx -1 ; 
          }
          else 
          {
               low = mid_idx  + 1;
          }
     
     }

     return first_occr;


}

int get_last_occr ( int arr[] , int target , int low, int high )
{

     int last_occr = -1;

     while ( low <= high)
     {
          int mid_idx = ( low + high )/2;

          int mid_val = arr [ mid_idx ] ; 

          if ( target == mid_val)
          {      
               last_occr =  mid_idx;
          }

          if ( target < mid_val )
          {
               high =  mid_idx -1 ; 
          }
          else 
          {
               low = mid_idx  + 1;
          }
     
     }
     return last_occr;

}


int main () 
{
     int arr[] = { 1 ,2 ,2 , 8 , 8 ,8 };
     
     int low = 0 , high = 5 , target =  8;

     int  first_occ = get_first_occr( arr , target ,low , high);

     if ( first_occ != INT_MAX)
     {
          int last_occr =  get_last_occr ( arr , target , low , high);
     
          int no_of_occurances = ( last_occr - first_occ) +1;

          cout <<"PRINTING THE NO OF OCCURANCES = " << no_of_occurances << endl;
     }    
     else 
     {
          cout <<"UNABLE TO FIND THE NO OF OCUURANCES "<< endl;
          cout <<"ELEMENT IS NOT FOUND "<< endl;
     }
     return 0;
}