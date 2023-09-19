#include"tree_config.h"

int min_differ ( vector < int > arr , int low , int high , int key )
{

     int difference = INT_MAX;

     while ( low <= high )
     {

          int mid = ( low + high )/2 ;

          int mid_val = arr [ mid ] ;

          // if the key is found then min_differ= key - key = 0;
          if ( mid_val == key )
          {
               difference = 0;
               break;          
          }
          if ( mid_val > key )
          {    
               high = mid - 1 ;

          }
          else{
               low = mid + 1 ;
          }

     }
          // if key is not found min _differ of the key will be in range of the arr [ high] , arr [ low ]
          //among arr  [ high ] , arr [ low ] ,which ever gives the minimum differnce then it will returned
     if ( difference !=0 )
     {
          difference  = min( abs ( arr [ high] - key )  , abs (arr[  low ] - key ) );

     }
     return difference ;
     


}

int main ()
{

vector < int > arr = {  1, 6 , 9 , 10 ,12 , 14 } ;

int key =  5;

cout << min_differ ( arr , 0 , arr.size() - 1 , key ) ;


return 0;


}