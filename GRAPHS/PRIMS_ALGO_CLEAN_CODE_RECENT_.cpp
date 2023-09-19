#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<vector>
#include<climits>
#include<iomanip>

class solution{
     public:
     void minimum_spanning_tree(int source,int n,vector<pair<int,int>>temp[]){

     vector < int > parent ( n ,  -1 );

     vector < int > dist ( n , INT_MAX ) ;

     vector < bool >  msf ( n ,false  );


     priority_queue< vector < pair < int , int > > ,  vector < pair< int, int > > , greater<pair < int ,int> > > min_heap;

     min_heap.push( make_pair(  0 , source  ) ) ;

     dist [ source ] = 0 ;

     parent [ source ] =  -2 ;


    for ( int i = 0 ;i <  n - 1 ; i ++ ){
     
     while ( !min_heap.empty () )
     {
         
     int parent_val = min_heap.top().second;

          int parent_weight = min_heap.top().first ;

          min_heap.pop () ;

          msf [  parent_val ] = true ;

          for ( auto it : temp [ parent_val ] )
          {
               
               int connected_node = it.first;

               int connected_node_weight = it.second ;

               if( msf [ connected_node ] == false and connected_node_weight < dist [  connected_node ] )
               {

                    dist [ connected_node ] =  connected_node_weight ;

                    parent [ connected_node ] =  parent_val;
                    
                    min_heap.push ( make_pair ( connected_node_weight , connected_node ) );
               
               }

          }


     }
    }
     cout <<"PRINTING THE PARENT VALUES : " << endl; 

     for ( auto it : parent )
     {
          cout << it << "  "  ;
     }
     cout << endl;

     cout <<setw(10)<<"NODE VALUE" <<setw( 10 )<<"  CONNECTED_NODE "<<setw ( 10 )<<"WEIGHT  " ;
     
     cout << endl;
     
     for ( int i = 0 ; i <  n ; i ++ )
     {

          if ( i == source ) 
          {
    // cout <<setw(10)<< i << setw ( 10 ) << endl;
          
          continue;

          }
     if( msf [ i ] == true ) 
     cout <<setw(10)<<parent [ i ] << setw (  10 ) << i <<setw (15) << dist [ i ] << endl;

     }


     }
};
int main(){
     int u,v;
     
     int n,m;
     
     cin>>n;
     
     cin>>m;
    
     vector<pair<int,int>>temp [ n + 1 ];
    
     int i;
    
     int wt;
    
     for(i=0;i<m;i++){
          cin>>u;

          cin>>v;
          
          cin>>wt;
          
          temp[u].push_back(make_pair(v,wt));
      // temp[v].push_back(make_pair(u,wt));//ensures to (V,wt) not u,wt
}

     solution obj;
     obj.minimum_spanning_tree( 0 ,  n , temp );
     //obj.dikstra(0,n,temp);
}

/*
6 6
0 1  2 
0 2  1
1 3  6
2 3  1
2 4  2
3 5  4


*/