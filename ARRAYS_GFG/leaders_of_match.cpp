#include<bits/stdc++.h>
using namespace std ;

// a leader is the element which is greter then all of its right side elements
vector < int > get_leaders  ( int arr [ ] ,int n ) 
{
vector<int> leaders ; 

     leaders.push_back( arr[ n -1 ]  );
     int  max_val = arr[  n -1 ] ; 
     for (  int idx =  n-2; idx >= 0 ; idx -- )
     {
          int curr_val =  arr[ idx ] ;

          if ( curr_val > max_val )  
          {
               leaders.push_back( curr_val ) ;
               max_val = curr_val;
          }   
     }

     vector<int>::reverse_iterator rev_it ;
     for ( rev_it = leaders.rbegin() ; rev_it != leaders.rend() ;  rev_it ++)
     {
          cout <<*rev_it <<  " ";
     }
     cout << endl;

}    



int main ()
{
     int arr[] = { 10,50,40, 4, 5 };
     get_leaders( arr , 5);

     return 0;
}