#include<bits/stdc++.h>
using namespace std;

int is_present ( int arr[] , int  target  , int n )
{

     int low =  0 ; 

     int high = n -1 ;

     while ( low <= high )
     {
          int mid_idx = ( low + high)/2;

          int mid_val = arr [ mid_idx]; 

          if (   mid_val == target ) return mid_idx;

          bool left_sorted = arr [ low ]  <  mid_val ? true : false ;

          if ( left_sorted )
          {
               if( target >= arr [ low ]  and target < arr [ mid_idx ]) 
               {
                    high =  mid_idx - 1 ;
               }
               else 
               {
                    low = mid_idx + 1 ;
               }
          }
          else
          {
               if ( target  > arr [ mid_idx]  and target <= arr [ high])
                    {
                         low = mid_idx + 1 ;
                    }    
               else 
               {
                    high  = mid_idx -1 ;
               }
          }

     }

     return false ;

}



int main ()
{

     int arr []  = {  10,20,30,40,1,2};

     int n  =  6 ; 

     int res = is_present ( arr ,2  , 6);

     if ( res ) 
     {
          cout << "INDEX OF THE TARGET ELEMENT  = " << res << endl;
     }
     else     
     {    
          cout << " UNABLE TO FIND OUT  THE ELEMENT "<< endl;
     }

     return 0;
}