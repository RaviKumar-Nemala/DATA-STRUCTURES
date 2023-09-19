#include<bits/stdc++.h>
using namespace std ;


class Solution 
{
public:

     void solve ( vector < int > arr []  , int n )
     {

          vector< int > time ( n , 0 ) ;

          vector < int > indegree  ( n + 1 , 0 ) ;

          for( int i = 0 ; i <  n  ; i ++ )
          {
               for ( auto it : arr [ i] )
               {
                    indegree [ it ] ++;
               }
          }

          queue < int > q ;

          for ( auto it : indegree )
          {
               if ( it == 0 )
               {
                    q.push ( it );

                    time [ it ] = 1 ;
               
               }
          }


          while ( !q.empty() )
          {

               int parent =  q.front () ;

               q.pop ( );

               for ( auto it :  arr[ parent ] ) 
               {
                    // indegree -- cheyali endukante already ee parent child ni reach ayyindi so aa edge ani mari calculate cheyyakaledu
                    indegree [ it ] --;

                    if ( indegree [it ] == 0 )
                    {
                         // child nodes indegree 0 ithe then aa node job complete cheyyachu
                         // aa node job complete cheyyadaniki minimum time enta ante dani parent job complete cheyyadani ayyina minimum time + 1 
                         time [ it ] = time [ parent ] + 1 ;
                         // indegree  0 ithe aa node ni q lo push cheyyli
                         // suppose ee node ki emina child unte vatini kuda process cheyyali kada
                         q.push ( it ) ;
                    
                    }

               }

          }
// it prints the total time ( min time ) for job processing

          for ( auto  it : time )
          {
               cout << it << "   " ;
          }

          return;
     
     }





};
int main () 
{

     /**
      * @brief Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be
      *  completed where each Job takes unit time to get completed.
      * 
      */

int n = 8;

int m =  9 ;


vector < int > temp[ n];

int u , v ;

for ( int i = 0 ; i < m ; i ++ )
{

     cin >> u ;

     cin >> v ;

     temp [ u ].push_back ( v ) ;     

}



Solution obj ;

obj.solve ( temp , n ) ;


}