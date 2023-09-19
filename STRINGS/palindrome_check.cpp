#include<bits/stdc++.h>
using namespace  std ;

bool is_palindrome( string str ) 
{
     int low = 0 ; 

     int high  = str.length() -1 ;

     while ( low < high )
     {
          if(  str.at( low) != str.at(high))
          {
               return false;
          }
          low ++;
          high --;
     }
     return true;
}

int main ()
{
     string str = "helllleh";
     if(is_palindrome( str )) 
     {
          cout <<"PALINDROME"<< endl;
     }   
     else 
     {
          cout <<"GIVEN STRING IS NOT A PALINDROME"<< endl;
     }

     return 0;
}