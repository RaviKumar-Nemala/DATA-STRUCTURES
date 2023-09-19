#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution{

     public:
     int Palidrome_Partioning(string s){
          int starting_index=0;
          int last_index=s.length()-1;
          int n=s.length();

          vector<vector<int> >dp(n+1,vector<int>(n+1 , -1));

          return Min_Partions(starting_index,last_index,s,dp);
     }

     private:

     bool Is_Palindrome(int i, int j , string s ){
          while(i < j){
               
               if(s[i] == s[j])
               {
                    i++;
                    j--;
               }
               else{
                    return false;
               }
          }

          return true;
     }

          int Min_Partions(int i , int j , string &s,vector<vector< int> > &dp){
               if(i >= j)
               return 0;

          if(Is_Palindrome( i , j , s))
               return 0;

               if( dp[i][j] !=-1){
                    return dp[i][j];
               }   

               int minimum=INT_MAX;
               int temp;
               
               for(int k=i; k<=j-1 ; k++){

                    temp = Min_Partions(i,k,s,dp) + Min_Partions(k+1,j,s,dp) + 1;

                    if( temp < minimum){
                         minimum = temp;
                    }

               }
               dp[i][j]=minimum;
               return   minimum;
               //return  minimum;
          }

};


int main(){

     string s="cbabd";
    // s="ababbbabbababa";
     Solution obj;
     cout<<obj.Palidrome_Partioning(s);
}

