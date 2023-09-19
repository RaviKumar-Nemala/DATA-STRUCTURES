// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(vector<int>A, int N) {
        // code here
        int dp[N];
        dp[N-1] = 0;
        int i,j;
        int min;
        int steps;
        for(i = N-2 ; i >= 0 ; i-- )
        {
            steps=A[i];
              min=INT_MAX;
            for(j=0 ; j <= steps && i+j < N ; j++ )
            {
              
                if(dp[i+j] < min and dp[i+j]!=0)
                {
                    min = dp[j];
                }
            }
            if(min!=INT_MAX)
            {
                dp[i] = min + 1;
            }
            else{
                 dp[i]=min;
            }
        }
        return dp[0];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    //cin >> t;
    int N=10;

        vector<int>A = {3,3,0,2,1,2,4,2,0,0};
        Solution ob;
        cout << ob.canReach(A,N) << endl;
    return 0;
}  // } Driver Code Ends