#include<bits/stdc++.h>
using namespace std ;

void handle ( string str )
{    
     int idx = 1 ;

     int len =  0;
     
     int n = str.size();

     int lps [n] = { 0 } ;
     lps [ 0 ] = 0 ;
     while( idx < n ) 
     {
          if ( str [ len ] ==str [ idx ])
          {
               len++;
               lps [ idx ] = len;
               idx ++;
          }
          else 
          {
               if ( len == 0 )
               {
                    lps [ idx ] = 0 ;
                    idx ++;
               }
               else 
               {
                    len = lps[ len - 1 ] ; //if the chars are not matched then go back try to match the before chars until length reaches to the zero
               }
          }
     }

     for ( auto it : lps)
          cout << it <<" " ;
}

int main()
{
     string str1 = "AAABAA" ;

     handle ( str1 ) ;

     return 0; 
}