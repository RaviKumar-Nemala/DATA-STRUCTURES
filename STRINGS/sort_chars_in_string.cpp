#include<string.h>
#include<iostream>
using namespace std ;

void handle (string str) 
{
     int char_freq[ 26]  = {  0 } ;

     for(char ch : str )
     {
          int asci_val =  ch - 'a';

          char_freq[asci_val] ++;

     }

     for ( int idx =  0 ; idx < 26 ; idx++ )
     {
          if ( char_freq [ idx ] != 0)
          {
               cout << (char) ( idx + 'a') <<" " << char_freq[idx]<< endl; 
          }
     }

     cout << endl; 
}

int main ()
{
     string str = "abcdedndlja" ; 
     handle( str) ; 
     return 0 ;
}