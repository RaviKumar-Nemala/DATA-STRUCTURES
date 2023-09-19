#include<iostream>
using namespace std;
#include<vector>
#include<queue>
vector<int>ans;//global reference of the ans for easy access//
class solution{
     public:
     void  bfs_traversals(int v,vector<int>adj[]){
          int i;
          //vector<int>ans;
          vector<int>visited(v+1,0);
          for(i=1;i<=v;i++){
               if(!visited[i]){
                    visited[i]=1;
                    queue<int>q;
                    q.push(i);
                    while(!q.empty()){
                         int node=q.front();
                         ans.push_back(node);
                         q.pop();
                         for(auto it:adj[node]){
                              if(!visited[it]){
                              q.push(it);
                              visited[it]=1;
                         }
                         }
                    }
               }
          }
          //return ans;
          /*for(auto i:ans){
               cout<<i<<" ";
          }*/
     }
     void print_ans(){
          for(auto i:ans){
               cout<<i<<" ";
          }
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
          cin>>u;
          cin>>v;
          temp[u].push_back(v);
          temp[v].push_back(u);//for undirected graph//
     }
     solution obj;
    obj.bfs_traversals(n,temp);
    obj.print_ans();
     //obj.print_ans(ans);
}    