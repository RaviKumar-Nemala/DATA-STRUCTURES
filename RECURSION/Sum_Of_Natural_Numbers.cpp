#include<bits/stdc++.h>
using namespace std ;


int  get_sum ( int n )
{
     if(  n== 0 )   return 0 ;

     int temp = get_sum ( n -1 ) ;

     return  n+ temp ;

}

int main ()
{

     cout << get_sum ( 3 ) << endl;

     return 0 ;
}