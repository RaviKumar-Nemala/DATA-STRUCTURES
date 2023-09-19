#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Longest_Common_Substring{

     public:
     void  LENGTH_OF_COMMON_SUBSTRING(string a,string b){
         util_lcs(a,b,a.length(),b.length());
     }

     private:

     void util_lcs(string a,string b,int n1,int n2){
          int i,j;
          int result_length=INT_MIN;
          int dp[n1+1][n2+1];
          int row,col;
          for(i=0;i<=n1;i++){
               for(j=0;j<=n2;j++){
                    if(i==0||j==0){
                         dp[i][j]=0;
                    }
                    else if(a[i-1]==b[j-1]){
                         dp[i][j]=dp[i-1][j-1]+1;

                       if(result_length<dp[i][j]){
                            result_length=dp[i][j];
                         row=i;
                         col=j;
                    }
                    }
                    else{
                         dp[i][j]=0;
                    }
               }
          }
          char result[result_length+1];
          result[result_length]='\0';

//char *result=(char*)(malloc(sizeof(result_length+1)));

               while(dp[row][col]!=0){
                    result[--result_length]=a[row-1];
                    row--;
                    col--;
               }
cout<<result;
     }
};
int main(){
     string a="abcdef";
     string b="abdefik";  //common substr =3=="def"//
    Longest_Common_Substring obj;
    obj.LENGTH_OF_COMMON_SUBSTRING(a,b);

}