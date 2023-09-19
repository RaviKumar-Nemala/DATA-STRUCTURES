#include<bits/stdc++.h>
using namespace std ;

class Solution 
{

public :

    
     void solve ( vector < int > graph []   , int v )
     {
           int cromatic_number= 0;

          // if the available is true means that color is already in use
          
          // if the available is false means that color is not used yet

          vector< bool> available ( v , false ) ;

          vector< int > res ( v , -1 );

          
          for ( int current_node = 0 ; current_node  < v ; current_node ++ )
          {

               for ( auto it : graph [ current_node ] ) 
               {
                    // means res[ it ] ante suppose it = 1 then res [ 1 ] anede 1 ki aa color alocate ayyindi anedi cheptundi
                    
                    // res [ it ] = -1 ante adj node ki inka color allocate cheyyaledu ani

                    if ( res [ it ] != -1 )
                    {
                         int color_no = res [ it ] ;
                         // current node and adj nodes oka color undakudadu so anduke adj nodes ki allocate ayina colors ni block chestamu
                         available [ color_no ] = true ;
                    }
               }

               int new_color ;

               for ( int j = 0 ; j < v ; j ++)
               {// it finds the first color which cannot be used by its any adj node
                    if ( available [ j ] == false )
                    {
                         new_color = j ;
                         break;
                    }
               }
               // current_node ni new_color to fill chestamu
               res [ current_node ] = new_color ;
                                                       // new_color anedi enni colors use ayyayi anedi specify chestundi
                                                       // new_color holds idx so + 1 is added
               cromatic_number = max ( cromatic_number , ( new_color + 1 ) ) ;
              
               // okasari adjacent colors ki coloring chesaka vatini remove cheyyali 
               // because next adj nodes ki colors cheyyali 
               for ( auto it : graph [ current_node ] )
               {
                    if ( res [ it ] != -1 )
                    {
                         available [ res [ it ]  ] =  false ;
                    }
               }
          
          }


          cout << " CROMATIC NUMBER: "<< cromatic_number << endl;

     }

 

};


int main () 
{

     int n  , m ;

     cin >>  n >>  m ;

     vector < int > graph [ n+1 ] ;

     int u ,v ;

     for ( int i = 0 ; i <  m  ; i ++ )
     {
          cin >>u >> v ;
          
          graph [u ].push_back ( v );

          graph[v].push_back ( u ) ;

     }

     Solution obj ;

     obj.solve ( graph , n ) ;


     return 0 ;

}