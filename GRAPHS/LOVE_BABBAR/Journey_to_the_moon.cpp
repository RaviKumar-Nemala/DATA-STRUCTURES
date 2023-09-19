#include<bits/stdc++.h>
using namespace std ;


class Solution 
{

public: 

     void dfs ( vector < int  > graph []  , int node , vector   < bool > &visited ,  int &nodes_count)
     {

          visited [ node ] = true; 

          nodes_count ++ ;

          for ( auto it : graph [ node ] ) 
          {

                    if ( !visited  [ it ] )
                    {

                         dfs ( graph , it, visited ,nodes_count ) ;

                    }

          }

     }


     void config ( vector < int > graph[] , int V )
     {

          vector <  bool > visited ( V , false ) ;

          vector < int > solution  ;

          for ( int i  = 0 ; i < V ; i ++ )
          {

               if (!visited [ i ] ) 
               {

                    int nodes_count = 0 ; 

                    dfs  ( graph ,  i   , visited, nodes_count );

                    solution.push_back ( nodes_count ) ;

               }

          }

          
          int  n = solution.size () ;

          int total_pairs = ( V * ( V -1 ) ) / 2 ; // nc2 = ( n *  n -1 )/2 

          for ( int i  =  0 ; i < n ; i ++ )
          {

          
          int component_pairs = ( solution [ i ] * ( solution[i] -1) ) / 2  ;

          total_pairs -= component_pairs;

          }


          cout << " NO OF DIFFERNT PAIRS : "<< total_pairs << endl ;

     }






};
 


int main () 
{

     
     int u,v;

     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;

     vector < int > graph [ n ] ;


     for ( int i = 0 ;i  < m ; i ++ )
     {

          cin >> u >> v ;

          graph [ u ].push_back ( v ) ;

          graph [ v ].push_back (  u  ) ;

     }

     Solution obj ;

     obj.config ( graph , n ) ;

}
