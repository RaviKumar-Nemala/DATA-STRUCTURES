#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<vector>
#include<climits>
class solution{
     public:
     void dikstra(int source , int n , vector <  pair < int , int > > temp[] ) {

          vector <  int > dist( n+1 , INT_MAX ) ;
         
          dist [ source ]=0;
         
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
         
          min_heap.push(make_pair(0,source));
          
          while(!min_heap.empty()){
            
               int value=min_heap.top().second;
         
               int distance=min_heap.top().first;
         
               min_heap.pop();
         
              for(auto it:temp[value]) {
         
                    int next=it.first;
         
                    int next_dis=it.second;
         
                         if( dist[ value ] + next_dis < dist[ next ] ) {
         
                              dist [ next ] = next_dis + dist[ value ]  ;
         
                              min_heap.push( make_pair (  dist[next] ,  next ) ) ; //dist[next] gives the shortest length of that element //
           
                         }
                }
          }
     
     for(auto it:dist)
     cout<<it<<" ";
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
      // temp[v].push_back(make_pair(u,wt));//ensures to (V,wt) not u,wt
}

     solution obj;
     obj.dikstra(0,n,temp);
}