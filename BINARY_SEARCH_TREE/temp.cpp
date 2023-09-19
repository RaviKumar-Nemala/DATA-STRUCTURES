#include<bits/stdc++.h>
using namespace std ;

class Solution 
{

public: 


void solve  ( vector< pair< int ,int >  >  adj[] , int n , int source , int destination  )
{

     priority_queue < pair < int, int  > , vector <pair < int , int > >  , greater<pair< int  , int  > > > min_heap;


     min_heap.push ( make_pair( 0 ,  source )) ;

     vector < int > dist ( n , INT_MAX) ;

     dist[  source] =  0 ;

     while( !min_heap.empty() )
     {
          int parent_val = min_heap.top().second ;

          int parent_weight = min_heap.top().first ;

          min_heap.pop();

          for ( auto it:  adj [ parent_val ]) 
          {

               int child_val =  it.first ;

               int child_weight =  it.second ;

               if ( dist[parent_val] +  child_weight < ( dist[child_val]))
               {
                    dist[ child_val ] = dist[ parent_val] + child_weight ;

                    min_heap.push ( make_pair( dist[child_val], child_val )) ;
               
               }

          }


     }

     for ( auto it : dist )
     {

          cout << it <<"   "; 
     }

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

Solution obj;

obj.solve( temp ,  n , 0 ,  2 );

return 0 ;

}

