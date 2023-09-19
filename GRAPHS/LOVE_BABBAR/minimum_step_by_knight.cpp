#include<bits/stdc++.h>

using namespace std ;



void min_steps ( vector < vector< int  > > arr  )
{

     queue < pair < int , int >  > q ;

     int n = arr.size() ;

     int i = 0 , j = 0 ;

     vector< vector < int  > >  visited (  n , vector < int > ( n , 0 )  );

     q.push ( make_pair ( i , j ) ) ;

     while ( !q.empty() )
     {

          int i  = q.front () .first ;

          int j = q.front ().second ;
          
          q.pop () ;

          if ( ( i + 1 ) >=0  and ( i + 1 ) < n and  ( j + 2)>=0 and ( j + 2 ) < n  and visited [ i + 1 ] [ j + 2 ] == false )
          {
               visited [  i + 1 ] [ j + 2 ] = true;

               arr [ i +  1 ] [ j + 2 ] = arr [ i ] [ j ] + 1 ;

               q.push ( make_pair ( i + 1, j + 2 ) ) ;

          }


               if ( ( i + 1 ) >=0  and ( i + 1 ) < n and  ( j-2)>=0 and ( j-2 ) < n  and visited [ i + 1 ] [ j-2 ] == false )
          {

               visited [ i + 1 ] [ j - 2 ] = true;

               arr [ i +  1 ] [ j-2 ] = arr [ i ] [ j ] + 1 ;

               q.push ( make_pair ( i + 1, j-2 ) ) ;

          }

          if ( ( i-1 ) >=0  and ( i-1 ) < n and  ( j + 2)>=0 and ( j + 2 ) < n  and visited [ i-1 ] [ j + 2 ] == false )
          {
               visited [ i - 1 ] [ j + 2 ] = true ;

               arr [ i -  1 ] [ j + 2 ] = arr [ i ] [ j ] + 1 ;

               q.push ( make_pair ( i-1, j + 2 ) ) ;

          }
          
          if ( ( i-1 ) >=0  and ( i-1 ) < n and  ( j-2)>=0 and ( j-2 ) < n  and visited [ i-1 ] [ j-2 ] == false )
          {

               visited [  i - 1 ] [  j - 2 ] = true ;

               arr [ i -  1 ] [ j-2 ] = arr [ i ] [ j ] + 1 ;

               q.push ( make_pair ( i-1, j-2 ) ) ;

          }

          if (  ( i + 2 ) >= 0 and ( i + 2 ) < n and  ( j + 1) >= 0 and  ( j + 1 ) < n and visited [ i + 2 ] [ j + 1 ] == false )
          {
               visited [ i + 2 ] [ j +  1 ] = true ;

               arr [ i + 2 ]  [ j + 1 ] = arr [ i ] [ j ] +  1;
               
               q.push ( make_pair( i + 2 , j + 1 ) ) ;
          
          }

           if (  ( i + 2 ) >= 0 and ( i + 2 ) < n and  (j-1) >= 0 and  (j-1 ) < n  and visited [ i + 2 ] [j-1 ] == false )
          {
               visited [ i + 2 ] [ j - 1 ] = true ;

               arr [ i + 2 ]  [j-1 ] = arr [ i ] [ j ] +  1;
               
               q.push ( make_pair( i + 2 ,j-1 ) ) ;
          
          }

           if (  ( i-2 ) >= 0 and ( i-2 ) < n and  (j-1) >= 0 and  (j-1 ) < n and visited [ i-2 ] [j-1 ] == false )
          {
               visited [ i - 2 ] [ j  - 1 ] = true ;

               arr [ i-2 ]  [j-1 ] = arr [ i ] [ j ] +  1;
               q.push ( make_pair( i-2 ,j-1 ) ) ;
          }

           if (  ( i-2 ) >= 0 and ( i-2 ) < n and  (j+1) >= 0 and  (j+1 ) < n and visited [ i-2 ] [j+1 ] == false )
          {
               visited [ i - 2 ] [  j + 1 ] = true ;

               arr [ i-2 ]  [j+1 ] = arr [ i ] [ j ] +  1;

               q.push ( make_pair( i-2 ,j+1 ) ) ;
          
          }





     }

     cout << arr [ n - 1 ] [ n - 1 ] << endl;

}
int main () 
{

     // in this problem we need to find out minimum steps that a horse( chess horse)  can reach to the end of the arr ( last position of the 2d matrix)  that will be returned
     
     vector< vector < int > > arr ( 4, vector < int >  ( 4 , 0 ) );

     min_steps ( arr ) ;


}