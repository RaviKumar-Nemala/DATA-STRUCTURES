#include"config.h"



bool dfs (  vector < bool > &visited ,  int k  , int src, vector  < pair< int , int > >  graph[]  )
{

     visited [ src ]  = true ;

     for ( auto it : graph [  src ] )
     {

          int v = it.first; 
          
          int wt = it.second ;
          // if the node is already in the path don't include it becuase problem says not contain any cycles
          if ( visited [v]  )
               continue;
          
          // if out path weight is greater then the given k value then simply return true means we found the answer

          if ( wt >=  k )
          {
               
               return true ;

          }
          
          if ( !visited [ v ] ) 
          {

                                   // k - wt means enduku ante every time nodes ni include chestunnappudu dani  " k "  weight lo nunchi detect cheyyali  ala chesi overall weight anedi k weight kanna takkuva unte then simply return true;
                                   
              if (  dfs(visited ,  k - wt  , v ,  graph ) )
                    return true;

          }

     }

     visited [ src ]  = false ; // it should be there if we not found the answer in one path then we need to check for the another path inorde to that we need to make the node as the non visited

     return false;

}


int main ( )
{


int source = 0 ;

int n ;

cin >> n ;

vector < pair < int , int> > graph [ n ] ; 


int u , v , wt ;


int no_of_edges ;

cin >> no_of_edges ;

for ( int i  = 0 ; i < no_of_edges  ; i ++ )
{

     cin >>  u >> v  >> wt ;

     graph [ u ].push_back ( { v , wt } ) ;

     graph [ v ].push_back ( {  u , wt } ) ;

}

int k ; 

cin >> k ; 

vector  < bool > visited ( n , false ) ;

if (  dfs ( visited , k , 0 , graph ) ) 
{
     cout <<" THERE IS A PATH WHOSE SUM MORE THEN THE K "<< endl;
}
else{
     cout<<" THERE IS NO PATH EXISTED WHOSE SUM IS MORE THAN THE K"<< endl;
}

     return 0 ;
}


/*
 6
 7
 0  1  1 
 0 4 1 
 1 2 3
 1 3 2 
 2 3 4 
 3 4  1
 3 5 1 

 */



