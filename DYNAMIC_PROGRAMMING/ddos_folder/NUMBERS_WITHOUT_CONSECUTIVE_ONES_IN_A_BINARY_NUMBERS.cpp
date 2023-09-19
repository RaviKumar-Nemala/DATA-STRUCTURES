#include<bits/stdc++.h>
using namespace std;
class Solution 
{
      public  : 
       int count_of_non_consectutive( int n )
       {
            return count_util(n);
       }
       int count_util( int n ){
          if ( n == 0 )
          return 0;
          else if( n == 1)
          {
               return 2 ;
          }
          else if( n == 2 )
          return 3 ;
        
          return count_util(n-2)+count_util(n-1);
       }
};

int main(){
     int n = 4 ;
     Solution obj ; 
     cout<< obj.count_of_non_consectutive(n);
}