//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DisJoint
{   
    
    public:
    vector< int > size ,  parent ;
        DisJoint( int n ) 
        {
            this->size.resize(n + 1 ) ;
            this->parent.resize(n +1 ) ;

            for  ( int i = 0 ; i <= n ; i ++ )
            {
                 parent [ i ] = i ; 
                 size [ i ] =  1 ; 
            }
        }

        int  find_parent( int node )
        {
             if ( node == parent [ node ] ) 
             {
                return  node ;     
             }
            
            return parent[ node ] =  find_parent (  parent[ node ] ) ; 
            
        }

        void size_by_union(  int s1 , int s2 ) 
        {
            int p1 =  find_parent ( s1 ) ;

            int p2 = find_parent ( s2 ) ; 
            
            if ( p1 == p2 ) 
            {
                return;
            }

            if ( size [ p1 ]  < size [ p2 ] )
            {
                parent[ p1] = p2 ;
                size[p2 ] += size [ p1] ; 
            }

            else 
            { 
                parent[ p2 ] =  p1;
                size [ p1 ] += size[  p2 ] ; 
            }
            return;
        }   


};

class Solution {
    private:

    bool is_valid (  int row , int col , int n ) 
    {
            if ( row >=0 and  row < n  and col >= 0 and col <n )    
                return true;
            else 
                return false; 
    }   

  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n = grid.size (); 
        
        DisJoint ds (  n * n ) ; 
        
        int row_dir[ ] = {  -1 , 0 , 1  , 0 };
        
        int col_dir[] = { 0  ,  -1 , 0 , 1 };
        
        for ( int row  = 0 ; row < n ; row ++ )
        {
            for( int col = 0 ; col < n  ; col ++ )
            {
                if( grid[ row ] [ col ] == 0 )
                    continue;

                for( int  idx = 0 ; idx < 4 ; idx ++ )
                {
                    int adj_row = row  + row_dir[ idx ];

                    int adj_col = col + col_dir[ idx ]; 
                    
                    
                    if ( is_valid( adj_row,  adj_col ,  n ) and  grid[adj_row] [ adj_col] == 1 )
                    {
                        int node_num =  row * n + col ;

                        int adj_num = adj_row * n  + adj_col; 

                         ds.size_by_union(  node_num , adj_num ) ;  
                    }
                      
                }
            }
        }
        
        int max_connected_nodes =  INT_MIN; 
        
        for ( int row = 0 ; row < n ; row ++ )
        {
             for(  int col = 0 ; col < n ; col ++ ) 
             {
                    if(  grid[ row ] [ col ] ==   0 ) 
                    {
                        int  total_val =  1 ; 
                        
                        unordered_set<int > my_set; 

                        for(  int idx = 0 ; idx < 4 ; idx ++ )
                        {
                                int adj_row =  row + row_dir[ idx ] ;
                                
                                int adj_col  = col + col_dir[ idx ] ; 

                                if ( is_valid ( adj_row,   adj_col , n ) ) 
                                {
                                    int adj_num =  adj_row  *n + adj_col ;

                                    int adj_parent = ds.find_parent(  adj_num );

                                    my_set.insert( adj_parent);

                                }
                        }   
                        int total =  1; 
                        for( auto it : my_set)
                        {
                            total +=  ds.size[it]; 
                        }
                        max_connected_nodes  = max ( max_connected_nodes ,  total);

                    }
             }
        }


        return max_connected_nodes ;

    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends