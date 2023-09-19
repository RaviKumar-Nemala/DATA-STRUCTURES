#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<vector>
#include<climits>
class min_span{
     public:
     void minimum_spanning_tree(int source,int n,vector<pair<int,int>>temp[]){
          int key[n+1];bool msf[n+1];
          int parent[n+1];
      int i;
      for(i=0;i<n;i++){
           key[i]=INT_MAX;
           msf[i]=false;
           parent[i]=-1;
      }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
       min_heap.push({0,0});
       parent[0]=0;
       key[0]=0;
      for(int i=0;i<n-1;i++){
               int weight=min_heap.top().first;
               int parent_value=min_heap.top().second;
               min_heap.pop();
               msf[parent_value]=true;
               for(auto it:temp[parent_value]){
                    int child_value=it.first;
                    int child_weight=it.second;
                    if(msf[child_value]==false and  child_weight<key[child_value]){///there is a modification here see tuf channel
                         //key[child_value]=key[parent_value]+child_weight;
                         key[child_value]=child_weight;
                        // msf[child_value]=true
                         parent[child_value]=parent_value;
                         min_heap.push({child_weight,child_value});
                    }
               }
          }
          int sum=0;
          for(i=0;i<n;i++){
               cout<<parent[i]<<" ";
          }cout<<"\n";
          for(i=0;i<n;i++)
          {
              // if(key[i]==INT_MAX)
               cout<<key[i]<<" ";
          }
         // cout<<"\n "<< sum;
     }
};
int main(){
     int u,v;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector<pair<int,int>>temp[20];
     int i;
     int wt;
     for(i=0;i<m;i++){
          cin>>u;
          cin>>v;
          cout<<"enter the weights : ";
          cin>>wt;
          temp[u].push_back(make_pair(v,wt));
          temp[v].push_back(make_pair(u,wt));//ensures to (V,wt) not u,wt
}
     min_span obj;
     obj.minimum_spanning_tree(0,n,temp);
          /*   2    3
            0____1_____2
            6|   8/    \ 5   |7
            | /       \ 4              
             3 */


/*
u v wt
0 1 2
1 2 3
0 3 6
1 3 8
1 4 5 */
}