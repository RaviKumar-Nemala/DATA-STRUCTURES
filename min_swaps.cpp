#include<bits/stdc++.h>
using namespace std;





void min_swaps (  vector < int >  arr , int  n )
{

     for ( auto it   : arr )
          cout << it << "  " ;

     vector< pair < int , int> >  v ;

     

     for ( int i = 0 ; i < n  ; i ++ )
     {

          int val = arr [ i ] ;

          cout << val <<  endl ;

          v .push_back  ( { val , i }  );
          
     }


     sort ( v.begin() , v.end ()  ) ;

     int no_of_swaps = 0 ;

     cout <<no_of_swaps << endl;

     for  ( int current_idx  = 0  ; current_idx < n ; current_idx  ++ )
     {

          pair< int , int > curr_pair =  v [ current_idx ] ; 

          int sorted_idx  = curr_pair.second ; 

          if ( current_idx   ==  sorted_idx  )
          {
               continue;
          }

          else{

               no_of_swaps ++ ;

               swap ( v[current_idx] , v [ sorted_idx ] ) ; 
               
               current_idx  --;

          }

     }


     cout << " NO SWAPS : "<< no_of_swaps << endl ;    

}

int main  () 
{


vector  < int >  temp =  { 1 , 5 , 4 ,3 ,2 } ;

min_swaps ( temp  , 5 ) ;



}
