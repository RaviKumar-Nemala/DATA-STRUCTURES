#include<bits/stdc++.h>
using namespace std ;

int sum_of_digits( int val )
{
     if ( val < 10 )
     {
          return val;
     }

     int rem = val % 10 ;

     val = val /10;

     return rem += sum_of_digits( val ) ; 

}


int main ()
{
     cout << sum_of_digits ( 1234) << endl; 
     
     return 0 ;
}