#include<iostream>
using namespace std;
#include<vector>
int parent[100];
int rank_find[100];
void make_set(int n){
     int i;
     for(i=1;i<n;i++){
          parent[i]=i;
          rank_find[i]=0;
     }
}
int find_parent(int node){
     if(node==parent[node]){
          return node;
     }
     return parent[node]=find_parent(parent[node]);
}
void union_sets(int node1,int node2){
           node1=find_parent(node1);
           node2=find_parent(node2);
     if(rank_find[node1]<rank_find[node2]){
          parent[node1]=node2;
     }
     else if(rank_find[node2]<rank_find[node1]){
          parent[node2]=node1;
     }
     else{
          parent[node2]=node1;
          //parent[node1]=node1;
          rank_find[node1]++;
     }
}
int main(){
     int m,n;
     int u,v;int i;
     cout<<"enter the n value  : ";
     cin>>n;
     cout<<"enter the no edges";
     cin>>m;
     make_set(n);
     for(i=0;i<m;i++){
     cin>>u>>v;
     union_sets(u,v);
}
if(parent[2]==parent[3]){
     cout<<"both are same";
}
for(i=0;i<=n;i++)
cout<<parent[i]<<" ";
}