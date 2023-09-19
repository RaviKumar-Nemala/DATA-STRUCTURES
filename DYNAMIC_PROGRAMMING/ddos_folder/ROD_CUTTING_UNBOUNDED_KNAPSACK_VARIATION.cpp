#include<iostream>
using namespace std;
#include<vector>
class cutting_rod_max_profit{
     public:
     int max_profit(int rod_length,vector<int>price,vector<int>&length){
           int array_length=length.size();
          //cout<<n<<" ";
          //int array_length=sizeof(length)/sizeof(length[0]);
               int dp[array_length+1][rod_length+1];
               register int i,j;
               for(i=0;i<=rod_length;i++){
                    for(j=0;j<=array_length;j++){
                         if(i==0||j==0){
                              dp[i][j]=0;
                         }
                         else if(j<length[i-1]){ 
                              dp[i][j]=dp[i-1][j];
                         }
                         else{      
                              dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
                         }
                    }
               }
               return dp[array_length][rod_length];
     }
};
int main(){
     vector<int>length={1,2,3,4,5,6,7,8};
     vector<int>price={1,5,8,9,10,17,17,20};
     int rod_length=8;
     cutting_rod_max_profit obj;
     cout<<obj.max_profit(rod_length,price,length);
}