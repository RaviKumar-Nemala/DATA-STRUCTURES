#include<bits/stdc++.h>
using namespace std;


class Solution 
{

     public:

     void dfs ( int row, int col , int n , vector <vector< bool >  > &visited ,  vector <int > graph []   )
     {

          if ( row < 0 or row >= n or col < 0 or col >= n  )
          {
               return ;
          }
          else if ( graph [ row ] [ col ] == 0 )
               return ;

          else if( visited [ row ] [ col ] == false )
          {

               visited [ row ] [ col ] = true;
          // down
               dfs ( row + 1 , col ,  n , visited , graph ) ;
          // up
               dfs ( row  - 1  , col , n , visited , graph ) ;
          // left
               dfs ( row   , col - 1  , n , visited , graph ) ;
          // right 
               dfs ( row    , col  + 1 , n , visited , graph ) ;

          // top left diagonal 
               dfs( row - 1 , col - 1 , n , visited , graph ) ;

          // top right diagonal 
               dfs ( row - 1 , col+ 1 , n , visited ,graph );

          // bottom left diagonal
               dfs ( row + 1 , col -1 , n , visited ,graph ) ;

          // bottom right diagonal 
               
               dfs ( row + 1, col + 1 , n  ,visited ,graph ) ;

          }

     }

     void solve ( vector < int > graph [ ]  ,int n  )
     {

          vector <vector <bool  > > visited ( n , vector< bool >  ( n ,false))  ;

          int no_of_islands = 0 ;

          for ( int i = 0 ; i < n ; i ++ )
          {
               
               for ( int j = 0  ;j <n  ; j++ )
               {
                    // 1 ki equal ithe ne adi islands avvudi other wise kadu
                    // so graph lo munde check cheyyali 
                    // no visited and it is island then only use dfs and find its connected nodes 
               if (  graph [ i ] [ j ] == 1 and visited [ i ] [ j ] == false  )
               {
                    // it will find no of connected '1's then those values marked as visited and the connectted 1's becomes the one island
                    
                    // ippudu ee 1'ki connect ayyi vunna total 1's oka island kinda consider chestamu  avi anni dfs traversal use chesi visit chestamu

                    dfs ( i , j ,  n , visited , graph );

                    // dfs traversal ayyaka oka connectted is land( connected island contains may be one '1' or multiple 1's ) form avvuddi so dani value ni increment cheyyli
                    
                    no_of_islands ++ ;// 
              
               }

               }

          }


     cout << "NO OF ISLANDS "<< no_of_islands << endl;

     }

};


int main ( )
{

     
vector < int > graph[]  = { 

     { 1 ,1 ,1 , 0 } ,
     
     { 0 , 1 , 0 , 0 },

     { 0 , 0 , 0 , 1 } ,

     { 1 , 0 , 1 , 1 } ,     
};
// output no_of_islands = 3    ( 1 ,1 1 ,1 ) ( first row lo firt 3 and second row lo 2 nd 1 kalipi ) combined is one island , ( 1 , 1 ,1 )( last row lo last redu and dani pidi kalipi oka island) ,  1 ( last row lo first 1's is one island)


Solution obj ;

obj.solve( graph , 4);


}