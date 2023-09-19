#include<iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
//time complexity for each vertex we are iteration through all of its edges so in worst case   TC=O(v.e)~ O(n^2)//
//source = tuf
struct node{
     int wt,src,dest;
};

class shortest_path{
     public:
     void path(int n,int m,vector<node>temp){
          vector<int>key(n,INT_MAX);
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
               if(updated==false)//if the update is over means that all the edges are taken the shortest path even we iterate through that we can't get any modification in that case simply break loop//
               break;
          }
          for(int i=0;i<m;i++){//
               int parent_value=temp[i].src;
               int parent_weight=temp[i].wt;
               int child_value=temp[i].dest;
               if(key[parent_value]+parent_weight<key[child_value]){
                    cout<<"detected that it is a cyclic negative graph"<<endl;
                    key[child_value]=key[parent_value]+parent_weight;
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
     
int u,v;

int wt;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector<node>temp(n+1);
     for(int i=0;i<m;i++){
          cin>>u>>v>>wt;
          temp[i].src=u;
          temp[i].dest=v;
          temp[i].wt=wt;
     }
     shortest_path obj;
     obj.path(n,m,temp);

     /*sample input->n=4 m=4;
u v wt
0 1 4
1 2 -10
2 3 3
3 0 5
*/

}