#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int dp[100][100][2];
class Solution{
     public:
     
          int  boolean_paranthesization(string s){
               
               int first_index=0;
               int last_index=s.length()-1;
               bool is_true=true;
              return no_of_ways_paranthesize(first_index,last_index,s,is_true);

          }

     private:
          int no_of_ways_paranthesize(int i , int j , string s,bool is_true){
               if(i>j)
                    return 0;
               
               if(dp[i][j][is_true]!=-1)
               return dp[i][j][is_true];

               if(i==j)
               {
                    if(is_true){
                         return s[i]=='T';
                    }
                    else{
                         return s[i]=='F';
                    }
               }
                          int ans=0;
               for(int k=i+1; k<=j-1; k+=2)
               {
                    int left_true,right_true,left_false,right_false;
                   if(dp[i][k-1][1]==-1)
                    left_true=no_of_ways_paranthesize(i,k-1,s,true);
                    else
                         left_true=dp[i][k-1][1];

                    if(dp[k+1][j][1]==-1)
                     right_true=no_of_ways_paranthesize(k+1,j,s,true);
                    else
                         right_true=dp[k+1][j][1];
                    

                    if(dp[i][k-1][0]==-1)
                     left_false=no_of_ways_paranthesize(i,k-1,s,false);
                    else 
                    left_false=dp[i][k-1][0];
                    
                    if(dp[k+1][j][0]==-1)
                     right_false=no_of_ways_paranthesize(k+1,j,s,false);
                     else
                     right_false=dp[k+1][j][0];

               if(s[k]=='|'){
                    if(is_true){

                    ans+=(left_true*right_true)+(left_true*right_false)+(left_false*right_true);
                    }
                    else
                    {
                         ans+=(left_false*right_false);
                    }
               }
               else if(s[k]=='&'){
                    if(is_true){
                         ans+=(left_true*right_true);
                    }
                    else{
                         ans+=(left_true*right_false)+(left_false*right_true)+(left_false*right_false);
                    }
               }
               
               else if(s[k]=='^'){
                    if(is_true){
                         ans+=(left_true*right_false)+(left_false*right_true);
                    }
                    else{
                         ans+=(left_false*right_false)+(left_true*right_true);
                    }
               }
                    dp[i][j][is_true]=ans;
               }
          return ans;
          }
};


int main(){
     //string s="T|F^F&T";
     string s="T|T&F^T";
     memset(dp,-1,sizeof(dp));
     Solution obj;
     cout<<obj.boolean_paranthesization(s);
}