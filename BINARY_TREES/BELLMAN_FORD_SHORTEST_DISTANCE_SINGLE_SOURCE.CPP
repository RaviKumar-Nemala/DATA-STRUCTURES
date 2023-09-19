#include<iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
struct node{
     int wt,src,dest;
};

class shortest_path{
     public:
     void path(int n,int m,vector<node>temp){
          vector<int>key(n+1,INT_MAX);
          vector<int>parent(n,-1);
          key[0]=0;
          parent[0]=0;
          bool updated=false;
          for(int i=0;i<n-1;i++){
                 updated=false;
               for(int j=0;j<m;j++){
                    int  parent_value=temp[j].src;
                    int parent_weight=temp[j].wt;
                    int child_value=temp[j].dest;
                    if(key[parent_value]+parent_weight<key[child_value]){
                         key[child_value]=key[parent_value]+parent_weight;
                         updated=true;
                         parent[child_value]=parent_value;
                    }
               }
               if(updated==false){
                    break;
               }
          }
          for(auto it:key)
          cout<<it<<" ";
          cout<<"\n";
          for(auto it:parent)
          cout<<it<<" ";
     }
};
int main(){
     int n,m;
     
     vector<int>edge;
}