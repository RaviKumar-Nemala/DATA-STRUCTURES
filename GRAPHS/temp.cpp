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

     priority_queue< vector < pair< int , int > >, vector < pair <int , int > > ,  greater<pair <int ,int > >  > min_heap ;


     min_heap.push( make_pair (  0 , source ) );

     for ( int i = 0  ; i < n - 1 ; i ++ )
     {

          while ( !min_heap.empty() )
          {

               int parent_val =  min_heap.top().second ; 


               int parent_weight = min_heap.top().first;

               msf [ parent_val ] =  true;

               min_heap.pop();


               for ( auto it : temp [ parent_val ] ) 
               {

                    int child_weight =  it.second ;

                    int child_value = it.first ; 

                    if ( msf [ child_value ] == false and child_weight < dist [ child_value ])
                    {
                         dist [ child_value ]   =  child_weight;

                         min_heap.push( make_pair ( child_weight ,  child_value) ) ;

                         parent [ child_value ] = parent_val ;

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


     vector < vector < int > >  config = { { 0 , 0 } ,  { 2 ,2 } , { 3 ,10 } , { 5 , 2 } , { 7 , 0 } } ;

     int n = config.size();

     /*
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

*/

     vector < pair < int , int > >  temp [ n ] ; 


     for ( int i = 0 ; i < n ; i ++ )
     {
          auto parent_points = config [ i ] ;

          int xi =  parent_points [ 0 ] ;

          int yi =  parent_points [ 1 ] ;

          
          for ( int j = i + 1 ; j < n ; j ++  )
          {
               auto conneted_points = config [ j ] ;

               int xj =  conneted_points [ 0 ] ;

               int yj = conneted_points [  1 ] ;

               int weight =  abs ( xi - xj ) + abs ( yi - yj ) ;
              
               /*cout << i << "   " ;

               cout << j << " " ;
               
               cout << weight << endl;
               */
               temp [  i ].push_back( make_pair ( j , weight  ) );
 
          }

     }

     solution obj ;

     obj.minimum_spanning_tree( 0 , n , temp ) ;

}