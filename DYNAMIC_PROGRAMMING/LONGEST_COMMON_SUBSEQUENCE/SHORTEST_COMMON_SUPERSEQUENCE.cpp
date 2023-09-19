#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Shortest_Common_Superseqeunce{
    public:
          int length_of_shortest_supersequence(string str1,string str2){
               int str1_length=str1.length();
               int str2_length=str2.length();
               int lcs=find_lcs(str1,str2,str1_length,str2_length);
               int result=0;
               result=str1_length+str2_length-lcs;
               return result;
          }

     private:
          int find_lcs(string a,string b,int n1,int n2)
    {
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
     string a="geek";
     string b="eke";
     //here we need to find the shortest string which contains the both string a and string b  in this case the result strins is : GEEKE and length=5//
     Shortest_Common_Superseqeunce obj;
     cout<<obj.length_of_shortest_supersequence(a,b);
}
