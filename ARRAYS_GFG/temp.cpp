#include<bits/stdc++.h>
using namespace std;

void find_fab ( int n ){
     if ( n == 1 )
     {
          cout << 0 <<endl;
     }
     else if( n == 2 )
     {
          cout << 1 << endl;
     }
     else 
     {
          int count = 2 ;
          int a = 0 ;
          int b = 1 ;
          
          while ( count < n )
          {
               int c = a +b ;
               count ++;
               if ( count == n )
               {
                    cout << c << endl;
                    break;
               }
               a = b ;
               b = c; 
          }
     }
}



int main ()
{
     int n;

     cin >> n ;

     find_fab( n );

     return 0;
}