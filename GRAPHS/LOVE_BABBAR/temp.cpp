#include<bits/stdc++.h>
using namespace std ;

class Solution 
{

public :

    
     int  solve ( vector < int > graph []   , int v )
     {


        vector < int > res (  v , -1 ) ;

        vector < bool > available (v , false );


        int cromatic_number = INT_MIN;

        for  ( int current_node =  0 ; current_node < v ; current_node ++ )
        {

        
        for ( auto adj_nodes : graph [ current_node ] ) 
        {

            if ( res  [ adj_nodes ] != -1 )
            {
                available [ res [ adj_nodes] ] =  true;
            }

        }
        int col_idx ;
        
        for (  col_idx =   0 ; col_idx < v ; col_idx ++ )
        {

            if ( available [ col_idx ] == false )
            {
                break;
            }

        }

        res [ current_node ]  = col_idx ;

        cromatic_number = max( cromatic_number , col_idx ) ;


        for ( auto it : graph [ current_node ] ){
               {
                    if ( res [ it ] != -1 )
                    {
                         available [ res [ it ]  ] =  false ;
                    }
               }
        }

     }


        return cromatic_number ;
     }

};


int main () 
{

     int n  , m ;

     cin >>  n >>  m ;

     vector < int > graph [ n+1 ] ;

     int u ,v ;

     for ( int i = 0 ; i <  m  ; i ++ )
     {
          cin >>u >> v ;
          
          graph [u ].push_back ( v );

          graph[v].push_back ( u ) ;

     }

     Solution obj ;


    int max_colors  ; 

    cin >> max_colors ;


    int cromatic_number =  obj.solve ( graph , n ) ;


    if ( cromatic_number <= max_colors )
    {
        cout << " GRAPH CAN BE COLOURED WITH THE GIVEN MAX COLORS  "<< endl;
    }
    else{
        cout <<" GRAPH CANNOT BE COLOURED WITH THE GIVEN MAX_COLORS "<< endl;
    }
     return 0 ;

}