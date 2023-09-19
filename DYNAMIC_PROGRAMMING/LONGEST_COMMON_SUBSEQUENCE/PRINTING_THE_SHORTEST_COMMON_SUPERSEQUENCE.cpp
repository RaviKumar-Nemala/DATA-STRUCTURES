#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class solution{
     public:

     void shortest_common_supersequence(string a,string b){

          print_shortest_common_sequence(a,b,a.length(),b.length());

     }
      
     private:

     void print_shortest_common_sequence(string a,string b,int n1,int n2){

               int i,j;
          int dp[n1+1][n2+1];
          vector<char>st;


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
           
           //here is the printing procedure starts//

           i=n1,j=n2;
          while(i>0 && j>0){
               if(a[i-1]==b[j-1]){
                    st.push_back(a[i-1]);
                    i--,j--;
               }
               else if(dp[i][j-1] > dp[i-1][j])
               {
                    st.push_back(b[j-1]);
                    j--;
               }
               else{
                    st.push_back(a[i-1]);
                    i--;
               }
          }

          while(j>0)
          {
               st.push_back(b[j-1]);
               j--;
          }
          
          while(i>0){
               st.push_back(a[i-1]);
               i--;
          }
          
          reverse(st.begin(),st.end());
          for (auto it:st)
          cout<<it<<" ";
     }

};

int main(){
     string a="abcdgh";
     string b="acbght";
     /*
     a="AGGTAB";
     b="GXTXAYB";*/
     solution obj;
     obj.shortest_common_supersequence(a,b);
}