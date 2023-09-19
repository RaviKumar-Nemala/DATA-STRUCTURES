#include<bits/stdc++.h>
using namespace std ;

bool is_match ( string str1 , string str2 )
{
     if( str1.length()  != str2.length())    return false;

     /**
      * APPROACH =  concatinate first string with itseleft 
      *let str1  = "ababc"
      *  str1 = str1 + str1 
      *
      *  str1 = "ababc" + "ababc" ;
      * 
      * str1 = "ababcababc" ;
      * 
      * now match the str2 with str1 if is found then we return true
      * else return false 
      *
      */
     str1 = str1 + str1 ;

     if( str1.find( str2 ) != str1.npos)
     {
          return true;
     }
     else 
          return false;
}


int main ()
{

     string str1 = "ababc";

     string str2 = "abcab";

     if ( is_match( str1 , str2 ))
     {
          cout <<"MATCH FOUND AFTER ROTATION OF STRING EITHER IN CLOCK OR ANTICLOCK WISE";
     }
     else
          cout <<"MATCH NOT FOUND "<< endl;

/**
 * str1  = ababc ->after 1st rotation = babca  -> second rotation = abcab 
 * 
 * after rotating the str on the 2 time in left we get value = abcab which is equal to the str2  
 *  
 * same thing applies to the right side rotation too 
 * 
 */

     return 0;
}