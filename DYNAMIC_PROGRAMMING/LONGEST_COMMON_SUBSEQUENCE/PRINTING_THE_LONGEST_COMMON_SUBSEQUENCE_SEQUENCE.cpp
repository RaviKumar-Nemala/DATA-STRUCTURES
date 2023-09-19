#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<cstring>
#include<cstdlib>
class Longest_Common_Substring{
     public:

     void  LENGTH_OF_COMMON_SUBSTRING(string a,string b){
               util_lcs(a,b,a.length(),b.length());
     }

     private:

     void util_lcs(string a,string b,int n1,int n2){
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

          
           i=n1,j=n2;
           int index=dp[n1][n2];
           //vector<char>result(dp[n1][n2]);
               char result[index+1];
               result[index]='\0';
          //dp[n1+1][n2+1];
          while(i>0 && j>0){
               if(a[i-1]==b[j-1]){
                   result[index-1]=a[i-1];
                   index--;
                    i--;
                    j--;
               }
               else if(dp[i-1][j]>dp[i][j-1]){
                    i--;
               }
               else{
                    j--;
               }
          }

          cout<<"LCS OF "<<a<<" AND "<<b<<" is = " <<result<<endl;
          cout<<"PRINTING THE LENGTH OF THE SUBSEQUENCE : "<<dp[n1][n2];

     }
};
int main(){
     string a="abcdef";
     string b="abdefg"; 
     /*a= "AGGTAB" ;
     b= "GXTXAYB";
     */
     Longest_Common_Substring obj;
     obj.LENGTH_OF_COMMON_SUBSTRING(a,b);

}