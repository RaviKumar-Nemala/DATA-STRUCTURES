#include<bits/stdc++.h>
using namespace std ;


bool is_anarglams( string  str1 , string str2 )
{
     int char_freq[256] = { 0 } ;

     if( str1.length() != str2.length() )
          return false;
     
     for ( int idx = 0 ; idx < str1.length() ; idx ++ ) 
     {
          char_freq [ str1[idx] ] ++;
          char_freq [ str2[idx]]--;
     }

     for( int idx = 0 ; idx < 256 ; idx ++){
          if( char_freq[ idx ] != 0)    return false;
     }

     return true;
}



int main ()
{

     //ANARGLASM ARE THE TWO STRING WHICH ARE THE SAME ELEMENTS AND THE FREQUENCIES OF THOSE ELEMENTS
     // BUT ORDER IS DIFFERENT

     string str1 = "aabca";
     string str2 = "acaba";

     if( is_anarglams( str1 , str2 ))
     {
          cout <<"BOTH ARE ANARGLAMS "<< endl;
     }
     else{
          cout <<"STRINGS ARE NOT ANARGLAMS"<< endl;
     }
     return 0;
}
