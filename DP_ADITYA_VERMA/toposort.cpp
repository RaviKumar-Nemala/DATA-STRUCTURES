#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
          int n = words.size () ;

          int cost [ n ] [ n ] ; 

          int i , j ;
          for ( i = 0 ; i < n ; i++)
          {
                cost [i ] [  i ] = maxWidth - words[i].size();
               for  (   j = i + 1 ; j <  n ; j ++ )
               {
                    cost [ i ] [ j ] =  cost [ i ] [ j - 1 ] - words [ j ] .size () - 1 ; 
               } 
          }

          for( i = 0 ; i < n ; i ++ )
          {
               for (  j = i  ; j < n ; j ++ )
               {
                       if(cost  [ i ] [ j ] < 0 )
                         {
                              cost [  i ] [ j ] = INT_MAX; 
                         }
                         else 
                         {
                              cost [ i ] [ j ] *=  cost [ i ] [  j ]; 
                         }
               }
          }


          vector < int > min_cost ( n ,  0) ;

          vector< int > arr( n , 0 ) ;

          for( i =  n - 1;  i >= 0 ; i -- )
          {
               min_cost [  i ] =  cost [ i ] [ n-1 ] ;
               arr [ i ] =  n  ;

               for ( j =  n-1 ; j > i ; j -- )
               {
                    if (  cost [i ][ j-1 ] == INT_MAX)
                    {
                         continue;
                    }
                    else 
                    {
                         if ( min_cost[i] >  ( cost [ i ] [ j -1 ] + min_cost [ j ] ))
                         {
                              min_cost [ i ] = cost [ i ] [ j -1 ] + min_cost [  j ] ;
                              arr [ i ] =  j ; 
                         }
                    }
               }
          }

          int end_idx = arr [ 0 ] ;
          vector< string > res ;
          int start_idx = 0 ;
          while( start_idx < n )
          {
               while ( start_idx < end_idx )
               {
                    res.push_back( words [  start_idx ] ) ;
                    res.push_back (" ");
                    start_idx++;
               }
               if ( end_idx != n )
                    res.push_back (",");
               end_idx =  arr[ start_idx];
          } 

          // for( auto it : res )
          // {
          //      cout << it; 
          //      if( it == ",")
          //      {
          //           cout << endl;
          //      }
          // }

    }
};

int main ( )
{
     vector <string > words ={ "tushar" ,  "roy" , "likes" , "to" , "code"} ;

     int max_width = 10 ;

     Solution obj;
     obj.fullJustify( words , max_width);

}