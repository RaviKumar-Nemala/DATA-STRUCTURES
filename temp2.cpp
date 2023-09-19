//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    //reference = pepcoding
    public:
    bool match(string wild, string pattern)
    {
        int n1= wild.size ()  , n2 = pattern.size () ; 
        bool dp [ n1 + 1 ] [ n2 +1 ] = { false };
        int  i, j ;
        
        for( i = n1 ; i >= 0 ; i -- )
        {
            for (  j = n2 ; j >= 0 ; j -- )
            {
                if(  i == n1  and j == n2)  
                {
                    dp [ i ] [ j ] = true;
                }
                else if(  i == n1)
                {
                    dp [ i ][ j ] = false ;
                }
                else if(  j== n2 )
                {
                    if( wild[i] == '*')
                    {
                        dp[i][j] = dp[i+1][j];
                    }
                    else 
                        dp[i][j]= false;
                }
                else 
                {
                    if( wild[i] == '?')
                    {
                        dp [i ][ j ] =  dp [ i +1 ][ j+1];
                    }
                    else if ( wild[i] == '*')
                    {
                        dp [ i ] [ j ] = dp [i+1][j] ||dp[i][j+1];
                    }
                    else 
                    {
                        if( wild[i] == pattern[j])
                        {
                            dp[i][j]= dp[i+1][j+1];
                        }
                        else 
                        {
                            dp[i][j]= false;
                        }
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{

        string wild = "ge?ks*";
        string pattern = "geeksforgeeks";

        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";

        return 0;
}
// } Driver Code Ends