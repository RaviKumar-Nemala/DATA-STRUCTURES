#include<bits/stdc++.h>
using namespace std ;
// } Driver Code Ends
class Solution
{
     int bfs ( int  curr_row , int curr_col , int row_size ,  int col_size , vector<vector<int> > &grid)
     {
          queue<pair< int , int > > q ;
          
          q.push( {curr_row ,curr_col } ) ;

          int row_dir [ 8 ]  ; 
          
          int col_dir [ 8 ] ; 
          int count = 1 ;    
          while ( !q.empty() ) {
          
          curr_row = q.front().first;
      
          curr_col  = q.front().second;
      
          q.pop () ;
      
          for( int i = 0 ; i < 8  ; i ++ )
          {
               int row = curr_row + row_dir[ i ] ;
               int col = curr_col + col_dir[i];
               if ( row < row_size  and col < col_size and grid[row][col] == 1 )
               {
                    q.push(  { row , col } ) ; 

                    grid[row][col] = 0 ;
                    count ++;
               }
          }
     }
          return count ;
     }
 
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {

     int row_size = grid.size () ;

     int col_size = grid[0].size () ;

     int max_size = INT_MIN; 

     for ( int row =0 ; row < row_size ; row ++ ) 
     {
          for ( int col = 0 ; col < col_size ; col ++ )
          {
               if ( grid [row] [ col ] == 1 )
               {
                    int temp = bfs(row ,col , row_size , col_size , grid) ; 
                    max_size = max( max_size , temp ) ;               
               }
          }

     }

     cout << max_size << endl; 
     
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends


int main()
{



     return 0; 
}