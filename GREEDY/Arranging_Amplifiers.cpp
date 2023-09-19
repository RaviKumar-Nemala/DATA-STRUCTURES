#include<bits/stdc++.h>
using namespace std ;



int main () {
     int  t; 
     cin >> t ;
     while ( t--)
     {
          int n  ;
          cin >>  n;
          vector< int > arr ;
          int ones = 0 , idx = 0 ;
          for ( idx = 0 ; idx < n ; idx ++ )
          {
               int  ele ;
               cin >> ele ;
               arr.push_back (  ele );
               if ( ele == 1 )     
                    ones ++;
          }
          sort( arr.begin ()  , arr.end() , greater<int> () );
          for( idx = 0  ; idx < ones ; idx ++ )
               cout <<  "1 ";
          
          if( (n-ones) == 2 and  arr [ 0 ] == 3 and  arr [1 ] == 2 )
          {
               cout << "2  3 ";
          }
          else 
          {
               for (idx = 0 ; idx < ( n - ones ) ; idx ++)
                    cout <<  arr [ idx ] << " " ; 
          }cout << endl;
     }

     return 0;
}