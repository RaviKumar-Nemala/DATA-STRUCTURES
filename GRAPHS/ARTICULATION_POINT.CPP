#include<iostream>
using namespace std;
#include<algorithm>
#define n 5
#include<vector>
#define pb push_back
vector<int>temp[n];
void dfs(int node,vector<int>&disc,vector<int>&parent,vector<int>&low,vector<bool>&ap){
     static int time=0;
     disc[node]=low[node]=time;
     time++;
     int child=0;
     for(auto it:temp[node]){
          if(disc[it]==0){
               child++;
               parent[it]=node;
               dfs(it,disc,parent,low,ap);
               low[node]=min(low[node],low[it]);
               if(child > 1 and parent[node]==-1){
                    ap[node]=true;
               }
               
               if(low[it]>=disc[node] and  parent[node]!=-1){
                    ap[node]=true;
               }
          }
          else if(it!=parent[node])//this is used to find the backedge if  "node" has adj element i.e it and it is already visited and that it is not came from the node that is why we use it!=parent[node]//
               low[node]=min(low[node],disc[it]);
          }
     }
void articulation_points(){
     vector<int>disc(n,0);
     vector<int>low(n,0);
     vector<int>parent(n,-1);
     vector<bool>ap(n,false);
     for(int i=0;i<n;i++){
          if(disc[i]==0)
          dfs(i,disc,parent,low,ap);
     }
     for(int i=0;i<n;i++){
          if(ap[i]==true)
          cout<<i<<" ";
     }
}
int main()
{
     /*
  temp[0].push_back(1);
   temp[0].push_back(3);
   temp[0].push_back(2);
   temp[1].push_back(0);
   temp[1].push_back(2);
   temp[2].push_back(0);
   temp[2].push_back(1);
   temp[3].push_back(4);
   temp[3].push_back(5);
   temp[3].push_back(0);
   temp[4].push_back(3);
   temp[5].push_back(3);
   */
   
     temp[0].pb(2);
	temp[2].pb(0);
	temp[0].pb(3);
	temp[3].pb(0);
	temp[1].pb(0);
	temp[0].pb(1);
	temp[2].pb(1);
	//adj[2].pb(4);
	//adj[4].pb(2);
	temp[1].pb(2);
	temp[3].pb(4);
	temp[4].pb(3);

     articulation_points();
}