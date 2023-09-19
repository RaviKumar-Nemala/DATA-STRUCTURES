#include<bits/stdc++.h>
using namespace std ;

vector<int > dfs_result;

vector< int > adj[100];

bool is_cycle_direct ( int curr_node ,  int parent , vector < int > adj [] , vector <bool>&visited , vector<bool>&dfs_path)
{
     visited [ curr_node ] = true;
     dfs_path [ curr_node ] = true;
     for ( auto it: adj [ curr_node ] )
     {
          if ( visited [ it ] == false )
          {
               if ( is_cycle_direct ( it , curr_node , adj , visited , dfs_path ) )
               {
                    return true;
               }
          }
          else if ( dfs_path[ it ] )
          {
               return true;
          }
     }
          dfs_path [ curr_node ] = false ;

          return false; 
}

void  direct_graph_cycle_detect( vector < int > adj[]  , int n ) 
{
     vector < bool > visited ( n, false );
     vector< bool>  dfs_path ( n , false );
     for ( int idx = 1 ; idx < n ; idx ++ ) 
     {
          if( !visited [ idx ] ) 
          {
               if ( is_cycle_direct ( idx , -1 , adj , visited , dfs_path ))
               {
                    cout <<"CYCLE DETECTED IN THE DIRECT GRAPH" << endl;
                    return;
               }
          }
     }

     cout <<"CYCLE IS NOT  DETECTED" << endl;

}

bool is_cycle ( int curr_node , int parent , vector < int > adj[] , vector <bool > &visited)
{
     visited[ curr_node ] = true ;

     for ( auto  it : adj [ curr_node ]) 
     {
          if ( !visited [ it ] )
          {
               if(is_cycle ( it , curr_node , adj , visited))
               {
                    return true;
               }

          }
          else if ( it != parent  )
          {
               return true;
          }
     }
     return false;

}




void dfs_util ( int curr_node ,vector < int > adj [ ] , vector<bool > &visited )
{
     visited[  curr_node ] =true;
     dfs_result.push_back( curr_node ) ;      
     for( auto it : adj [ curr_node ] ) 
     {
          if ( visited [ it ] == false )
          {
               dfs_util ( it , adj , visited )  ;
          }
     }

     return;

}


void check_cycle ( vector < int > adj [] , int n )
{
     vector < bool > visited ( n ,  false ) ;

     for( int idx =0 ; idx < n ; idx ++ )
     {
          if ( !visited[idx] )
          {
               if ( is_cycle(idx , -1 , adj , visited))
               {
                    cout <<"CYCLE IS EXISTED"<< endl;
                    return;
               }
          }
     }
     cout << "CYCLE IS NOT FOUND" << endl;

}



void dfs ( vector< int > adj [] , int n  )
{
     vector < bool> visited ( n , false ) ;

     for ( int idx = 0; idx < n ; idx ++ )
     {
          if( visited [ idx] == false)
          {
               dfs_util ( idx , adj , visited ) ; 
          }

     }

     for( auto it: dfs_result )
     {
          cout << it <<"  " ; 
     }cout << endl;
}

void toposort_bfs( vector <int > adj[] , int no_of_nodes )
{

     // dfs(adj , no_of_nodes) ;

     queue <int >   q ;

     q.push ( 1 ) ; //assuming the start node =1  
     
     vector< int > res ;
     
     vector< int > indegree ( no_of_nodes , 0 ) ;

     for ( int idx = 1  ; idx < no_of_nodes; idx++)
     {    
          for ( auto it : adj[ idx ]) 
          {
               indegree[it] ++;
          }
     }

     while ( !q.empty() )
     {
          int curr_node = q.front ();

          q.pop ();

          res.push_back( curr_node ) ;

          for ( auto it : adj[curr_node ]) 
          {
               indegree [ it ]--;

               if ( indegree[it] == 0 )
               {
                    q.push ( it ) ;
               }
          }

     }
     for ( auto it : res )
     {
          cout << it <<" " ; 
     }cout<< endl;
}




bool is_bipolo ( int no_of_nodes , vector < int > adj [] ) 
{
     queue < int > q ;
     vector<int > visited ( no_of_nodes , -1 ) ;
     q.push ( 1 ) ;
     visited[  1 ] = 1 ;

     while ( !q.empty() )
     {
          int curr_node = q.front () ;

          q.pop();

          for ( auto  it : adj [ curr_node ]) 
          {
               cout << it <<endl;

               if ( visited [ it ]  == -1 )
               {
                    visited[  it ] = 1 - visited [ curr_node ] ; 
                    q.push ( it );
               }
               else if( visited [ it ] == visited[  curr_node ]) 
               {
                    return false;
               }
          }

     }

     return true;

}


void check_bipolo  ( int no_of_nodes , vector <  int > adj [] ) 
{
     vector < int > visited ( no_of_nodes ,false ) ;   

     if(is_bipolo(no_of_nodes , adj ) )
     {
          cout <<"IT IS THE BIPATITE GRAPH " << endl;
     }
     else 
     {
          cout  <<"IT IS NOT A BIPATITE GRAPH"<< endl;
     } 

}

void shortest_distance ( int no_of_nodes , vector<int > adj[] , int source ,int dest )
{

     vector < int >distance ( no_of_nodes , INT_MAX);

     distance [ source ] = 0 ;

     queue <int > q ;

     q.push ( source) ; 

     while ( !q.empty() ) 
     {    
          int curr_node =q.front (); 
          
          q.pop();

          int curr_distance = distance [ curr_node ] ;

          for ( auto it: adj [ curr_node ]) 
          {
               if ( curr_distance  +1 < ( distance [ it ]) )
               {
                    distance[ it ] = curr_distance + 1 ; 
                    q.push ( it ) ; 
               }
          }
     }

     cout<<distance[ dest] << endl;

}

void dikstra( int no_of_nodes  , int source, vector <pair<int , int > >adj[] )
{

     priority_queue<pair < int , int >  , vector< pair < int ,int > >  , greater <  pair < int, int >  >  > min_heap;

     min_heap.push ( make_pair (0, source ) ) ;

     vector <int > distance ( no_of_nodes , INT_MAX);
     distance [ source] = 0 ;

     while ( !min_heap.empty() ) 
     {
          int curr_node =  min_heap.top ().second ;

          int curr_distance  = min_heap.top () .first;

          for ( pair < int , int > it : adj[ curr_node ]) 
           {
               int connected_node = it.first ;

               int connected_weight = it.second ; 

               if ( curr_distance + connected_weight > distance [ connected_node ]   )
               {
                    min_heap.push ( make_pair(curr_distance  + connected_weight , connected_node  ) ) ;

                    distance [connected_node ] = curr_distance  + connected_weight ; 
               }


           }


     }



}


int  make_direct_graph (  ) 
{

     int no_of_nodes  =  5;
     adj [ 1 ].push_back ( 2 ) ;
     adj [ 1 ].push_back(4);
     adj [ 1].push_back ( 3) ;
     // adj [ 4].push_back ( 1 ) ;

     return no_of_nodes;
}


int make_indirect_graph (  )
{
     int no_of_nodes = 7 ; 
 
     adj[1].push_back( 2 ) ;
     adj[2].push_back ( 1);
     adj [1].push_back( 4);
     adj[4].push_back( 1 );
     adj [ 1].push_back( 3) ;
     adj [ 3].push_back ( 1) ;
     adj [ 3].push_back ( 6 ) ;
     adj [6].push_back ( 3) ;
     adj[2].push_back (5);
     adj [ 5].push_back ( 2);
     adj[3].push_back( 4 ) ;
     // adj[3].push_back(4);
     return no_of_nodes;

}

int main ()
{

     // int no_of_nodes =make_direct_graph( ) ;


     // direct_graph_cycle_detect( adj ,no_of_nodes) ;    

     int no_of_nodes = make_indirect_graph ( ) ; 

     // check_bipolo ( no_of_nodes  , adj ) ; 

     // toposort_bfs( adj , no_of_nodes ) ;

     int source = 1 ;

     int dest = 5 ;

 //    shortest_distance( no_of_nodes , adj , source , dest ) ;

   


     // int no_of_nodes = 6 ;

     
     // // dfs ( adj , no_of_nodes +1);
     // check_cycle ( adj , no_of_nodes +1 ) ;
     // return  0; 
}