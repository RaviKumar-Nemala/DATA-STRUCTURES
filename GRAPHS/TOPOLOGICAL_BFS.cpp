#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class solution{
     public:
     vector<int> topology(int v,vector<int>adj[]){
          queue<int>q;vector<int>ans;
          vector<int>indegree(v+1,0);
          int i;
          for(i=0;i<v;i++){
               for(auto it:adj[i]){
                    indegree[it]++;
               }
          }
          for(i=0;i<v;i++){
               if(indegree[i]==0){
                    q.push(i);
               }
          }
          while(!q.empty()){
               int node=q.front();
               q.pop();
               ans.push_back(node);
               for(auto it:adj[node]){
                      indegree[it]--;
                    if(indegree[it]==0){
                         q.push(it);
                    }
                  
               }
          }
          return ans;
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
     vector<int>ans=obj.topology(n,temp);
     for(auto it:ans){
          cout<<it<<" ";
     }
}


/*


               1   ->  2 ->3 <-- 6 
                           |    |
                           4  -> 5 


*/