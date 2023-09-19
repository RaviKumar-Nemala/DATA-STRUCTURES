#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    bool isMatch(string s, string p) {
         int n1=p.length();
       int n2=s.length();
       bool dp[n1+1][n2+1];
       int i,j;
       char p_char,s_char;
       char ch;
        for(i=0;i<=n1; i++)
        {
            for(j=0;j<=n2;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j]=true;
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(j==0)
                {
                    ch = p[i-1];
                    if(ch == '*')
                    {
                        dp[i][j] = dp[i-2][j];
                    }
                    else 
                    {
                        dp[i][j]=false;
                    }
                }
                else 
                {
                    p_char=p[i-1];
                    s_char=s[j-1];
                    if(p_char == s_char)
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p_char == '*')
                    {
                        dp[i][j] = dp[i-2][j];
                        
                        char previous =  p[i-2]; //this is the case if we have ".*" in our pattern string then we have several options either we can look up on two rows above or we can left that char because of '.'chare is there  //
                        if(previous == s_char  || previous=='.') 
                        {
                            dp[i][j] = dp[i][j] || dp[i][j-1]; //dp[i][j-1]  is used if '.' char is replaced with the string char //dp[i][j] which is already calculted on above it used if    ".*" is ignored then we need look up on the two above"                     }
                    }
                    else if(p_char == '.')
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else {
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[n1][n2];
        
     }
}
};
int  main(){
    // string s1="mississippi";
     //string s2="mis*i.*p*i";
     string s1="missi";
     string s2="mis*i";
     s1="missi";
     s2="miss*i";
     Solution obj;
    cout<<obj.isMatch(s1,s2);
}
