#include<bits/stdc++.h>
using namespace std ;




// source  = https://youtu.be/5h1JYjin_4o

vector < int>  in_time ;

vector < int > out_time ; 

int timer ; 

void dfs ( vector < int > graph[] , int src , vector < bool > visited )
{

     in_time[ src  ] =  timer ++;

     visited [ src ] = true;

     for ( auto it : graph [ src ]  )
     {

          if ( !visited [ it ] ) 
          {
               dfs ( graph , it , visited );
          }

     }

     out_time [ src ] =  timer++;


     return ;

}


bool check ( int x   , int y )
{

bool case_1 =  in_time [ x ] < in_time [ y ] ? true : false;

bool case_2 =  out_time [ y ] < out_time [ x ] ? true: false;

if ( case_1 and case_2 )
{
     return true;
}
else
{
     return false;
}


}

int main() 
 {


     int n ; 
     
     cin >> n ;

     vector < int > graph [ n+1 ] ;

     int u , v ;

     ::in_time.resize( n+1 , 0 );

     :: out_time.resize( n+1 , 0 ) ;

     for ( int  i = 0 ; i < n-1  ; i ++ ) 
     {

          cin >> u >> v ;

          graph [ u ].push_back ( v ) ;

          graph [ v ].push_back (u ) ;

     }

     vector  < bool > visited ( n+1 , false ) ;
     
     dfs ( graph , 1 , visited );

     int queries_size  ; 


     cin >> queries_size ;


     for ( int i  = 0 ; i < queries_size ; i++ )
     {

          int  type ,  oliver , bob ;

          
          cin >> type >>oliver >> bob ;

          if ( !check ( oliver, bob )  and !check ( bob , oliver ) )
          {

               cout << " NO"<< endl;

          }


          else if(  type == 0 ) {
          
          if  ( check ( oliver , bob ) ) 
          {

               cout <<"YES "<< endl;
          }
          else
          {
               cout <<" NO "<< endl;
          }

          }

          else {

               if ( check ( bob  , oliver ) ) 
               {
                    cout << "YES "<< endl;
               }
               else
               {
                    cout <<" NO "<< endl;
               }

          }


     }

     return 0 ;

 }