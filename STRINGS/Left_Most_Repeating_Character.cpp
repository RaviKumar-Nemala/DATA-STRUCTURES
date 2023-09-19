#include<bits/stdc++.h>
using namespace std ;

void left_most_rep_char ( string str ) 
{

     int char_freq [ 256]  = { 0 } ;

     for(int idx = 0 ; idx < str.length() ; idx ++ )
     {
          char curr_char = str [ idx ]  - 'a'; 

          char_freq[curr_char] ++;

          if ( char_freq[curr_char] > 1 )
          {
               cout << str [ idx ]<< endl;
               return;
          }
     }
     
     cout <<"LEFT MOST CHAR NOT FOUND"<< endl;
}


int main ()
{
     string str = "abbcd";

     left_most_rep_char( str ) ; 

     return  0;
}
