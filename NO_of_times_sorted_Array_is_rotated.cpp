#include"tree_config.h"

int get_no_of_rotations ( vector< int > arr , int low ,int high )
{
     int n  = high + 1 ;

     int no_of_rotations = 0;

     while ( low <= high )
     {
          int mid_idx = ( low + high)/2 ;

          cout << mid_idx << endl;

          int current_ele = arr [ mid_idx ] ;

          int next_val_idx = ( mid_idx + 1 ) %n ;

          int prev_val_idx =  ( mid_idx + n - 1  ) % n ;

          int next_val = arr [ next_val_idx ];

          int prev_val = arr [ prev_val_idx ];

          // if it is the pivot element where left side of this element is one sorted region
          
          // and the right side of this element is another sorted region

          if ( current_ele < prev_val and current_ele < next_val )
          {
               
               cout << mid_idx << endl;

               no_of_rotations = mid_idx ; 
               
               break     ;

          }
          
          //check right if the right side of the mid is sorted it it is then go to left part from the mid_ idx 

          else if ( current_ele < arr [ high ] )
          {high = mid_idx - 1 ;
          }

          // if the left part of the mid_idx is sorted then go to the right side 

           else if ( current_ele > arr [ low ]  )
          {
               low = mid_idx + 1 ;
          }

     }

     return no_of_rotations ;
}


int main ()
{

     vector < int > arr = { 8 ,  11 , 15 , 18 , 2 ,3 , 4,  5 } ;



     int temp = get_no_of_rotations ( arr , 0 , arr.size() - 1  ) ;
     cout << temp ;
     {
          cout <<" NO OF ROTATIONS :  "<< temp << endl;
     }
     

     return 0;



}