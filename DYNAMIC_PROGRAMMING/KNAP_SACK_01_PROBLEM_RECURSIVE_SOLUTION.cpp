#include<iostream>
#include<algorithm>
#include<climits>
int knapsack(int wt[],int val[],int max_wt,int n){
     if(n==0||max_wt==0){
          return 0;
     }
     if(wt[n-1]<=max_wt){
          return std::max(val[n-1]+knapsack(wt,val,max_wt-wt[n-1],n-1),knapsack(wt,val,max_wt,n-1));
     }
     else if(wt[n-1]>=max_wt){
          return knapsack(wt,val,max_wt,n-1);
     }
}
int main(){
     int wt[]={20,30,25,40};
     int val[]={50,20,10,30};
     int max_wt=50;
     std::cout<<knapsack(wt,val,max_wt,4);
}