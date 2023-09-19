#include<bits/stdc++.h>
using namespace std ;

int row_dir []  = {2, 1, -1, -2, -2, -1, 1, 2 };
  
int col_dir [] = { 1, 2, 2, 1, -1, -2, -2, -1 };

class Solution
{
     int N  ;
     void util ( int cnt , vector< vector<  bool > > &visited , vector< vector< int > > &board , int row , int col )
     {
          if( row < 0 || row >= N || col < 0  || col >= N  || visited[ row] [ col ])
          {
               return;
          }
          
          board [ row ] [ col ] = cnt ;
          visited[ row ] [ col ] = true;
          if( cnt == (N * N -1))
          {
               return;
          }

          for( int idx = 0 ; idx < 8 ; idx ++)
          {
               int nr = row_dir [ idx ] + row ;
               int nc = col_dir [ idx ] + col; 

               util(cnt + 1 ,  visited, board , nr , nc ) ;
          }
          
     }
     public : 
     void solve(  int  n )
     { 
          this -> N = n ;
          vector< vector< int > >board( n , vector< int > ( n , -1 ) );
          vector< vector< bool > > visited(  n , vector< bool >( n , false));
          util ( 0 ,  visited, board , 0 , 0 ) ; 

          for( auto v1 : board)
          {
               for( auto  v2 : v1)
               {
                    cout << v2 <<" ";
               }
               cout << endl;
          }
          return;
      }
};


int main()
{ 
     int n = 8; 
     Solution obj;
     
     obj.solve(  n ) ;
     return 0;
}