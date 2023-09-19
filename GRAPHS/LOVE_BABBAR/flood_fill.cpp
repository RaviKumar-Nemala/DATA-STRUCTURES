#include<bits/stdc++.h>
using namespace std ;


void flood_fill ( vector < vector < int > > colors ,  int n  , pair < int , int> source )
{


     vector < vector < int >  >   visited ( n , vector < int > ( n , 0) );

     queue < pair < int  , int > >  q ;

     q.push ( source ) ;

     visited [  source.first] [ source.second] = true;

     int new_val = 2 ;
     
     while ( !q.empty() )
     {

          int i = q.front ().first; 

          int j = q.front () .second ;

          q.pop();

          int old_val = colors [ i ] [ j ] ;

          colors [ i ] [ j ] =   new_val;


          if ( i -1 >= 0 and ( i - 1 ) < n  and j >=0 and  j < n  and visited [ i - 1 ] [ j ] == false and  colors [ i -1 ] [ j ] ==  old_val )
          {

               visited  [ i - 1 ] [  j ] = true;

               q.push ( { i -1   , j } ); 

          }
          if ( i+1 >= 0 and ( i+1 ) < n  and j >=0 and  j < n  and visited [ i+1 ] [ j ] == false and colors [ i + 1 ] [ j ] == old_val )
          {

               visited  [ i+1 ] [  j ] = true;

               q.push ( { i+1   , j } ); 

          }

          if ( i >= 0 and ( i ) < n  and j +1  >=0 and  j +1  < n  and visited [ i ] [ j +1  ] == false and colors [ i ] [ j + 1 ] == old_val  )
          {

               visited  [ i ] [  j +1  ] = true;

               q.push ( { i   , j +1  } ); 

          }

          if ( i >= 0 and ( i ) < n  and  j -1   >=0 and   j -1   < n  and visited [ i ] [  j -1   ] == false and colors [ i ]  [ j -1 ] == old_val )
          {

               visited  [ i ] [   j -1   ] = true;

               q.push ( { i   ,  j -1   } ); 

          }

     }


     for ( int i = 0 ; i <n  ; i ++)
     {
          for ( int j = 0 ; j < n ; j ++ )
          {
               cout << colors [ i ][ j ] <<"  " ;
          }
          cout << endl;
     }



     return ;

}

int main () 
{

vector < vector < int >  > colors = {

     {
          0 , 1,  0, 0  
     },
     {
          1 , 1, 1 , 0 
     },
     {
          0 ,  1 , 0 , 0 
     },
     {
          0 ,  1 , 1 , 0
     }
};


flood_fill ( colors ,4 ,  { 1 , 1 } );

return 0 ;
}