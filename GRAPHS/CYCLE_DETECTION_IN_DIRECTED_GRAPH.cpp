#include<iostream>
using namespace std;
#include<vector>
class solution{
     public:
     bool is_cycle(int node,vector<int>&visited,vector<int>&bfs_visited,vector<int>adj[]){
          visited[node]=1;
          bfs_visited[node]=1;
          for(auto it:adj[node]){
               if(visited[it]==0){//if inc case node is not visited then only execute this 
               if(is_cycle(it,visited,bfs_visited,adj)){
                    return true;
               }
          }
          else if(bfs_visited[it]){//in case if the node is visited and also it is already presented int bfs_visited then we say there is a cycle in it that is why we use bfs not visited array becaz we need to check both cases //
               return true;
          }
          }
          bfs_visited[node]=0;//if a particular node bfs path has happeend after that we need to make that node value as 0 becaz of this is a directed graph //
          return false;
     }
     bool cycle_detect(int v,vector<int>adj[]){
          int i;
          vector<int>visit(v+1,0);
          vector<int>bfs_visit(v+1,0);
          for(i=1;i<=v;i++){
               if(visit[i]==0){
                    if(is_cycle(i,visit,bfs_visit,adj)){
                         return true;
                    }
               }
          }
          return false;
     }
};

int main(){
     /* i/p ->    1->2->3
                     |  |
                     up   below direction
                     5<-4
                     */
     int u,v;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
    vector<int>temp[20];
     int i;
     for(i=0;i<m;i++){
          cin>>u;
          cin>>v;
          temp[u].push_back(v);
          //temp[v].push_back(u);//for directed graph//
     }
     solution obj;
bool cycle=obj.cycle_detect(n,temp);
if(cycle)
cout<<"there is a cycle";
else{
     cout<<"there is no cycle";
}
}

