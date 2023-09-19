#include<bits/stdc++.h>
using namespace std;


class Solution 
{

     bool is_cycle ( vector < bool > &visited , vector < int > graph [] , int src , vector < bool > &dfs_path  )
     {

          visited [  src ] = true  ;

          dfs_path [ src ] = true ;

          for  ( auto  nodes :  graph [ src ]  )
          {
               if  ( visited [ nodes ] == false )
               {
                    bool cycle_res =  is_cycle ( visited , graph , nodes , dfs_path);
                    if ( cycle_res )
                         return true;
               }
               else if ( dfs_path [ nodes ] )
               {
                    return true;
               }
          }

          dfs_path  [ src ] = false;

          return  false;

     }

     void solve ( vector < int > graph [] , int n ) 
     {

          vector < bool > visited (  n , false ) ;

          vector <  bool > dfs_path ( n , false );

          bool res = true ;

          for  ( int i = 0 ; i < n ; i ++)
          {
               if ( !visited [ i ] )
               {
                    if ( is_cycle ( visited ,  graph , i ,  dfs_path ) )
                    {
                         cout <<" cycle is detected "<< "NOT POSSIBLE TO FINISH ALL TASKS"<< endl;
                         
                         res = false;

                         break;
                    }
               }
          }

          if ( res )
          {
               cout << " CYCLE IS NOT DETECTED POSSIBLE TO FINISH ALL JOBS"<< endl;
          }          


     return ;


     }


};


int main () 
{

/*There are a total of n tasks you have to pick, labelled from 0 to n-1. 
Some tasks may have prerequisites, for example to pick task 0 you have to first pick task 1, 
which is expressed as a pair: [0, 1]
Given the total number of tasks and a list of prerequisite pairs, 
is it possible for you to finish all tasks?
*/

/*
input: 2, [[1, 0]] 
Output: true 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0. So it is possible.
Input: 2, [[1, 0], [0, 1]] 
Output: false 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0, and to pick task 0 you should also have finished task 1. So it is impossible.
Input: 3, [[1, 0], [2, 1], [3, 2]] 
Output: true 
*/

// take the graph( u , v ) where  v ->u important  and when ever the cycle in the graph then return false 
// other wise return true;

}