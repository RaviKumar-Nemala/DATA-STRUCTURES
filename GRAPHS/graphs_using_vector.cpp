#include<iostream>
using namespace std;
#include<vector>

int main(){
     int u,v;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector<int>temp[n+1];
     int i;
     for(i=0;i<m;i++){
          cin>>u;
          cin>>v;
          temp[u].push_back(v);
          temp[v].push_back(u);//for undirected graph//
     }
   /* for(auto i:temp){
         cout<<temp[i];
         for(auto j:i){
              cout<j<<" ";
         }
    }*/
    for(int i=0;i<n+1;i++){
         cout<<i<<"-> ";
         for(auto j:temp[i]){
              cout<<j<<" ";
         }
         cout<<"\n";
    }
}
