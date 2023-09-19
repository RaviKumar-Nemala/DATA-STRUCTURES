#include<bits/stdc++.h>
using namespace std ;

class Solution 
{

public:


void solve ( vector < int > length , vector <int > price , int n , int rod_length )
{

     int dp [n + 1 ][ rod_length + 1  ] ;

     for ( int i = 0 ; i <= n ; i ++ )
     {
          for ( int j  = 0 ;  j <= rod_length ; j ++ )
          {

               if ( i ==  0 or j ==  0 )
                    dp [ i ] [ j ] =  0 ;

               else if ( j >= length [ i - 1 ]  )
               {

                    dp [ i ] [ j ] = max ( price [ i - 1 ] + dp [ i ] [ j -length [ i -1  ] ] , dp [ i - 1 ] [ j ] ) ;

               }

               else
               {
                    dp [ i ] [ j ] = dp [ i -1 ] [ j ] ;
               }

          }

     }

     

     cout <<" MAX PROFIT :"<< dp [ n ] [ rod_length ] ;


}
     
};



int main ( )
{


vector < int > length  = { 1,  2,3, 4, 5, 6 , 7 , 8 } ;

vector <int> price = { 1, 5, 8 , 9  , 10 ,17 , 17 , 20 } ;


Solution obj  ; 

int rod_length = 8 ; 

obj.solve( length , price , 8 , rod_length  ) ;


}