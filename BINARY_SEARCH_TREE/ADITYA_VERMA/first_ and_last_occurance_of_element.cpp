#include "tree_config.h"


int res ;

int get_occurence ( vector < int>nodes , int target , int low ,int end )
{

     while ( low < end )
     {

          int mid_idx = low + ( end - low )/2 ;

          int curr_ele = nodes [ mid_idx ] ;

          if ( curr_ele == target  )
          {

               res =  mid_idx ;

               end = mid_idx - 1 ;//for finding the first occurence

               // start = mid_idx + 1 ;// for finding the  last occurence
               
          }
          
          if( curr_ele < target)
          {

               low = mid_idx + 1 ;

          }
          else{

               end = mid_idx - 1 ;

          }    
          
     }

     return res ;

}

int main ()
{

     vector < int >  arr  = { 1 , 2 , 3 , 5 , 5,  8 , 9 };

     int target = 5 ;

     cout <<"LEAST OCCURENCE OF THE ELEMENT : " << get_occurence ( arr , target , 0 ,arr.size() -1 ) ;

     return 0;

}