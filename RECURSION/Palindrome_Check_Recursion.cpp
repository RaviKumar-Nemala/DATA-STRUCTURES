#include<bits/stdc++.h>
using namespace std ;


bool is_palindrome ( int start , int end,  string str ) 
{
     if( start >= end )
     {
          return true ; 
     }

     if( str [ start ] != str [ end ] ) 
     {
          return false; 
     }

     return is_palindrome ( start +1 , end - 1 , str ) ; 
}


int main ()
{
     string str = "abbca";

     cout<<is_palindrome ( 0 ,  3 , str ) ;

     return 0 ;
}