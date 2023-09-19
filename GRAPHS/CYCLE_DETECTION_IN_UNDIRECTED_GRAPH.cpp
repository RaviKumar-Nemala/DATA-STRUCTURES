#include<iostream>
using namespace std;
#include<vector>
class solution{
     public:
     bool is_cycle(int node,int parent,vector<int>&visited,vector<vector<int>>adj){
          visited[node]=1;
          for(auto it:adj[node]){
               if(!visited[it]){
               if(is_cycle(it,node,visited,adj))
               return true;
              } else if(it!=parent)
                    return true;
          }
          return false;
     }
     bool cycle_detect(int n,vector<vector<int>>adj){
          vector<int>visited(n+1,0);
          for(int i=0;i<n;i++){
               if(!visited[i]){
                    if(is_cycle(i,-1,visited,adj))
                    return true;
               }
          }
          return false;
     }
};
int main(){
     int u,v;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector<vector<int>>temp(n+1);
     int i;
     for(i=0;i<m;i++){
          cin>>u;
          cin>>v;
          temp[u].push_back(v);
          temp[v].push_back(u);//for undirected graph//
     } 
     solution obj;
bool cycle=obj.cycle_detect(n,temp);
if(cycle)
cout<<"there is a cycle";
else{
     cout<<"there is no cycle";
}
}