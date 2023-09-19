//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

   int ways =  0 ;

   void dfs ( int curr_node  , int target_node, vector< int >adj[] )
   {
          if ( curr_node == target_node ) 
          {
               ways++;
          }

          for( auto it : adj [ curr_node ] ) 
           {
               dfs ( it , target_node , adj ) ; 
           }
   }


  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        dfs( source , destination , adj );
    }
};

void print_val ( vector< int > temp )
{
     for( auto it : temp )
     {
          cout << it <<" " ; 
     }cout << endl; 
}
//{ Driver Code Starts.
int main() {

     vector < int > temp = { 1 ,2,5,4 } ;

     vector <int > temp2 = temp ;

     
     sort(temp.begin () , temp.end() ) ;

     print_val ( temp ) ;

     print_val ( temp2) ;


    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends