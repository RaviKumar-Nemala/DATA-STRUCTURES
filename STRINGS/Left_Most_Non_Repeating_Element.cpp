#include<bits/stdc++.h>
using namespace std ;


void left_most_non_repeat_optimal ( string str )
{
     int char_freq[ 256 ] = { -1 };

     for ( int idx = 0; idx < str.length () ; idx ++ )
     {
          if( char_freq[str[ idx]] == 0 )
          {
               char_freq[ str[ idx ]] = idx;
          }
          else //when the char appeared more then once simply place it with negative values
          {
               char_freq[str[idx]] = -1;
          }
     }

     int res = INT_MAX;

     for( int idx = 0 ; idx< 256 ; idx ++)
     {
          if( char_freq [ idx ] > 0 )//>0 means those chars are appeared only once we need to find the min idx amont them
          {
               //char_freq[idx] holds the index of the char in the string str
               res = min( res , char_freq[ idx ]) ;
          }
     }

     cout << str[res] << endl;
     
}


void left_most_non_repeat( string str )
{
     int char_freq[ 256 ] = { 0 };

     for ( int idx = 0; idx < str.length () ; idx ++ )
     {
          char_freq [ str[  idx ] ]++;

     }

     //non repeating char frequency is going to be the one 
     for ( int idx = 0 ; idx < str.length (); idx ++)
     {
          if ( char_freq [ str[ idx ] ] == 1)
          {
               cout << str[idx] << endl;
               return;
          }
     }

     cout <<"ALL ARE DUPLICATE NO UNIQUE ELEMENT" << endl;
}


int main ()
{
     string arr = "abbccda";

     left_most_non_repeat_optimal( arr ) ; 

     return 0;
}