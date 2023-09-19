#include"tree_config.h"

int find_ceil(vector < int > arr , int low, int high , int target)
{


     int res = INT_MAX;

     while ( low <= high )
     {

          int mid = ( low + high ) /2 ;

          int current_ele =  arr [ mid ] ;

          if ( current_ele == target )
          {    
               res = mid ;
               break;
          }
          
          // store the nearest greater element from the target element

          else if ( current_ele > target )
          {
               
               res =  mid ;
               
               high =  mid - 1 ;

          }

          else
          {
               
               low = mid  + 1 ;

          }

     }

// it returns the index of the ceil element for the given 
     
     return res ;

}




int main ( char ** argv, int a)
{

     vector < int >  arr = { 1 , 2  ,3 , 5 , 8 , 9 } ;

     int target =  9;
    
     int res = find_ceil ( arr , 0 , arr.size() -1 , target ) ;
      if ( res != INT_MAX ){
     cout <<" CEIL OF THE GIVEN ELEMENT :"<< arr[ res ] << endl;
      }
      else{
          cout <<" CEIL OF THE ELEMENT IS NOT EXISTED "<< endl;
      }

     return 0 ;
}