#include<bits/stdc++.h>
using namespace std;
class Solution{
     public:
          bool is_match ( string s1 , string s2 , string s3 )
          {
               int i = 0 , j;
               int n1 = s1.size();
               int n2 = s2.size();
              // vector<vector<bool > > dp (s1.length() +1 ,vector<bool > ( s2.length() +1 ) );
              bool dp[s1.length() +1 ][s2.length() + 1 ];
              memset(dp , false , sizeof(dp));

               for ( i = 0 ;i  <= n1 ; i ++ ){
                for( j = 0 ; j <= n2 ; j++ )
                { 
                     if(i== 0 && j==0)
                     dp[i][j] = true;
                    else if(i==0)
                    {
                         if(s2[j-1] ==  s3[ i+j - 1 ]) 
                         dp[i][j] =  dp[i][j-1];
                    }
                    else if( j == 0) {
                           if (s1[i-1] == s3[i+j - 1 ] ) 
                          dp[i][j] = dp[i-1][j];
                    }
                     else if (s1[i-1] == s3[i+j-1]  && s2[j-1] != s3[i+j-1] )
                     {
                          dp[i][j] = dp[i-1][j];
                     }
                     else if(s1[i-1] != s3[i+j-1]  and s2[j-1] == s3[ i+j-1] ){
                         dp[i][j] =  dp[i][j-1];
                     }
                     else if(s1[i-1] ==  s3[i+j-1]  and s2[j-1] ==  s3 [ i + j - 1 ] )
                     dp[i][j] = (dp[i][j-1] ||  dp[i-1][j]);
                }
          }

     for( i = 0 ; i <= n1 ; i ++ )
     {
          for  ( j = 0  ; j <=n2 ; j ++ )
          cout<<dp[i][j]<<" ";
          cout<<"\n";
     }
return dp[n1][n2];
}
};

int main() {
      string s1,s2,s3;
      s1 = "aabcd";
      s2 =  "abade";
      s3 = "abade";
      s1 = "XXY", s2 =  "XXZ" , s3 ="XXZXXY";
      Solution obj ;
      cout << obj.is_match("XY", "X", "XXY" );
}