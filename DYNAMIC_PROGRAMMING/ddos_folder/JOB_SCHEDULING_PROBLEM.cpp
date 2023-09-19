#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<algorithm>
struct job
{
     int start , end ,profit;
};
typedef struct job job;
class Solution{
     private :
          int check_time_compatability( job temp[] , int i)
          {
               int j;
               for( j = i-1  ; j >= 0 ; j--)
               {
                    if(temp[j].end <= temp[i].start)
                    {
                         return j;
                    }
               }
               return -1;
          }
          bool jobComparator( job temp1 ,  job temp2)
          {
               if(temp1.end < temp2.end) return true;
               else return false;
          }
     public : 
          int job_schedule_max_profit( job temp[]  , int n)
          {
               int i, j;
               if(n==1)
               {
                    return temp[n-1].profit;
               }
               //sort(temp ,temp+n , jobComparator);
               int dp[n];
               dp[0]=temp[0].profit;
               for(i=1 ; i < n; i ++)
               {    
                    int included_profit = temp[i].profit;
                    int  timings = check_time_compatability(temp , i);
                    if(timings  != -1)
                    {
                         included_profit+=dp[timings ];
                    }
                         dp[i] = max(dp[i-1] , included_profit);
               }
               return dp[n-1];
          }
};

int main(){
     int n;
     cout<<"enter the n value : ";
     cin>>n;
     struct job var[n];
     int start,end,profit;
     int i;
     for(i=0;i<n;i++)
     {
          cin>>start>>end>>profit;
          var[i].start=start;
          var[i].end = end;
          var[i].profit = profit;
     }
     Solution obj;
     cout<<obj.job_schedule_max_profit(var , n );
}
