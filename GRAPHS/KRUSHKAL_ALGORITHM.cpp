using namespace std;
#include<bits/stdc++.h>

struct node{
     int u;
     int v;
     int wt;
     node(int first,int second,int weight){
      u=first;
      v=second;
      wt=weight;
}
};

bool comp(node a,node b){
     return a.wt<b.wt;
}

int find_parent(int u,vector<int>&parent){
     if(u==parent[u])
     {
          return u;
     }
     return parent[u]=find_parent(parent[u],parent);
}

void union_make(int node1,int node2,vector<int>&parent,vector<int>&rank){
     node1=find_parent(node1,parent);
     node2=find_parent(node2,parent);
     if(rank[node1]<rank[node2]){
          parent[node1]=node2;
     }
     else if(rank[node2]<rank[node1]){
          parent[node2]=node1;
     }
     else {
          parent[node2]=node1;
          rank[node1]++;
     }
}
int main(){
     int m,u,v,i;int n;
     cout<<"Enter the n value: ";
     cin>>n;
     int wt;
     cout<<"enter the m value";
     cin>>m;
     vector<node>edges;
     for(i=0;i<m;i++){
          cin>>u>>v>>wt;
          edges.push_back(node(u,v,wt));
     }
     sort(edges.begin(),edges.end() , comp );
     vector<int>parent(n);
     for(int i=0;i<n;i++)
         parent[i]=i;

     vector<int>rank(n,0);
     vector<pair<int,int>> mst;
     for(auto it:edges){
          if(find_parent(it.v,parent)!=find_parent(it.u,parent)){
               union_make(it.u,it.v,parent,rank);
               mst.push_back({it.u,it.v});
          }
     }cout<<"\n";
     for(auto it:mst){
          cout<<it.first<<"->"<<it.second<<endl;
     }
     return 0;
}