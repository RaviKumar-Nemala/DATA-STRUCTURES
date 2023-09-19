#include<bits/stdc++.h>
using namespace std ;

void dfs ( int row , int col , int n , string path , vector < string > &ans , vector<vector < int > >  &visited , vector< vector< int > >  maze )
{

     if ( row == n -1 and col == n -1 )
          {
               ans.push_back ( path);
               return ;
          }
     // moving to the down 
      if ( row + 1 < n  and visited [ row + 1 ] [ col ] == false and maze[ row + 1 ][ col ] == 1 )
     { 

          visited [ row+1][col ] = 1 ;

          dfs ( row + 1 , col , n , path+"D" , ans ,visited , maze);
          
          // once traversal completed make sure visited will be 0 because there may be chance some other path take this path to reach to the destination

          visited[ row + 1 ][col ] =  0;
     
     }

     // moving to the upper side 
     if(   row - 1 >= 0 and visited [ row - 1 ] [ col ] == false and maze [ row -1 ] [ col ] ==  1 )
     { 

          visited [ row -1 ] [ col ] = 1 ;
          dfs ( row - 1 , col , n , path+"U", ans , visited , maze );
          visited [ row - 1 ] [ col ] = 0;

     }
     //moving to the right side
     if ( col + 1 < n  and visited [ row  ] [ col + 1 ] == false and maze[ row  ][ col + 1 ] == 1 )
     { 

          visited [ row ][col + 1  ] = 1 ;

          dfs ( row , col + 1  , n , path+"R" , ans ,visited , maze);

          visited[ row ][col + 1  ] =  0;
     
     }
     // moving to the left side
     if ( col  - 1 >= 0  and visited [ row  ] [ col -1  ] == false and maze[ row  ][ col - 1 ] == 1 )
     { 

          visited [ row ][col - 1  ] = 1 ;

          dfs ( row , col - 1  , n , path+"L" , ans ,visited , maze);

          // once traversal completed make sure visited will be 0 because there may be chance some other path take this path to reach to the destination

          visited[ row ][col - 1  ] =  0;
     
     }

}


void solve ( vector < vector < int >  > maze )
{ 

     int n = maze.size() ;

     vector< vector< int > >  visited ( n , vector < int > ( n , 0 ) ) ;

     vector< string > ans ;

     dfs ( 0 , 0 ,  n , "" ,  ans , visited , maze );

     for ( auto it : ans )
          cout <<it <<"  " << endl;
     
     return; 


}

int main () 
{

vector < vector < int > >  maze = {    
                                    { 1 ,0 , 1 ,1   } ,
                                    
                                    { 1 , 1 ,  1 , 1 },
                                    
                                    {0 , 1 , 1 , 1  } ,
                                    
                                    {0 , 0 , 1 , 1  }
                                   
                                   };



solve ( maze ) ;



                                        
                                        
                                        
                              


}