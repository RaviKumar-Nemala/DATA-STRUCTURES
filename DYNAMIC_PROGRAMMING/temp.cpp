//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void permutation( string str , int idx  , vector < string > &res  )
    {
        int n = str.size()  ; 
        
        if ( idx == n )
        {
             res.push_back ( str ) ; 
             return;
        }
        char ch  = str [ idx ] ; 
        for( int i = idx ; i < n ; i ++  )
        {
             swap( str[ i ] , str [ idx ]  ) ;
             permutation( str ,  i + 1  , res ); 
        }
        str[ idx] = ch ; 
        return;
    }
    
	public:
		vector<string>find_permutation(string S)
		{
		   vector <string > res; 
		   permutation ( S ,  0 , res ) ;
		   return res;
		}
};



//{ Driver Code Starts.
int main(){
   
	    string S = "ABC";
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);    
        for ( auto it : ans )  
            cout << it << endl;
	return 0;
}

// } Driver Code Ends