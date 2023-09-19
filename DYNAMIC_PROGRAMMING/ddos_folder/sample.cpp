#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution
{

     public:
          int  edit_distance(string S1, string S2)
          {
               int n1=S1.length();
               int n2=S2.length();
               return edit_distance_util(S1,S2,n1,n2);
          }

          int edit_distance_util(string S1, string S2, int n1, int n2)
          {
               int dp[n1+1][n2+1];
               int i,j;
               for(i=0;i<=n1;i++)
               {
                    dp[i][0]=i;
               }
               for(i=0;i<=n2;i++)
               {    
                    dp[0][i]=i;
               }

               for(i=1;i<=n1;i++)
               {
                    for(j=1;j<=n2;j++)
                    {
                         if(S1[i-1] == S2[j-1])
                         {
                              dp[i][j]=dp[i-1][j-1];
                         }
                         else {
                         dp[i][j] = 1+min( dp[i-1][j]  , min(dp[i][j-1] , dp[i-1][j-1]));
                         }
                    }
               }
               return dp[n1][n2];
          }

          int util(string a , string b , int n1 , int n2 )
          {
               int i , j ; 
               int dp[n1+1][n2+1];

               for ( i = 0 ; i <= n1 ; i ++)
               {
                    dp[i][0] = i ;
               } 

               for ( j = 0 ; j <= n2 ; j ++)
               {
                    dp[0][j] = j ;
               }

               for  ( i = 1 ; i<=n1 ;i ++)
               {
                    for ( j =1 ; j <= n2 ; j++)
                    {
                         if ( a[i-1] == b[j-1] )
                         dp[i][j] = dp[i-1][j-1];
                         else
                         dp[i][j] = 1 + min(dp[i][j-1] , min(dp[i-1][j] , dp[i-1][j-1]));
                    }
               }
               return dp[n1][n2];
          }
};

int main()
{
	// your code goes here
	string str1 = "sunday";
	string str2 = "saturday";
     Solution obj;
	cout << obj.edit_distance_util(str1, str2, str1.length(), str2.length());
     cout<<obj.util(str1,str2,str1.length() ,  str2.length());
	return 0;
}

