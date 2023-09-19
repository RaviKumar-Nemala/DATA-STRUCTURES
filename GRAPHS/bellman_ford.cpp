#include<iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
//time complexity for each vertex we are iteration through all of its edges so in worst case   TC=O(v.e)~ O(n^2)//
struct node{
     int wt,src,dest;
};

class shortest_path{
     public:
     void path(int n,int m,vector<node>temp){
        
        vector <  int > parent( n  , 0 ) ;

        vector < int > key  (n , INT_MAX);

        key [ 0 ] = 0 ;

        parent [ 0 ] = -1 ;

        
        for ( int i  = 0 ; i < m - 1 ; i ++ )
        {

          bool update_status = false;

          for ( int j =  0 ; j < m ; j ++ )
          {

               int parent_val = temp [i].src;

               int child_val = temp [ i ].dest ;

               int weight = temp [ i ].wt ;

               if( key [ parent_val ] + weight < (  key [ child_val ]) )
               {
                    
                    key [ child_val ] =  key [ parent_val ] + weight ;
                    
                    update_status = true ;
                    
                    parent [ child_val ] = parent_val;
                    
                }

          }

          if (update_status == false )
          {
               break;
          }

        }





          for(auto it:key)
          cout<<it<<" ";
          cout<<"\n";
          for(auto it:parent) 
               cout<<it<<" ";
     }
};
int main(){
int u,v;

int wt;
     int n,m;
     cout<<"enter the n value: ";
     cin>>n;
     cout<<"enter the m value: ";
     cin>>m;
     vector<node>temp(n+1);
     for(int i=0;i<m;i++){
          cin>>u>>v>>wt;
          temp[i].src=u;
          temp[i].dest=v;
          temp[i].wt=wt;
     }
     shortest_path obj;
     obj.path(n,m,temp);

     /*sample input->n=4 m=4;
u v wt
0 1 4
1 2 -10
2 3 3 
3 0 5
*/

}