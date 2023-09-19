#include<bits/stdc++.h>
using namespace std;

int get_sqrt_optimal ( int target)
{
     
     if ( target == 1 )  return 1 ; 

     int low = 1  , high = target;

     int res = -1; 

     while ( low <= high ) 
     {    
          int mid_val = ( low + high )/2; 
          
          int mid_square = mid_val * mid_val;

          if ( mid_square <= target)
          {
               res =  mid_val;
               low = mid_val + 1 ;               
          }    
          else 
          {
               high  = mid_val -1;
          }

     }    
     return res;

     
}



int get_sqrt_naive( int target)
{

// let result = sqrt(target) => result*result =  target;
//then find the largest result value whose squre is lesser then the target value

if( target ==  1)   return 1 ;

int i =  1 ;

while ( i * i  <= target)
{
     i = i+1;

}

return i-1 ;

}

int main () 
{    
     int res = get_sqrt_naive( 10 ) ;

     res  = get_sqrt_optimal ( 16 );

     cout << res << endl;

     return 0;
}