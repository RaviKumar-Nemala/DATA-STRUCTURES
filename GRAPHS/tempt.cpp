#include<bits/stdc++.h>
using namespace std ;

vector < pair < int ,int >  >bridges; 

int timer = 0 ; 

void find_bridges ( int node, vector < int > &low , vector< int> &disc ,vector < bool>  &visited  , vector<int > adj[]  , int parent) 
{
     low [ node ]  =  timer;

     disc [ node ] = timer;

     visited [ node ] = true ;

     timer ++;

     for ( auto it : adj [ node ]) 
     {
          if ( visited [ it ] == false )
          {
               find_bridges( it , low , disc , visited , adj  , node) ;

               low [ node ]  = min( low [ node ],  low [ it] ) ;

               if ( disc [ node ] < low [ it ] ) 
               {
                    bridges.push_back ({node , it } ) ; 
               }
          }
          else if ( it != parent )
          {
               low [ node ] = min ( low [ node ] ,  disc [ it ] ) ; 
          }
     }
     return;
}

void detect_bridges( vector < int > adj[]  , int no_of_nodes )
{
     vector<bool> visited ( no_of_nodes , false ) ; 

     vector < int > low (  no_of_nodes  );

     vector <int  > disc( no_of_nodes) ; 
     cout <<"called" << endl;
     for ( int idx = 0 ; idx < no_of_nodes ; idx ++ ) 
     {    
          if ( visited[idx ] == false )
          {
               find_bridges (idx , low ,disc , visited , adj , -1);
          }          
     }

     cout << bridges.size () << endl;
     for ( auto it : bridges )
     {
          cout << it.first <<  " " << it.second  <<  " " << endl;
     }
}



struct node
 {
     int u  , v , wt ;
     node ( int u , int v , int wt)
     {
          this -> u  = u ;
          this -> v = v ;
          this -> wt = wt ;
     }    
 
};

int find_parent ( int node , vector< int> &parent ) 
{
     if ( node ==  parent [ node ] )
     {
          return node ; 
     }

     parent [ node ] = find_parent ( parent[node ] , parent ) ; 

     return parent[node ];

}

void join(  int u , int v , vector < int > &rank , vector<int> &parent ) 
{

     u = find_parent ( u , parent ) ; 

     v = find_parent ( v  , parent ) ;

     if ( rank[u ] > rank  [ v ] )
     {
          parent [ v ] = u ;          
          rank [ u ] ++;
     }
     else if ( rank [ v ] > rank [u ]) 
     {
          parent [ u ] = v ;
          rank  [ v  ]++;
     }    
     else 
     {
          parent [ v ] = u ;
          rank[ u ]++;
     }
     return;
}

void dfs_1( int curr_node , vector < int > adj[] ,  vector < bool > &visited , stack <int >&st )
{
     visited [ curr_node] = true ;

     for ( auto it : adj [ curr_node ]) 
     {
          if ( !visited [ it ] ) 
          {
               dfs_1 ( it , adj , visited , st);
          }

     }    
     
     st.push(  curr_node);

}

void dfs_2 ( int node, vector< bool> &visited , vector < int > rev_nodes[] )
{
     visited [ node ] = true ;
     cout << node <<" " ; 

     for ( auto it :  rev_nodes [ node ] )
     {
          if ( visited[ it ] == false )
          {
               dfs_2 ( it , visited , rev_nodes );
          }
     }
}

vector < int > rev_list [ 100 ] ; 

void reverse ( vector< int > adj[] , int no_of_nodes )
{
     for( int idx = 0 ; idx < no_of_nodes  ; idx ++ )
     {
          for( auto  it : adj [ idx ] )
          {
               rev_list [it].push_back(idx); 
          }
     }
}

void print_stack ( stack< int > st )
{
     while ( !st.empty() )
     {
          cout << st.top () <<" " ; 
          st.pop();
     }
     cout <<endl;
}

void print_rev_list( int no_of_nodes ) 
{
     for ( int idx = 0 ; idx < no_of_nodes ; idx ++ )
     {
          for( auto it : rev_list[ idx ] ) 
          {
               cout << idx << "  ->" << it << endl; 
          }
     }

}

void dfs( int node , vector < int > &low , vector < int > &disc , vector< bool>&visited , vector< int > adj[] , int parent) 
{
     visited [ node ] = true;

     static int timer = 0 ;

     low [ node ] = disc [ node ] = timer;
     
     timer++;

     for ( auto it : adj [ node ] ) 
     {
          if ( visited [ it ] == false ) 
          {
               dfs ( it , low , disc ,  visited  , adj , node ); 
               low [ node ] = min( low[node ] ,  low[it] ) ;
               if ( disc[node] < low [ it ] ) 
               {
                    cout << node <<" -> " << it <<" " << endl; 
               }
          }
          else if ( it != parent )
          {    
               low[node ] = min( low [ node ] ,  disc[  it ] ) ;
          }
     }
}
void articulation_points (  int no_of_nodes,vector< int > adj[] )
{
     vector<int >low ( no_of_nodes );
     vector < int > disc ( no_of_nodes ) ;
     vector < bool > visited( no_of_nodes , false );

     for ( int idx = 0 ; idx < no_of_nodes ; idx ++)
     {
          if ( !visited[ idx ] ) 
          {
               dfs(idx , low , disc , visited , adj , -1) ;
          }
     }
}

void scc ( int no_of_nodes , vector< int > adj[] ) 
{
     vector< bool> visited( no_of_nodes  , false ) ;

     stack < int > st ; 

     for ( int idx= 0 ; idx < no_of_nodes ; idx ++ )
     {    
          if ( visited[  idx ] == false )
          {
               dfs_1( idx , adj , visited , st );
          }

     }

     reverse( adj , no_of_nodes );

     visited.assign(no_of_nodes , false ) ;

     while ( !st.empty() ) 
     {
          int curr_node = st.top () ;
          st.pop ();
          if ( !visited[ curr_node ] ) 
          {
               dfs_2( curr_node ,  visited , rev_list) ; 
          }cout << endl;

     }

}

    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int > >q ;
        
        int row , col;
        
        int row_size = grid.size() ;
        
        int col_size = grid [0].size() ; 
        
        for ( row = 0 ; row < row_size; row ++)
        {
            for ( col = 0 ; col < col_size ; col ++)
            {
                if (  grid[row][col] == 2)
                {
                    q.push( make_pair(row, col) );
                }
            }
        }
        
        int res = 0 ;
    while  ( !q.empty( )){
        
        int n = q.size ();
        res ++;
        while ( n-- )
        {
            
            auto it = q.front();
            
            int curr_row = it.first ;
            
            int curr_col = it.second;
            
            q.pop();
            
            int top_row =  curr_row -1 >=0 ? curr_row -1  : -1 ;

            int left_col = curr_col -1 >= 0 ? curr_col - 1 : -1 ; 

            int right_col = curr_col +1 <=(col_size-1) ? curr_col + 1  : -1 ;

            int bottom_row = curr_row +1 <= (n-1) ? curr_row + 1 : -1 ;

            if ( top_row != -1 and grid [ top_row] [ curr_col ] == 1 )
            {
                grid [ top_row] [ curr_col ] =  2;
                q.push(make_pair(top_row , curr_col));
            }
            
            if ( left_col != -1 and grid[curr_row][left_col] == 1 )
            {
                grid[curr_row] [left_col] = 2 ;
                q.push( make_pair( curr_row, left_col ) ) ;
            }
            
            if( right_col != -1 and grid [curr_row] [ right_col ] == 1 )
            {
                grid[ curr_row][right_col] =2 ;
                q.push(make_pair( curr_row, right_col));
                
            }
            
            if( bottom_row != -1 and grid[ bottom_row][curr_col] == 1 )
            {
                grid [ bottom_row][curr_col] = 2 ;
                q.push( make_pair( bottom_row,curr_col));
            }
            
        }
        
    }
    
    cout << res << endl;
        for( row = 0 ; row < row_size ; row ++ )
        {
            for ( col = 0; col < col_size ;  col++)
            {
                if ( grid [ row] [ col ] == 1 )
                {
                    return -1;
                }
            }
        }
        
        return res ;
        
        
    }

int main ()
{
    vector<vector<int > >  grid = {{0,1,2},{0,1,2},{2,1,1}};

     cout <<orangesRotting(grid) << endl;


     // int no_of_nodes ;
     // int no_of_edges ;
     // cin >> no_of_nodes >> no_of_edges ;

     // // vector< node > nodes ;
     // vector < int  >adj [ no_of_nodes + 1 ] ; 

     // for ( int idx = 0 ; idx  < no_of_edges  ; idx ++ ) 
     // {
     //      int u ,v ;
     //      cin >> u >> v ;
     //      adj [ u ] .push_back ( v ); 
     //      adj [ v].push_back ( u ) ; 
     // }

 //    scc( no_of_nodes , adj ) ;

     //articulation_points ( no_of_nodes , adj ) ;

     // detect_bridges ( adj , no_of_nodes+1) ; 


     // vector < int  > parent ( no_of_nodes+1 ) ;

     // vector < int > rank ( no_of_nodes+1  , 0 );

     // for ( int idx = 0 ; idx < no_of_nodes ; idx ++ )
     // {
     //      parent [ idx ] = idx ;
     // }

     // for ( int idx = 0 ; idx < no_of_edges  ; idx ++ ) 
     // {
     //      int u , v  , wt ;

     //      cin >>  u >> v >> wt ; 

     //      node n ( u, v ,wt ) ;

     //      nodes.push_back ( n ); 
     // }
     
     // for ( auto it : nodes ) {

     //      if ( find_parent (it.u, parent) != find_parent ( it.v , parent) )
     //      {
     //           join(it.u , it.v ,  rank , parent ) ;
     //      }
     //      else 
     //      {
     //           cout <<" THERE IS A CYCLE IN THE GRAPH "<< endl;
     //           exit(1);
     //      }
     // }
 
     // cout << "THERE IS NO CYCLE IN THE GRAPH " << endl;

     return 0 ;
}