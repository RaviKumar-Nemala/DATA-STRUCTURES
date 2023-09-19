#include<bits/stdc++.h>
using namespace std ;

class Solution
{

public:

     void solve (  )
     {

          int no_of_snakes , no_of_ladders ;

          unordered_map < int  , int >  snake_values ;

          unordered_map < int , int >  ladder_values ;

          cout <<"ENTER THE   SNAKE  SIZE : " ;

          cin >> no_of_snakes;
          
          int i ; 

          int u ,v; 

          for ( i = 0 ; i <  no_of_snakes  ; i ++ )
          {
               
               cin >> u >>v ;
               
               snake_values[ u ] = v ;
          
          }

          cout << "ENTER THE SIZE OF THE LADDERS  : " ; 

          cin >> no_of_ladders ;

          for ( i =  0 ; i < no_of_ladders ; i ++ )
          {
               cin >> u >> v ;
               ladder_values [ u ] = v ;
          }


          queue < int > q ;

          vector< bool >  visited ( 101 , false);

          visited [ 0 ] = visited [ 1 ] =  true;

          q.push ( 1 ) ;

          int moves = 0 ;     

          bool found = false; 

          while (!q.empty () and !found )
          {

               int n = q.size() ;

               moves ++;

               while ( n-- )
               {
                    // current_values nunchi maximum positions enni reach avvagalamo anni combinations try cheyyali
//suppose current_val = 1  then dice use chesi manam  ( 2 nundi 7th position varaku reach avutamu )
// current_value nundi dice value ni add chesina tarvatha vachina prati combination anedi ladders lo unda,  leda snakes lo unda leda anedi check chestamu
// oka vela unte danni malli queue lo ki push chestamu
// visited array_maintain chestam endukante already visited values ni malli visit cheyyavalasina avasaram ledu

                    int current_val = q.front() ;

                    q.pop();

                    for ( int die_val =  1 ;die_val <= 6 ; die_val++ )
                    {

                         int next_val = current_val + die_val ; 

                         if ( next_val == 100 )
                         {
                              found = true;
                         }
                         // next_val ladder_values lo unte 
                         else if ( next_val <= 100  and ladder_values [ next_val]   and (!visited [ ladder_values [ next_val] ] ) )
                         {
                              // next_val  ladder_values lo undi + adi 100 equal the stop the loop 
                              if ( ladder_values [ next_val ] == 100 )
                                   found = true;
                              
                              q.push ( ladder_values [ next_val  ] );

                              visited [ ladder_values[next_val ] ] = true;

                         }
                         // next_val anedi snake_value aithe                           // snake value ayindi but it is already visited then no need to do the same thing simply skip it
                         else if ( next_val <= 100 and snake_values[ next_val] and ( !visited [ snake_values[next_val] ]  ) )
                         {

                              //100 ki reach ayyamu but 100 lo snake place ayiundi then it is also indicate that we reach the final state
                              if ( snake_values [ next_val ] == 100 )
                                   found =true;
                              
                              q.push ( snake_values [ next_val ]  );

                              visited [ snake_values [ next_val  ] ]  = true;
                         
                         }
                         // next_val anedi ladder kadu and snake kuda kadu 
                         // and also not visited then add the value into the queue
                         else if ( next_val <= 100 and  !visited [ next_val ] ) 
                         {
                              q.push ( next_val ) ;

                              visited [ next_val] = true; 

                         }
                    }

               }
              

          }


          if ( found )
               {
                     
                     cout << " no of moves to reach the destination :"<<  moves << endl;

               }
          else{
               cout <<" DID NOT REACH THE DESTINATION "<< endl;
          }

     }

};


int main ( ) 
{


Solution obj ;

obj.solve ( ) ;



return 0 ;
}