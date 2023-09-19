#include"tree_config.h"

int get_index ( vector < int > arr  , int target )
{

     int low = 0 ; 
     int high = 1;

     while ( arr [ high ] < target)
     {

          low = high ;

          high = high * 2 ;

     }

     int first_occurence_idx = -1 ;

     while ( low <= high )
     {

          int mid = ( low + high ) / 2;

          if ( arr [ mid ] ==target )
          {
                    first_occurence_idx = mid ;
                    high = mid - 1 ;
          }
          if ( target > arr[ mid ] )
          {
               low = mid + 1 ;
          }
          else
               high = mid - 1 ;
     }

     return first_occurence_idx ;

}

int main ( )
{

// assuming it is a infinite array 

// we need to find the first occurrence index of the element  1 in this infinite array

vector < int > arr = {  0 , 0 , 0 , 0 , 0 , 1 ,1, 1, 1 ,1 } ;

int target= 1 ;

int res = get_index ( arr ,  target );

if ( res != -1 )
{
     
     cout<< "INDEX OF THE FIRST OCCURENCE OF THE ELEMENT 1 = "<< res << endl;

}
else
{
     cout<<" INDEX IS NOT FOUND  "<< endl;

}
return 0 ;

}