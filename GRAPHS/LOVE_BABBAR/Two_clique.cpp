#include"config.h"

class Solution 
{
public: 

void print_graph  ( vector < int > graph []   , int v )
{

     cout << " inside of the print graph "<< endl ;

     for ( int i = 0 ; i < v ; i  ++ )
     {    

         
          for( auto it : graph [ i ] )
          {
              

               cout  << i << " -> " << it << endl;
               
          }

     }    

     return ;

}


bool is_bipatite ( vector <int >graph [ ] , int src  , vector < int > &color )
{

     if ( color [ src ] == -1 )
          color [ src ] =  1 ;

     for ( auto it :  graph [ src ] ) 
     {

          if ( color [ it ] == -1 )
          {
               color [ it ] = 1 -  color [ src ]  ;
               
               if ( !is_bipatite ( graph , it ,   color ) ) 
               {
                    return false;
               }
          }

          else if ( color [ it ] == color [ src ] ) 
          {
               cout << " true " << endl ;

               return false ;

          }

     }
     return true;

}


void config ( vector < int > graph []  ,int v  )
{
     cout <<"adfjas"<< endl;

     vector <bool  > connected_nodes ( v , false  ) ;


     vector < int  > new_graph[ v ] ;


     for ( int i = 0 ; i < v ; i++)
     {

          connected_nodes.clear();

          connected_nodes [ i  ] = true ;

          for  ( auto it :  graph [ i ] ) 
          {

               connected_nodes [  it ] = true ;

          }

          for ( int j = 0 ; j < v ; j++ )
          {

               if ( !connected_nodes [ j ]  )
               {

                    new_graph[i].push_back ( j ) ;

                    new_graph [ j ].push_back ( i ) ;

               }

          }

          

     }

     cout << "OUTSIDE "<< endl;

     vector < int > color ( v , -1 );

     //print_graph ( new_graph , v ) ;

     
     if ( is_bipatite ( new_graph , 0 , color ) )
     {
          cout <<" GIVEN GRAPH CAN BE DIVIDED INTO THE TWO CLIQUES "<< endl;
     }
     else
     {
          cout <<" GIVEN GRAPH CANNOT BE DIVIDED INTO THE TWO CLIQUES "<< endl;
     }
     

}





};


int main()
{

int n , m ;

cin >> n ;

cin >>  m ;

vector < int > graph   [   n   ]   ;

int u , v ;

for ( int i = 0 ; i < m  ; i ++ )
{

cin >> u >> v ;

graph[ u ] .push_back ( v ) ;

graph [ v ].push_back ( u ) ;

}



Solution obj ;

obj.config( graph  , n ) ;


return 0 ; 

}

/*

5
5
0 1 
0 2 
1 2
0 3
3 4 




6 7 
0 1 
0 2
1 2
0 3
3 4
3 5
4 5

*/