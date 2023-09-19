#include<bits/stdc++.h>
using namespace std ;

bool is_possible( vector< int > &chefs,  int  max_minutes ,  int parathas)
{
     int count =  0;
     for(  int idx = 0 ;idx < chefs.size() ; idx ++ )
     {
          int time = chefs[ idx ] ;
          int j =  2;
          while( time <= max_minutes)
          {
               count ++;
               time = time +  ( chefs[idx]* j);
               j++;
          }

          if( count >= parathas )  return true ;
     }
     return false;
}



int main () 
{
     int t ;
     cin >> t ;
     int ans = -1;
     while ( t -- )
     { 
          int parathas ;
          cin >> parathas;
          int chef_len  ;
          vector < int >chefs;
          for( int  idx = 0  ; idx < chef_len ; idx ++)
          {
               int ele ; 
               cin >> ele ;
               chefs.push_back( ele );
          }
          int lb= 0  , ub = 1e8;
          while ( lb <= ub)
          {
               int mid_val = ( lb + ub )/2;
               if( is_possible( chefs , mid_val ,parathas) )
               {
                    ans =  mid_val ; 
                    ub = mid_val -1 ;
               }
               else 
               {
                    lb = mid_val  + 1 ;
               }
          }
          cout <<ans ; 
     }

     return 0;
}