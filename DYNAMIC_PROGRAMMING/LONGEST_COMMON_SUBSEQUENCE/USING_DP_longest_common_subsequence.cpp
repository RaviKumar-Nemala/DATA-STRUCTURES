#include<iostream>
using namespace std;
#include<algorithm>

class LCS{
     public:
     int longest_common_subsequence(string a,string b){
          int n1=a.length();
          int n2=b.length();
          int i,j;
          int dp[n1+1][n2+1];
          for(i=0;i<=n1;i++){
               for(j=0;j<=n2;j++){
                    if(i==0||j==0){
                         dp[i][j]=0;
                    }
                    else if(a[i-1]==b[j-1]){
                         dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else{
                         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
               }
          }
          return dp[n1][n2];
     }
};
int main(){
     string a="abcdef";
     string b="abdefik"; //lcs=abdef len=5//
     LCS obj;
   int result= obj.longest_common_subsequence(a,b);
   cout<<result<<" ";
}