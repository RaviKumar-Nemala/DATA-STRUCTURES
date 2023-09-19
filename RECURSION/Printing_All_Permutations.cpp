#include<bits/stdc++.h>
using namespace std ;


void permutations(  string str , int idx ) 
{
     if ( idx == str.length() -1  )
     {
          cout << str << endl;
          return;
     }

     for (int j = idx  ; j < str.length () ; j ++ )
     {
          swap (str [  idx ] , str [ j  ])  ;
          permutations( str , idx + 1  ) ;
          swap ( str [ idx ] ,  str [ j ] ) ;
     } 
     return;
}





int main ()
{
     string str = "ABCD";

     permutations( str , 0 );

     return 0;
}