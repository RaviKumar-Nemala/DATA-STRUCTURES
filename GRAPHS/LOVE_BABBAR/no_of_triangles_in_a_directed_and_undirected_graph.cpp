#include"config.h"

int main()
{

int V =  4 ;

 int digraph[V][V] = { {0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}
                      };


bool is_directed = true ;

int triangles = 0 ;

     for ( int i =  0 ; i < V ; i ++ )
     {

          for ( int j =  0 ; j < V ;  j ++ )
          {

               for ( int k =  0 ; k < V ; k ++)
               {

                    if ( digraph [ i ] [ j ] and digraph [ j ] [ k ]  and digraph [ k ][ i ] ) 
                    {

                         triangles ++ ;

                    }

               }

          }

     }
     // we need to find the unique triangles if it is a directed graph 
     // oka directed graph triangle lo 3 different nodes ni attach chesi 3 ways lo traingle ni form cheyachu
     // kani kanilo manaku only oka triangle matrame kavali so need to divide by 3 

     if ( is_directed )
     {
          triangles =  triangles /  3 ;
     }   
     // oka triangle ni undirected graph use chesi 6 different ways tho construct cheyachu
     // kani danilo okate kavale so divide by 6   
     else
     {
          triangles =  triangles / 6 ;
     }

         cout <<" NO OF TRIANGLES : "<<  triangles << endl;
}