#include<iostream>
using namespace std;
#include<algorithm>
#define n 5
#include<vector>
#define pb push_back
vector<int>temp[n];
vector<pair<int,int>>bridge;
void dfs(int node,vector<int>&disc,vector<int>&low,vector<int>&parent){
     static int time=0;
     disc[node]=low[node]=time;
     time++;
     for(auto it:temp[node]){
          if(!disc[it]){
               parent[it]=node;
               dfs(it,disc,low,parent);
               low[node]=min(low[node],low[it]);
               if(low[it]>disc[node]){ //low[it] should not be greater then or equal to the codition if incase of the cyclic then greater then or equal condition is not giving the proper results//
                    bridge.push_back({node,it});
               }
          }
          else if(it!=parent[node]){
               low[node]=min(low[node],disc[it]);
          }
     }
}

void find_bridge(){
     vector<int>disc(n,0);
     vector<int>parent(n,-1);
     vector<int>low(n,0);
     for(int i=0;i<n;i++){
          if(!disc[i]){
               dfs(i,disc,low,parent);
          }
     }
     for(auto it:bridge){
          cout<<it.first<<" "<<it.second<<endl;
     }
}


int main(){
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
find_bridge();
}