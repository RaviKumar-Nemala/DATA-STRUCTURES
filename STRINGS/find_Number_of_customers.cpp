#include<bits/stdc++.h>
using namespace std;

int solve( int n , string str )
{ 
     int occupied =  0 ,res = 0 ; 
     vector< int> freq ( 26 , 0 ) ;
     for( int idx = 0 ;idx<  str.size () ; idx ++)
     {
          char ch = str [ idx ] ;
          int ele = ch - 'A';
          if( freq [ ele] == 0 )
          {
               freq [ ele] = 1 ;
               if ( occupied < n )
               { 
                    freq[ele] = 2 ;
                    occupied ++;
               }
               else
               { 
                    res++;
               }
          }
          else 
          {
               if( freq [ ele] == 2)
               {
                    occupied --;
               }
               freq [ ele] =  0 ;
          }

     }
     return res;
}


int main()
{
     //function to find number of customers who could not get any  computers computer
     //love babbar sheet //reference = gfg
     
     // int  n = 2 ; string str  = "ABBAJJKZKZ";
     int n = 3 ; string str = "GACCBDDBAGEE";
     cout << solve( n , str ) ;
     return 0 ;
}