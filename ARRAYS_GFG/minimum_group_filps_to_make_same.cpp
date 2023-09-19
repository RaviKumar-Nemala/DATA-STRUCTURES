#include<bits/stdc++.h>
using namespace std ;
 
int get_min_flips ( int arr[]  ,int n  ) 
{
     //APPROACH THE SECOND GROUP OF ELEMENT EITHER HAVE LESSER ELEMENTS THEN THE FIRST GROUP OR THE EQUAL ELEMENTS
     //SO WE SIMPLY FLIP ALL THE SECOND GROUP ELEMENTS

     int target_val = -1;
     int first_val = arr [  0] ;

     for ( int idx = 1 ; idx <  n ; idx ++ ) 
     {
         int curr_val  = arr [ idx ] ;
          
          int prev_val = arr [ idx -1 ] ;
     
          if ( curr_val  != prev_val )//helpful for finding the group
          {
               if ( curr_val != first_val )//helpful fo comparing with the first element
               {
                    cout <<"FROM " << idx<< " TO ";
               }
               else 
               {
                    cout <<"TO " << idx -1 << endl;//this line will be printed when we meet the new element after the  same group
               }
          }

     }

     //if the last elment is different element then  the above loop print only ( FROM IDX   TO IDX IS  NOT GOING TO BE PRINTED )
     if( arr[ n -1 ] != arr[ 0 ] )
     {
          cout<<" TO "<< n -1 << endl;
     }


}


int main ( )
{
     int arr[] = {  1 ,1 , 0 , 0 , 0  , 1 , 0 , 0 , 1  } ; 
     int n   = 9 ; 
     get_min_flips( arr , n ) ;
     return 0 ;
}