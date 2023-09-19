#include<bits/stdc++.h>
using namespace std ;


void print_val ( vector<vector<int > > &copy )
{

}

void find_distance ( vector<vector< int> > grid ) 
{
     int n  = grid.size ( ) ;
     int col_size = grid[0].size () ;

     vector <vector < int > > copy ; 
     vector < vector < bool > > visited ;
     for ( int idx = 0 ; idx < n ; idx ++ )
     {    
          vector<  int >  temp ( col_size ) ;
          copy.push_back ( temp ) ; 
          vector <bool >temp_2 ( col_size , false );
          visited.push_back(temp_2);
     }

     queue< pair<  pair<int , int > ,  int >  >  q ; 
     int row , col ; 
     for ( row = 0 ; row < n  ; row ++ )
     {
          for (  col = 0 ; col < col_size ; col ++ )
          {
               if ( grid[ row ] [ col ] == 1 ) 
               {
                    q.push ( make_pair ( make_pair(row , col)  , 0  ) ) ;
                    visited[ row ] [ col ] = true;                   
               }
               else 
               {
                    visited[ row ] [ col ] = false ;
               }
          }
     }

     while( !q.empty() ) 
     {
          auto it = q.front ( ) ;
          
          q.pop();

          int curr_row = it.first.first ;

          int curr_col = it.first.second;

          // cout << curr_row << " " << curr_col << endl; 
          
          int distance = it.second ;

          copy[curr_row] [ curr_col ] = distance;

          int top_row =  curr_row -1 >=0 ? curr_row -1  : -1 ;

          int left_col = curr_col -1 >= 0 ? curr_col - 1 : -1 ; 

          int right_col = curr_col +1 <=(col_size-1) ? curr_col + 1  : -1 ;

          int bottom_row = curr_row +1 <= (n-1) ? curr_row + 1 : -1 ;

          if ( top_row != -1 and visited[top_row] [curr_col] == 0 )
          {
               q.push ( make_pair(make_pair(top_row  , curr_col) , distance +1) )  ;
               visited[top_row][curr_col] = true ;
          }
          
          if ( left_col != -1  and visited[curr_row] [ left_col ] == 0 )
          {
               q.push( make_pair (make_pair(curr_row ,  left_col) , distance +1) );
               visited[curr_row][left_col] = true ;
          }

          if ( right_col != -1 and visited[ curr_row] [ right_col] == 0)
          {
               q.push( make_pair ( make_pair ( curr_row , right_col) , distance + 1 ) ) ; 
               visited[curr_row][right_col] = true ;
          }

          if ( bottom_row != -1  and visited[bottom_row][curr_col] == 0 )
          {
               q.push ( make_pair ( make_pair( bottom_row , curr_col ) , distance + 1 ) ) ;
               visited[bottom_row][curr_col] = true ;
          }
     }

     for ( row = 0 ; row < n ; row ++ ) 
     {
          for ( col = 0  ; col < col_size  ; col ++ )
          {
               cout << copy[row][col] <<" " ; 
          }cout << endl;
     }

}


int main ()
{

     //  grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}

     vector< vector< int > >   grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}};

     find_distance (grid ) ;

     return 0;
}