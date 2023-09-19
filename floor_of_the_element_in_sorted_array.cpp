#include"tree_config.h"


int find_floor (  vector < int > arr , int low,  int high , int target  )
{

     int res = INT_MIN ;

     while ( low <= high )
     {

          int mid_idx = ( low + high )/2 ;

          int current_ele =  arr [ mid_idx ] ;

          if ( current_ele == target )
          {
               res =  mid_idx ;
               break;
          }

          else if ( current_ele < target )
          {
               low = mid_idx+ 1 ;
               
               res = mid_idx ;

          }

          else if ( current_ele > target )
          {
               high = mid_idx - 1 ;
          }

     }

     return res ;

}

int main ()
{

     vector < int >  arr = { 1 , 2  ,3 , 5 , 8 , 9 } ;

     int target = 6 ; //for 6 nearest floor value =  5 
     // target = 8 // since 8 is already existed then floor value is also = 8 
     
     // if the target is not in the arr[] then floor will point nearest smallest element for the given target element

     int res = find_floor ( arr , 0 , arr.size() - 1 , target ) ;
     
     // res will store the idx value of floor value for the given elment 

     cout<< "FLOOR VALUE "<<arr [ res ] << endl;

     return 0 ;
}