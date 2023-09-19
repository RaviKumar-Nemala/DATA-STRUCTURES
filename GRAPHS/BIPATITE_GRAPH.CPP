#include<iostream>
using namespace std;
#include<vector>
#include<queue>
class solution{
     public:
//DFS APPROACH TO SOLVE THE BIPATITE GRAPH

     bool is_bipolo( int src , vector < int > visit , vector < int >  adj [] )
     {

          if  ( visit [ src ] ==  -1 )
          {
               visit [ src ] = 1 ;

          }


          for ( auto it :  adj [ src ] )
          {
               if( visit [ it ] ==  -1 )
               {
                    if ( !is_bipolo ( it , visit , adj ) ) 
                    {
                         return false;
                    }
               }
               else if ( visit [ it ] == visit [ src ] )
                    return false ;
          }
          return true;

     }




     // with the help of the queue 
     bool is_bipolo(int node,vector<int>visit,vector<int>temp[]){
          queue<int>q;
          q.push(node);
          visit[node]=1;//for the first element we intialized with value 1 then its next element must initialized with value 0(opposite)
         //temp int adj_node=q.front();
               while(!q.empty()){
                    int adj_node=q.front();
                    q.pop();
               for(auto it:temp[adj_node]){
               if(visit[it]==-1){
                    visit[it]=1-visit[node];//this is used becaz adj node must be opp value of its parent that is why we substract with its parent
                    q.push(it);
               }
               else if(visit[it]==visit[node]){//if both parent and adj nodes have same value then we say this is not a bipolo 
                    return false;
               }
          }
     }
          return true;
}
     bool biperate(int v,vector<int>temp[]){
          vector<int>visit(v+1,-1);
          for(int i=1;i<=v;i++)
          {
               if(visit[i]==-1){
                    if(!is_bipolo(i,visit,temp)){
                         return false;
                    }
               }
          }
          return true;
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
          temp[v].push_back(u);//for directed graph//
     } 
     solution obj;
     if(obj.biperate(n,temp)){
          cout<<"biperate ";
     }
     else{
          cout<<"not biperate";
     }
}
