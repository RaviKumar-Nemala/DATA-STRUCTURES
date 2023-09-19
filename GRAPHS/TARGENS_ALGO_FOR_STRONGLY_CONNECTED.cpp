#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#define n 7
vector<int>temp[n];
void dfs(int node,vector<int>&low,vector<int>&disc,vector<int>&visit,stack<int>&st,vector<bool>&stack_elements){
     visit[node]=1;
     static int time=0;
     time++;
     low[node]=disc[node]=time;
     stack_elements[node]=true;
     st.push(node);
     for(auto it:temp[node]){
          if(visit[it]==0)
          {
               dfs(it,low,disc,visit,st,stack_elements);
               
               low[node]=min(low[it],low[node]);
          }
          else if(stack_elements[it]==true){
               low[node]=min(low[it],disc[node]);
          }
     }

     if(low[node]==disc[node]){
          cout<<"the scc is : ";
          while(st.top()!=node){
               cout<<st.top()<<" ";
               stack_elements[st.top()]=false;
               st.pop();
          }
          cout<<st.top()<<" ";
          stack_elements[st.top()]=false;
          st.pop();
          cout<<"\n";
     }
}
void targens_algo(){
     vector<int>visit(n,0);
     vector<int>low(n,0);
     vector<int>disc(n,0);
     vector<bool>stack_elements(n);
     for(int i=0;i<n;i++){
          stack_elements[i]=false;
     }
     stack<int>st;
     for(int i=0;i<n;i++){
          if(!visit[i]){
               dfs(i,low,disc,visit,st,stack_elements);
          }
     }
}

int main()
{
    temp[0].push_back(1);
     temp[1].push_back(2);
     temp[1].push_back(3);
     temp[3].push_back(4);
     temp[4].push_back(0);
     temp[4].push_back(5);
     temp[4].push_back(6);
     temp[5].push_back(6);
     temp[6].push_back(5);
     
     targens_algo();
}