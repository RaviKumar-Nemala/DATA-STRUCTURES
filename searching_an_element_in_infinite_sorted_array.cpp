#include"tree_config.h"



int find_element( vector < int > arr , int target )
{
     int low = 0 ;

     int high = 1 ;

     // this loop will be stop once the given target element will be the range of the low and high

     while (  arr [ high ] < target )
     {
          low = high ;
          high = high*2;
     
     }

     cout <<" ELEMENT IS IN THE RANGE OF THE ( "<< arr [ low ] << "  , "<< arr[ high ] <<" )"<< endl;

     // once target is in the range then find its exact position

     while ( low <= high )
     {

          int mid=  ( low + high )/ 2;

          if ( target == arr [ mid ] )
          {
               return mid ;
          }
          if ( arr[ mid ] > target )
          {
               high = mid - 1 ;
          }
          else
          {    
               low = mid + 1 ;
          }

     }

     return INT_MAX;

}

int main () 
{


     // let us asume this is infine array
     vector < int > arr =  { 1 , 5 , 9 ,  8 , 10 , 12 , 88 , 99 };

     int target = 12 ;

     int res = find_element ( arr ,target  );

     if ( res != INT_MAX )
     {

          cout <<"ELEMENT IDX = "<< res << endl;

     }
     else{
          cout <<" ELEMENT IS NOT FOUND "<< endl;
     }
     return 0 ;
}