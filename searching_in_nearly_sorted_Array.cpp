#include"tree_config.h"

int find_idx_of_element_is_nearly_sorted_array ( vector < int >arr ,int target ,  int start , int end)
{

     int target_element_idx = INT_MIN;

     while ( start <= end){

     int mid = ( start + end ) /2 ;

     int current_ele = arr [ mid ] ;

     if ( current_ele == target )
     {
          target_element_idx =  mid;
     }
               // mid- 1 used to  when mid == 0 then mid -1 will be over flow 
               // over flow not happens so need to check that condition

     else if( (mid-1) <= start and target == arr [ mid - 1 ] ) 
     {
          
          target_element_idx =  mid -1 ;

     }
          //mid_+ 1<= end will be used when mid== end then mid+ 1 will be over flow case
          
    else if ( mid + 1 <= end  and target ==arr [ mid  + 1 ]  )
     {
           target_element_idx =  mid + 1 ;

     }

     if ( target < current_ele )
     {
          end = mid - 2 ;
     }
     else
          start = mid + 2;
     

}

     return target_element_idx ;

}
int main () 
{
/*
     // sorted rotated array in the sense sorted array is slightly interchanged 
     // which means the element at position is at ith location or i-1 th location
     //or the i+ 1 th location
     vector < int > arr = { 1 , 2 , 6 , 5 , 7 , 9 };

     int temp  = find_idx_of_element_is_nearly_sorted_array (arr , 5 , 0 , arr.size() - 1 ) ;

     if ( temp != INT_MAX )
     {
          cout <<" ELEMENT FOUND : INDEX =  "<< temp << endl;
     }
     else
     {
          cout <<" element is not found "<< endl ;
     }

*/
     vector < int  > arr = { 1  ,22 , 3 ,5 , 6 } ;

     auto it = find ( arr.begin() , arr.end (), 5);

     cout << ( it - arr.begin () ) << endl;

     return 0 ;

}