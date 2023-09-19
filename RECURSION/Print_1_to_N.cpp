#include<bits/stdc++.h>
using namespace std ;


void solve ( int n )
{
     if ( n == 0 )
     {
          return; 
     }
     solve(  n -1 ) ;
     cout << n << endl;
}

void solve_2 ( int n )
{
     if  (  n == 0 )
     {
          return;  
     }
     cout << n << endl;
     solve_2 ( n -1 ) ;
     
}

int main ()
{
     solve( 5 ) ;

     return 0 ; 
}