#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Longest_Common_Substring{
     public:
     int LENGTH_OF_COMMON_SUBSTRING(string a,string b){
          return util_lcs(a,b,a.length(),b.length());
     }
     private:
     int util_lcs(string a,string b,int n1,int n2){
          int i,j;
          int result_length=INT_MIN;
          int dp[n1+1][n2+1];
          for(i=0;i<=n1;i++){
               for(j=0;j<=n2;j++){
                    if(i==0||j==0){
                         dp[i][j]=0;
                    }
                    else if(a[i-1]==b[j-1]){
                         dp[i][j]=dp[i-1][j-1]+1;
                         result_length=max(result_length,dp[i][j]);
                    }
                    else{
                         dp[i][j]=0;
                    }
               }
          }
          return result_length;
     }
};
int main(){
     string a="abcdef";
     string b="abdefik";  //common substr =3=="def"//
    Longest_Common_Substring obj;
    int result=obj.LENGTH_OF_COMMON_SUBSTRING(a,b);
    cout<<result<<" ";

}