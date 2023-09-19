#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class solution{
  void find_topo(int node,stack<int>&st,vector<int>&visit,vector<int>temp[]){
       visit[node]=1;
       for(auto it:temp[node]){
            if(visit[it]==0){
                 find_topo(it,st,visit,temp);
            }
       }
       st.push(node);//in topological order parent has to presented on to the top of the stack and its child are presented before of the stack 
  }
  public:
  vector<int> topology(int n,vector<int>temp[]){
       vector<int>visit(n+1,0);
     stack<int>st;
     vector<int>ans;
     for(int i=0;i<n;i++){
          if(visit[i]==0){
               find_topo(i,st,visit,temp);
          }
     }
     while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
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