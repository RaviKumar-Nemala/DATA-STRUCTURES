#include<bits/stdc++.h>
using namespace std ;


void insertion_sort( int arr[] , int n )
{
     int i , j ;

     for ( i = 0 ;  i < n ; i ++ ) 
     {    
          int key = arr [ i ] ;

          int j  =  i - 1; 

          while (  j >= 0 and arr [ j ] > key )
          {
               arr [ j  + 1 ] =  arr [ j ] ; 
               j --;
          }

          arr [ j + 1 ] =  key ; 

     }

}
void get_min_cost ( vector < pair< int , int > > adj [] , int n  )
{
     vector <  bool > visited ( n , false ) ; 
     
     visited [ 0 ] = true ; 
     
     int source  = 0 ;

     vector <int > dist ( n , INT_MAX );

     dist [ 0 ]  =  0 ; 

     priority_queue< pair < int , int > , vector < pair < int , int > >  , greater< pair< int , int > > >  min_heap;

     min_heap.push (  { 0 , source } ) ;

     while ( !min_heap.empty () )
     {
          auto it =  min_heap.top () ;

          min_heap.pop();

          int parent = it.second ;

          int weight = it.first ; 

          for ( auto child : adj [ parent ] ) 
          {
               int child_node = child.first ;     
               
               int c_weight =  child.second ; 

               if ( dist [ child_node ] > ( weight + c_weight ) ) 
               {
                    dist  [ child_node] =  weight + c_weight;
               
                min_heap.push( {weight + c_weight ,  child_node } ) ; 
                }
          }

     }

     for ( auto it: dist )
     {
          cout  << it << " " ; 
     }
     cout << endl;


}

int main()
{    
     int n ;

     int v; 

     cin >> n >> v ;

     vector< pair< int , int > > adj  [ n ]  ;

     for ( int i = 0 ; i < v; i ++ )
     {
          int u , v , wt ;    

          cin >> u >> v >> wt  ;

          adj [  u ].push_back(  { v , wt } ) ; 
     }    
     
     get_min_cost(  adj , n ) ; 

     return 0 ; 
}