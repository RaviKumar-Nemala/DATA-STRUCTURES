#include<bits/stdc++.h>
using namespace std ;

void get_subsets( string str , string curr , int idx  )
{
     if ( idx  == str.size () )
     {
          cout << curr << endl; 
          return;
     }

     get_subsets( str ,  curr  , idx + 1 ) ;

     get_subsets( str , curr + str [ idx ] , idx + 1 ) ;

     return;
}

int main ()
{

     string str = "ABCD";
     string curr = "";
     get_subsets( str , curr , 0 ) ;
     
     return 0 ;
}