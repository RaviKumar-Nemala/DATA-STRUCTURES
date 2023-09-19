#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class solution{
     public:
     bool topology(int v,vector<int>adj[]){
          queue<int>q;
          vector<int>indegree(v,0);
          int count=0;
          int i;
          for(i=0;i<v;i++){
               for(auto it:adj[i]){
                    indegree[it]++;
               }
          }
          for(i=0;i<v;i++){
               if(indegree[i]== 0){
                    q.push(i);
               }
          }
          while(!q.empty()){
               int node=q.front();
               q.pop();
             count++;
               for(auto it:adj[node]){
                      indegree[it]--;
                    if(indegree[it]==0){
                         q.push(it);
                    }
               }
          }
          if(count==v){
               return false; 
          }
          else{
               return true;
          }
     }
};
     int main(){
     //TOPOLOGICAL SORT ONLY APPLIES FOR THE DIRECTED AND ASYCLIC GRAPHS//
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
          //for directed graph//
     }
     solution obj;
     bool ans=obj.topology(n,temp);
     if(ans==false){
          cout<<"no cycle";
     }
     else {
          cout<<"there is a cycle";
     }
     /*
     if(obj.topology(n,temp)){
          cout<<"cycle is  ditected";
     }
     else{
          cout<<"cycle is not detected";
     }*/
}