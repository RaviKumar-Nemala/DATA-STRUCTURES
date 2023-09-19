#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>
#include<climits>
class solution{
     public:
     void shortest_distance(int n,int source,vector<int>adj[],int dest){
          vector<int>dist(n,INT_MAX);
          int i;
          queue<int>q;
          q.push(source);
          dist[source]=0;
          while(!q.empty()){
               int node=q.front();
               q.pop();
               for(auto it:adj[node]){
                    if(dist[node]+1<dist[it]){
                         dist[it]=dist[node]+1;
                         q.push(it);
                    }
               }
          }
          for(auto it:dist)
          cout<<it<<" ";
     cout<<"\n SHORTEST DESTINATION:"<<dist[dest];
     }
};
int main(){
     /*i/p 
   1 2
   2 3
   3 4
   4 5
   1 6
   6 7
   6 8
   7 8
   n=8
   m=8
   */
     int u,v;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector<int>temp[ n  + 1 ]; 
     int i;
     for(i=0;i<m;i++){
          cin>>u;
          cin>>v;
          temp[u].push_back(v);
          temp[v].push_back(u);//for undirected graph//
     }
     solution obj;
     cout<<"enter the destination value";
     int dest;
     cin>>dest;
     obj.shortest_distance(n,0,temp,dest);
}
