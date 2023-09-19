#include"config.h"



class Solution 
{

public:




void find_shortest_path ( vector < pair < int , int >  > graph [] , int v , int source, int destination  )
{


priority_queue < vector < pair <int , int  > >  , vector < pair < int  , int > >  , greater < pair <  int , int > >  >  min_heap ;



min_heap .push ( { 0 , source  } ); 


vector < int > distance (  v , INT_MAX );

distance [ source ] = 0 ;

while( !min_heap.empty() )
{


     int current_node = min_heap.top().second ;

     min_heap .pop();
     

     for ( auto adj_nodes :  graph [ current_node ] )
     {

          int adj_node = adj_nodes.first ;

          int adj_node_wt = adj_nodes.second ;

          if ( distance [ adj_node ] > ( distance [ current_node ] + adj_node_wt ) )
          {

              distance [ adj_node ] = ( distance [ current_node ] + adj_node_wt );
              
              min_heap .push ( { adj_node_wt , adj_node } ) ;

          }

     }

}



cout << " NO OF EDGES TO REVERSE TO REACH THE DEST : "<< distance [ destination] << endl;

return ;


}



void print_graph ( vector < pair < int , int > > graph[] , int v )
{
     for ( int i =  0 ; i < v ; i ++ )
     {
          
          for ( auto it : graph [ i ] ) 
          {
               
               int v =  it.first ;

               int wt =  it.second;

               cout << i  << " -> " << v << " : " << wt<< endl;

          }

     }

     return ;

}

void config ( vector < int >graph [ ]  , int v , int source , int destination   )
{

     
     vector < pair < int , int >  > new_graph [ v] ;

     for ( int current_node = 0 ; current_node < v ; current_node  ++ )
     {


          for( auto adj_node  :  graph [ current_node ] ) 
          {

               new_graph [ current_node ] .push_back ( { adj_node   , 0 } ) ;

               new_graph [  adj_node ].push_back ( { current_node , 1 } ) ;

          }

     }


    // print_graph ( new_graph , v ) ;

     find_shortest_path (new_graph , v , source , destination ) ;

     return ;

}

};





int main() 
{

     int n  , m ;

     cin >>  n >>  m ;

     vector < int > graph [ n ] ;

     int u ,v ;

     for ( int i = 0 ; i <  m  ; i ++ )
     {
          cin >>u >> v ;
          
          graph [u ].push_back ( v );

     }

     Solution obj ;

     int source =  0 ;

     int destination =  6 ; 

     obj.config( graph , n  , source , destination );

     return  0 ;
}