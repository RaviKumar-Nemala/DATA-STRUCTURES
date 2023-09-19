#include<bits/stdc++.h>
using namespace std;





// for finding the topological sort for the given graph


void dfs ( vector < vector <  pair <int, int > >  > &graph ,int src  , vector < bool > &visited  , stack < int  > &st ) 
{

     visited [ src ] =  true ;

   
     for ( auto connected_nodes : graph [ src ] ) {

          int child_val =  connected_nodes.first ;

          if ( !visited [ child_val ] ) 
          {
               dfs ( graph , child_val , visited , st ) ;
          }
     }

     st.push( src ) ;

}
  

void config ( vector <vector  < pair < int , int  > > >  graph ,  int src , int n )
{

     vector < bool >  visited ( n ,false ) ;

     vector  < int  > dist ( n  ,INT_MIN ) ;

     dist [ src ] = 0 ; 

     stack < int >  st ;

     for ( int i = 0 ; i < n ; i  ++  )
     {

          if ( !visited [i ] ) 
          {
               dfs ( graph , i , visited , st ) ; 
          }

     }

     vector < int> sequence ; 

     while( !st.empty() )     
     {

          sequence.push_back ( st.top () );

          st.pop () ;

     }

     for (  int i = 0 ; i < n ; i ++ )
     {

          if ( dist [  sequence [ i ] ]  != INT_MIN ) 
          {

               for  ( auto it : graph [ sequence [  i ]  ]  )
               {

                    int parent_val = sequence [ i ] ;

                    int child_val = it.first  ;

                    int weight = it.second ; 

                    if ( dist [ child_val ] < ( dist[ parent_val ] + weight ) )
                    {
                         
                         dist [ child_val ] = dist [ parent_val] + weight;

                    }

               }

          }


     }



     for ( int i = 0 ; i < n ; i ++ )
     {

          if ( dist [ i ] != INT_MIN )
          {

               cout << src << " -> "<< i <<  "  = " << dist [ i ] << endl ;

          }

     }
     

}




int main(){
     
int u,v;

int wt;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector <  vector < pair <int ,int > >  > graph ( n ) ;

     for(int i=0;i<m;i++){
          cin>>u>>v>>wt;

          graph[u].push_back( { v ,wt} ) ;
     
}
config ( graph , 1 , n );


return 0 ;
}