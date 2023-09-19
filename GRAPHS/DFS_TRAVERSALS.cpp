#include<iostream>
using namespace std;
#include<vector>
#include<queue>
class solution{
     public:
     void dfs(int node,vector<int>&ans,vector<int>&visited,vector<int>adj[]){
          ans.push_back(node);
          visited[node]=1;
          for(auto i: adj[node]){
               if(!visited[i]){
               dfs(i,ans,visited,adj);
          }
          }
     }
     void main_dfs(int v,vector<int>adj[]){
          vector<int>ans;
          vector<int>visited(v+1,0);
          for(int i=1;i<=v;i++){
               if(!visited[i]){
                    dfs(i,ans,visited,adj);
               }
          }
          for(auto i:ans)
          cout<<i<<" ";
     }
};
     int main(){
     int u,v;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector<int>temp[n+1];
     int i;
     for(i=0;i<m;i++){
          fflush(stdin);
          cin>>u;
          fflush(stdin);
          cin>>v;
          temp[u].push_back(v);
          temp[v].push_back(u);//for undirected graph//
     }
     solution obj;
     obj.main_dfs(n,temp);
}