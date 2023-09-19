#include<iostream>
using namespace std;

int main(){
     int  u,v;
     long n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     long int  adj[n+1][n+1]={0};

     fflush ( stdin );

     for(int i=0;i<m;i++){

          fflush ( stdin );

          cin>>u;

          cin>>v;

          adj[u][v]=1;
          adj[v][u]=1;
     }
     for(int i=0;i<m;i++){
          for(int j=0;j<m;j++){
               if(adj[i][j]==1){
                    cout<<"(" <<i<<","<<j<<")";
               }
          }
     } 
}