#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class solution{
     public:
     int Longest_Repeating_Subsequencce(string str1){
          int str1_length=str1.length();
          string str2=string(str1.rbegin(),str1.rend());
          int str2_length=str2.length();
          return Find_Lps_Util(str1,str2,str1_length,str2_length);
     }
     private:
     int Find_Lps_Util(string str1,string str2,int n1,int n2)
     {
          int dp[n1+1][n2+1];
          int i,j;
          
          for(i=0;i<=n1;i++){
               for(j=0;j<=n2;j++){
                    if(i==0||j==0){
                         dp[i][j]=0;
                    }
                    else if(str1[i-1]==str2[j-1] && i!=j)
                    {
                         dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else {
                         dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }
               }
          }

          return dp[n1][n2]; 
     }
};

int main(){
     string a="AABEBCDD"; //here is the program which finds the length of the longest repeating subsequnces//
     //IN THIS CASE SEQUENCE "ABD" IS REPEATING AND IT IS LARGE AMONG ALL OTHER STRINGS//
     //SO THE OUTPUT IS 3 SINCE THE LENGTH OF THE SEQUENCE IS 3//
     solution obj;
     int result=obj.Longest_Repeating_Subsequencce(a);
     cout<<result;
}