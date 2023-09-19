#include<iostream>
using namespace std;
#include<vector>
int dp[100][100]={-1};
int i,j;
void initilize(){
for(i=0;i<100;i++)
{
	for(j=0;j<100;j++)
	dp[i][j]=-1;
}
}

int knap_sack(int wt[],int val[],int max_wt,int n)
{
     if(n==0||max_wt<=0)
     return 0;
     if(dp[n][max_wt]!=-1){
          return dp[n][max_wt];
     }
     else if(wt[n-1]<=max_wt){
          return dp[n][max_wt]=max(val[n-1]+knap_sack(wt,val,max_wt-wt[n-1],n-1),knap_sack(wt,val,max_wt,n-1));
     }
     else {
          return dp[n][max_wt]=(knap_sack(wt,val,max_wt,n-1));
     }
}

	int main(){
     int wt[]={20,30,25,40};
     int val[]={50,20,10,30};
     int max_wt=50;
   initilize();
     std::cout<<knap_sack(wt,val,max_wt,4);
}