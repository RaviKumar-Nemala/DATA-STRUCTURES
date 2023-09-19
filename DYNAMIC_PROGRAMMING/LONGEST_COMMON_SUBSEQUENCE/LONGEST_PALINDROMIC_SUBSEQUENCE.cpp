#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<string>
class solution{

     public:
     int Longest_Palindromic_Subsequence(string str1){
          int str1_len=str1.length();
         // cout<<str1_len;
         // string str2=reverse(str1,str1+str1_len);
         string str2=string(str1.rbegin(),str1.rend());
         int str2_len=str2.length();

         /*
         string str2;int  i,j;
               char ch=']';
               i=str1_len-1;
               j=0;
        while(ch!='\0'){ 
             
             ch=str1[i];
             str2[j]=ch;
             i--,j++;
        }
        str2[j]='\0';
        */
          int result=LCS(str1,str2,str1_len,str2_len);
          return (str1_len-result);
     }

     private:

     int LCS(string a,string b,int n1,int n2)
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
     string a= "agbcba";//here second string is b:rev(a); NOW find the lcs on these both strings and THE NO DELETION TO MAKE THIS STRING AS LONGEST PALINDROMIC SUBSTRINS IS SIZEOF(sTRING - LCS)//
     solution obj;
     cout<<obj.Longest_Palindromic_Subsequence(a);
}
