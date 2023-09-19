#include<bits/stdc++.h>
using namespace std ;
#define n 5
#define pb push_back
vector<int>graph[n];

class Solution 
{

public :

vector < pair < int , int > >  bridge ; 



void dfs ( vector <int > graph []   , int node , vector < int > &low , vector< int > &disc ,  int parent  , vector <bool > &visited  )
{

     static int time = 0 ; 

     low [ node ] = disc [ node ] = time++;

     visited [ node ] = true ;

     for ( auto it : graph [ node ] ) 
     {

          if ( !visited [ it ] ) 
          {    

               dfs ( graph , it , low, disc,  node ,visited ) ;


               low [ node ] = min ( low [ node ] , low [ it ] ) ;

               if ( low [ it ] > low [ node ] ) 
               {
                    bridge.push_back ( { node,  it }) ;
               }

          }
          else  if ( it != parent)
          {

               low [ node ] = min ( low [ it ] , disc [ node ])  ;
          }

     }


}

      void config ( vector < int > graph[] )
     {

          vector <  bool > visited ( n , false );

          vector< int >  low  ( n , 0 ) ;

          vector < int> disc ( n , 0 ) ;

          for (  int i = 0 ; i <  n ; i ++ )
          {

               if ( !visited[ i ] ) 
               {
                    
                    dfs ( graph  ,i ,low,  disc, -1, visited );

               }
          
          }


          for ( auto it : bridge )
          {

               cout <<it.first << "  " << it.second << endl ;

          }

     return ;
     }
     

};
int main () 
{


   graph[0].pb(2);
	graph[2].pb(0);
	graph[0].pb(3);
	graph[3].pb(0);
	graph[1].pb(0);
	graph[0].pb(1);
	graph[2].pb(1);
	//adj[2].pb(4);
	//adj[4].pb(2);
	graph[1].pb(2);
	graph[3].pb(4);
	graph[4].pb(3);


Solution obj ;

obj.config( graph );


}




