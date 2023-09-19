#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<climits>
class solution{
     public:
     void topology(int node,stack<int>&st,vector<int>&visit,vector<pair<int,int>>temp[]){
          visit[node]=1;
          for(auto it:temp[node]){
               if(visit[it.first]==0){
                    topology(it.first,st,visit,temp);
               }
          }
          st.push(node);
     }
     void shortest_path(int source,int n,vector<pair<int,int>>temp[]){
          stack<int>st;
          vector<int>visit(n+1,0);
          vector<int>dist(n+1,INT_MAX);
          dist[source]=0;
          for(int i=0;i<n;i++){
               topology(i,st,visit,temp);
          }
          while(!st.empty()){
               int node=st.top();
               st.pop();
                if(dist[node]!=INT_MAX){
               for(auto it:temp[node]){
                        if(dist[it.first]>dist[node]+it.second){
                         dist[it.first]=dist[node]+it.second;
                        }
                    }
               }
          }
              for(auto it:dist){
                   cout<<it<<" ";
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
     vector<pair<int,int>>temp[20];
     int i;
     int wt;
     for(i=0;i<m;i++){
          cin>>u;
          cin>>v;
          cout<<"enter the weights : ";
          cin>>wt;
          temp[u].push_back(make_pair(v,wt));//ensures to (V,wt) not u,wt
         // temp[v].push_back(make_pair(v,wt));//for undirected graph//
     }
     solution obj;
     obj.shortest_path(0,n,temp);
}
