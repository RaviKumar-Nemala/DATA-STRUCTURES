#include<iostream>
using namespace std;
#include<vector>
vector<int>ans;
class dfs{
     public:
     void dfs_util(int node,vector<int>&visit,vector<int>adj[]){
          visit[node]=1;
          ans.push_back(node);//either we can store out answer or we can print it DFS ALWAYS GIVES THE PRE ORDER TRAVERSAL
          //cout<<node;
          for(auto i:adj[node]){
               if(visit[i]==0){
                    dfs_util(i,visit,adj);
               }
          }
     }
     void dfs_search(int n,vector<int>adj[])
     {
          vector<int>visit(n+1,0);
          for(int i=1;i<=n;i++){
               if(visit[i]==0){
                    dfs_util(i,visit,adj);
               }
          }
     }
     void add_edge(int v,int u,vector<int>temp[]){ //ADDING THE NODES INTO THE TEMP VECTOR
          temp[u].push_back(v);
          temp[v].push_back(u);
     }
};
int main(){
     dfs obj;
     int n, m;
     vector<int>adj[100];
     int u,v;
     cout<<"enter the n : ";
     cin>>n;
     cout<<"enter the m: ";
     cin>>m;+1;
     for(int i=0;i<m;i++){
          cin>>u;
          cin>>v;
          obj.add_edge(u,v,adj);
     }
     obj.dfs_search(n,adj);

     for(auto it:ans)
     cout<<it<<" ";
}