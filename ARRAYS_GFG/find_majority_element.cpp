#include<bits/stdc++.h>
using namespace std ;

int get_majority_element_optimal( int arr[] , int n )
{ 
     int count = 1 ;
     int res_idx =  0 ; 
     
     /**
      * IN THE FIRST LOOP 
      * WE ARE FINDING THE COUNT OF THE MAJORITY ELEMENT 
      *  
      * IN THE SECOND LOOP 
      * WE ARE CHECKING THE FONDED ELEMENT IS THE MAJORITY ELEMENT OR NOT
      */

     for ( int idx  = 1 ; idx < n ; idx++ ) 
     { 
          if ( arr[ res_idx] ==  arr[  idx ])
          {
               count ++; 
          }
          else count -- ;

          if ( count == 0 )   {
               res_idx = idx ;
               count = 1; 
          }
     }    
     
     count = 0 ; 
     
     for ( int idx = 0 ; idx < n ; idx ++ )
     {
          if ( arr [ idx ] == arr [res_idx ])
          {
               count ++;
          }
          if ( count > ( n /2 )  ) 
               return  arr[ idx ] ;
     }

     cout <<" UNABLE TO FIND OUT THE MAJORITY INDEX" << endl;
     
 }

int get_majority_element ( int arr[] , int n ) 
{    
     
     for ( int i = 0 ; i< n ; i ++ )
     {
          int count = 1 ;
          for ( int j = i + 1 ; j  < n ; j ++ )
          {
               if ( arr[ i ] == arr [ j ]   )     count ++ ; 
          }
          if ( count > ( n /2 )  ) {
          return arr[ i ] ; 
          }
     }

     cout << "CANNOT FIND THE MAJORITY ELEMENT  "<< endl;

}

/**
 * majority element is the element which appear more then the ( n /2 ) times in the array
 */
int main ()
{
     int arr [] = {  1 ,2, -1 ,5,5,5,5};

     int n=  7 ;

     cout << get_majority_element ( arr , n ) << endl;

     cout<< get_majority_element_optimal (arr , n ) << endl;

     return 0 ; 
}