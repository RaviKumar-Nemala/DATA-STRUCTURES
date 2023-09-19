//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:

    int minimumCostPath(vector<vector<int>>& grid) 
    {
          int dist[grid.size()][grid[0].size()] ;

          int curr_cost = 0 ;
          int row_size = grid.size ();
          int col_size = grid[0].size () ; 

          for ( int idx = 0 ; idx <row_size  ; idx ++ )
          {
               for ( int col = 0 ; col < col_size ; col ++)
               {
                    dist[idx][col] = INT_MAX;
                }
          }
          
          priority_queue< pair< int , pair<int ,int> >  , vector< pair <int , pair<int,int> > >  , greater<pair<int,  pair<int,int > >  >  >  min_heap;

          min_heap.push(make_pair(0 , make_pair(0,0)));

          dist [ 0 ] [ 0 ] = 0 ;
           
          int row_dir[4] = { -1   , 1 , 0 ,0};

          int col_dir[4] = {  0 ,  0  , -1 , 1 };
          int total_dis = 0 ;          
          while ( !min_heap.empty())
          {
               auto it = min_heap.top() ;
               
               min_heap.pop();

               int distance =  it.first ;
               total_dis += distance ;
               int curr_row = it.second.first; 
               
               int curr_col = it.second.second;
               
               if( curr_row == row_size -1 and curr_col == col_size -1 )
               {
                    return total_dis;
               }

               for ( int idx = 0 ; idx  < 4  ; idx++ )
               {
                    int next_row = curr_row + row_dir [ idx] ;
                    int next_col = curr_col + col_dir [  idx ] ;
                    if(next_row >=0 and next_row < row_size  and next_col >= 0 and next_col < col_size)
                    {
                         if(distance + grid[ next_row] [ next_col] < ( dist[next_row][next_col]))
                         {
                              int total_dis = distance + grid[ next_row] [ next_col];

                              dist[next_row] [ next_col] =  total_dis ;

                              min_heap.push( make_pair( grid[next_row][next_col] , make_pair(next_row , next_col)));

                         }
                    }
               }

          }
         


    }
};

//{ Driver Code Starts.
int main(){
	
          vector<vector<int > > grid = 
{ {9 , 4 , 9 ,  9},  
  {6 ,7 ,6 ,4}, 
  {8, 3 ,3, 7 },
  {7, 4, 9, 10}
};
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	
	return 0;
}
// } Driver Code Ends