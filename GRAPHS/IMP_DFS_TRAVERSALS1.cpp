#include<iostream>
using namespace std;
#include<vector>
vector<int>temp[30];
void dfs(int node,vector<int>&Visit){
     Visit[node]=1;
     cout<<node<<" ";
     for(auto it:temp[node]){
          if(Visit[it]==0){
               dfs(it,Visit);
          }
     }
}
int main(){
     int n,m;
      int u,v;
     cout<<"enter the n : ";
     cin>>n;
     cout<<"enter the m: ";
     cin>>m;
      vector<int>visit(n+1,0);
     for(int i=0;i<m;i++){
          cin>>u;
          cin>>v;
          temp[u].push_back(v);
          temp[v].push_back(u);
     }
     dfs(2,visit);//if we traversal from the 2 then it gives result for 2
     cout<<"\n for node 1: ";
     visit.assign(n+1,0);//similary we are checking for 1 before that make sure visit has to re initalized with 0
     dfs(1,visit);
}