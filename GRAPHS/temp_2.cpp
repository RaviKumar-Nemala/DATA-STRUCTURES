#include<bits/stdc++.h>
using namespace std ;

void prims_algo ( vector<pair< int , int >  >adj [ ]  , int no_of_nodes  , int source )
{
     vector< int > distance( no_of_nodes , INT_MAX);

     vector < bool > mst ( no_of_nodes , false );
     vector < int >parent ( no_of_nodes , -1 ) ;
     parent [ source ] = -2 ; 

     distance [source ] =  0 ;

     priority_queue<pair < int , int >   , vector < pair < int , int> >  , greater <pair < int , int >  > > min_heap;

     min_heap.push ( make_pair (  0 , source ) ) ;

     for ( int i = 0 ; i < no_of_nodes - 1 ; i ++ )
     { 
               int parent_val = min_heap.top ().second; 

               min_heap.pop () ;

               mst [ parent_val ] = parent_val ;

               for( auto it : adj [parent_val]) 
               {
                    int adj_node = it.first ;
                    int wt = it.second; 

                    if ( mst [ adj_node ] == false and  wt < distance[  adj_node ]) 
                    {    
                         distance[ adj_node] = wt ;

                         parent [ adj_node ] = parent_val;

                         min_heap.push( make_pair ( wt , adj_node )) ; 

                    }
               }
     }
     // for ( auto it : distance )
     //      {
     //           cout <<it <<" " ; 
     //      }
     //      cout << endl;
     
     for ( int idx = 0 ; idx < parent.size () ; idx ++ )
     {
          if ( parent[ idx ]  == -1 )continue ;
          
          cout << parent [ idx ] << " ->  "  << idx << "  " << distance [ idx ]  << endl;
     }

}

struct node 
{
     int  u ; 
     int v ; 
     int  wt ;
     node (int u ,  int v , int wt )
     {
          this -> u = u ;
          this -> v = v ;
          this -> wt = wt ;
     }
};


int find_parent ( int u , vector< int > &parent ) 
{
     if ( parent [u ]  == u )
     {
          return u ;
     }

     parent [ u ] = find_parent ( parent [ u ] ,  parent ) ;
     return parent [ u ] ; 
}

void make_union ( int u , int v , vector<int >&parent , vector < int > &rank)
{
     u = find_parent  ( u  , parent ) ;

     v = find_parent ( v  ,parent) ;

     if ( rank [ u ] > rank [ v ]) 
     {
          parent [ v ] = u ; 
          rank [ u ]++;
     }
     else if ( rank [v] > rank [ u ] ) 
     {
          parent [ u ]  = v;
          rank [ v ] ++;
     }
     else 
     {
          parent [ u ] = v ; 
          rank[ v ] ++;
     }

}

bool comp ( node  a, node b ) 
{
     return a.wt < b .wt ; 
}

int main ()
{
     int no_of_nodes ; 
     int no_of_edges ;
     cin>> no_of_nodes >> no_of_edges ; 
     vector < node > adj ; 

     for ( int idx = 0 ; idx  < no_of_edges ; idx ++ ) 
     {
          int u , v ,  wt ; 
          cin >>  u >> v  >> wt ;
          node n(u , v , wt ) ;
          adj.push_back ( n ) ; 
     }

     sort( adj.begin () , adj.end() , comp) ;

     vector< int > rank ( no_of_nodes +1 ,  0 ) ; 

     vector <int > parent ( no_of_nodes + 1 , -1 ) ;

     vector<pair < int  ,int > >  mst ; 

     for( int idx = 0 ; idx <= no_of_nodes ;  idx ++ )
     {
          parent [ idx ] = idx ;
     }

     for( auto  it : adj ) 
     {
          int u = it.u; 
          int v = it.v ;
          int wt = it.wt ;    

          if ( find_parent( u , parent ) != find_parent( v , parent) ) 
          {
               make_union( u , v , parent , rank ) ; 
               mst.push_back ( { u ,v } ) ;           
          }
     }    

     for ( auto it : mst )
     {
          cout << it.first << " -> " << it.second  << endl; 
     }

     for ( auto it : parent )
     {
          cout << it << endl;
     }

     // vector< pair <  int ,int >>  adj [no_of_nodes + 1 ] ;

     // for ( int idx = 0 ; idx< no_of_edges ; idx ++ ) 
     // {
     //      int u , v , wt ;

     //      cin >>u >> v >> wt ;     

     //      adj[ u ].push_back ( make_pair ( v , wt )) ; 

     //      adj [ v ] .push_back( make_pair ( u , wt )) ; 
     // }

     // // dikstra ( no_of_edges , 1 , adj ) ; 

     // prims_algo(adj , no_of_nodes+1 , 1 ) ; 


     return 0;

}


