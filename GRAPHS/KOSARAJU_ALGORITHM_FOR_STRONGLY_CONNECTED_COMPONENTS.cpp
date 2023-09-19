#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define n 8
vector<int>temp[n];
vector<int>rev[n];
void dfs1(int node,vector<int>&visit,stack<int>&st){
     visit[node]=1;
     for(auto it:temp[node]){
          if(!visit[it]){
               dfs1(it,visit,st);
          }
     }
     st.push(node);
}
void reverse(){
     for(int i=0;i<n;i++){
     for(auto it:temp[i]){
          rev[it].push_back(i);
     }
}
}
void dfs2(int node,vector<int>&visit){
     visit[node]=1;
     cout<<node<<" ";
     for(auto it:temp[node])
     {
          if(visit[it]==0){
               dfs2(it,visit);
          }
     }
}
void scc(){
   stack<int>st;
   vector<int>visit(n,0);
   for(int i=0;i<n;i++)
   {
        if(visit[i]==0){
             dfs1(i,visit,st);
        }
   }
   reverse();
   for(int i=0;i<n;i++){
        visit[i]=0;
   }

     while ( !st.empty())
     {
          cout << st.top () <<" " ;
          st.pop (); 
     }cout << endl;

     return;

     while(!st.empty()){
          int current = st.top();
          
          if ( visit [ current ] == 0 )
          {
               dfs2 (current,visit);
          }
          cout << endl;
     }
}
int main(){
     temp[0].push_back(1);
     temp[1].push_back(2);
     temp[2].push_back(0);
     temp[2].push_back(3);
     temp[3].push_back(4);
     temp[3].push_back(5);
     temp[4].push_back(7);
     temp[5].push_back(6);
     temp[6].push_back(4);
     temp[6].push_back(7);
     scc();
     return 0;
}



