#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class solution{
     public:

     void  Min_Insertions_And_Delelions(string str1,string str2){
          int str1_length=str1.length();
          int str2_length=str2.length();
          int lcs=find_lcs(str1,str2,str1_length,str2_length);
          Util_Minimum_Deletions(str1,str2,str1_length,lcs);
          Util_Minimum_Insertions(str1,str2,str2_length,lcs);
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

     void Util_Minimum_Deletions(string str1,string str2,int str1_length,int lcs_lenght){
               int min_del=str1_length-lcs_lenght;
               cout<<"PRINTING THE NO OF DELETIONS TO CONVERT "<<str1<<" TO "<<str2<<" ARE: "<<min_del<<endl;
     }

     void Util_Minimum_Insertions(string str1,string str2,int str2_length,int lcs_lenght){
          int min_inst=str2_length-lcs_lenght;
            cout<<"PRINTING THE NO OF INSERTIONS TO CONVERT "<<" \" "<<str1<<" \" "<<" TO "<<" \" "<<str2<<" \" "<<" ARE: "<<min_inst;
     }
};

int main(){
     string a="heap";
     string b="pea";
     solution obj;
     obj.Min_Insertions_And_Delelions(a,b);
}