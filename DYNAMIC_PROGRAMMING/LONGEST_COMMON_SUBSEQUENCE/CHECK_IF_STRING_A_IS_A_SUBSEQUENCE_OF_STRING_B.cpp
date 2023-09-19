#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{
     public:
     bool Check_If_Subsequence_Or_Not(string a,string b){
          int a_length=a.length();
          int b_length=b.length();
          int lcs= Util_Subsequence(a,b,a_length,b_length);
          if(lcs==a.length()){
               return true;
          }
          else
          return false;
     }

     private:
     
     int Util_Subsequence(string a,string b, int n1,int n2){
          int i,j;
          int dp[n1+1][n2+1];

          for(i=0;i<=n1;i++){
               for(j=0;j<=n2;j++){
                    if(i==0||j==0){
                         dp[i][j]=0;
                    }
                    else if(a[i-1]==b[j-1]){
                         dp[i][j]=dp[i-1][j-1]+1;
                         //result_length=max(result_length,dp[i][j]);
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
     string a="AXY";
     string b="ADXCPY";
     Solution obj;
     bool result=obj.Check_If_Subsequence_Or_Not(a,b);
     if(result)
     cout<<"given string : "<<" \" "<<a<<" \" "<<"is a subsequence of"<<" string : "<<"\""<<b<<" \"";
}