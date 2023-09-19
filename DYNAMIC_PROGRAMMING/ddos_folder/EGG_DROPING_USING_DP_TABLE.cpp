#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{
     public:
          int Egg_Drop(int n , int k){
               int dp[n+1][k+1];
          int i , j, res , min =INT_MAX;
               for( i=1;i<=n;i++){
                     dp[i][1]=1;
                     dp[i][0]=0;
               }

               for(j=1;j<=k;j++){
                    dp[1][j]=j;
               }
               
               for(i=2; i<=n; i++) {
                    for(j = 2 ; j <= k ;  j++){
                         dp[i][j]=INT_MAX;
                         for(int x=1;x<=j;x++){

                         res= 1 + max(dp [i-1][x-1] , dp[i][j-x]);

                         if(res < dp[i][j])
                         dp[i][j]=res;

                         }
                    }
               }
               return dp[n][k];
               
          }
};

int main(){
     Solution obj;
     int no_of_eggs=2;
     int no_of_floors=36;
     cout<<obj.Egg_Drop(no_of_eggs , no_of_floors);
}