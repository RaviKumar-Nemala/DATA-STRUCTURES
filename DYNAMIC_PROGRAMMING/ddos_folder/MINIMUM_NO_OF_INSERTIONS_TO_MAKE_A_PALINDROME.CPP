#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{
     public:
     int Minimum_Insertios_To_Make_Palindrome(string a){
          string b=string(a.rbegin(),a.rend());
          int palidrome_length= Minimum_Insertions_Util(a,b,a.length(),b.length());    
          int no_of_insertions=a.length()-palidrome_length;
          return no_of_insertions;   
     }

     private :

     int Minimum_Insertions_Util(string a,string b,int n1,int n2){
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
     string a="aebcbda";//here is the program which find the minimum no of insertions that we need to make this string as the palindrome //
     Solution obj;
     
     //this is similar to longest paldromic subsequences after fiding the lps we need to substract that lps from our main string length then we  get the minum no of insertions//

     int no_of_insertions=obj.Minimum_Insertios_To_Make_Palindrome(a);
     cout<<no_of_insertions;
}