#include<iostream>
using namespace std;
#include<vector>
class solution{
     public:
     bool is_cycle(int node,int parent,vector<int>&visit,vector<int>adj[]){
          visit[node]=1;
          for(auto it:adj[node]){
               if(visit[it]==0){
                    if(is_cycle(it,node,visit,adj)){
                         return true;
                    }
               }
               else if(it!=parent){
                    return true;
               }
          }
          return false;
     }
     bool cycle_detect(int v,vector<int>adj[]){
          int i;
          vector<int>visit(v+1,0);
          for(i=1;i<=v;i++){
               if(visit[i]==0){
                    if(is_cycle(i,-1,visit,adj))
                    return true;
               }
          }
          return false;
     }
};
int main(){
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
          temp[v].push_back(u);//for undirected graph//
     }
     solution obj;

bool cycle=obj.cycle_detect(n,temp);
if(cycle) cout<<"there is a cycle";
else
cout<<"no cycle";
}
/* SAMPLE INPUT
  
   0->2
   2 ->3
   2 ->4 THIS NOT FORMS A CYCLE

   0->2
   2->3
   2->4
   3->4 THIS FORMS A CYCLE_DETEC
   */