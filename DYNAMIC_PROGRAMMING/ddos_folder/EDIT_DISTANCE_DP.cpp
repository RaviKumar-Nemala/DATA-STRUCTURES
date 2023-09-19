// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        int dp[n+1][m+1];
        int i,j;
        for(i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                dp[i][j] =  dp[i-1][j-1];
                else
                {
                    dp[i][j] = 1+min(dp[i-1][j] , min(dp[i][j-1] ,dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
        
};

// { Driver Code Starts.
int main() {
        string s, t;
        cin >> s >> t;
       // "sunday";
	   //"saturday"
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    return 0;
}
  // } Driver Code Ends