#include<bits/stdc++.h>
using namespace std ;

int get_sum (  vector < int > arr ) 
{    
     int x = 0 ;    
     for(  auto it : arr) 
     {
          x += it ; 
     } 

     return x ;
}

vector <vector <bool> >  is_sub_arr_existed ( vector <int > arr , int sum ) 
{
     int i , j ;
     
     int n = arr.size () ; 

     vector< vector < bool > >  dp ( n + 1 , vector< bool > ( sum + 1 ,  false ) ) ; 

      for(  i = 0 ; i <=  n ; i ++ )
      {
          for ( j  = 0 ; j <= sum  ; j ++ )
          {
                if ( i == 0 and j == 0 )
                {
                    dp [ i ] [ j ] = true ; 
                }
                else if(  j == 0 )
                {
                    dp [ i ] [ j ] =  true ; 
                }
                else if(  i == 0 )
                {
                    dp [ i ] [ j ] = false ;
                }
               else 
               {
                    if  ( arr [ i  - 1 ] > j   ) 
                    { 
                         dp [ i ] [ j ] = dp [ i -1 ] [ j ] ; 
                    }
                    else  
                    { 
                         dp[ i ] [ j ] =  dp [ i -1 ]  [ j  - arr [ i-1 ] ]  ||   dp [ i - 1 ] [ j ] ;
                    }
                    
               }
          }     
      }

     return dp;

}

void min_differ( vector< int > arr  )
{
     int n = arr.size ( ) ;

     int range = get_sum ( arr ) ;

     int target_sum  =  range / 2 ;

     vector <  vector< bool > > res = is_sub_arr_existed( arr , target_sum ) ;

     vector< int>  elements; 

     int i =   n ; 

     for ( int j = range / 2 ; j >=0   ; j -- )
     {
          if ( res [ i ] [ j ] == true )
          {
                elements.push_back(  j ) ; 
               // cout << j <<  " ->" ; 

          }

     }
     
     int min_val = INT_MAX; 

     for ( auto it : elements )
     {
          min_val = min ( min_val , abs( range - 2 * it ) ) ;

     }

     cout  << min_val << endl; 

     return;
}


int main()
{

     vector < int> arr = { 1 , 2,  7 } ;

     min_differ ( arr  ) ;

     return  0 ; 
}