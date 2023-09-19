#include<bits/stdc++.h>
using namespace std ;


int main ()
{
     int t ;
     cin >> t ;
     while( t--)
     { 
          int  w , h , n ;
          cin >> w >> h >> n ;
          vector<int > a ;
          vector<int> b ;
          a.push_back(  0 ) ;
          b.push_back (  0  ) ;
          
          for( int idx = 0 ;  idx < n ; idx ++)
          {
               int  x_cord , y_cord ; 
               cin >> x_cord >> y_cord ; 
               a.push_back( x_cord );
               b.push_back( y_cord );
          }
          a.push_back( w + 1 ) ;
          b.push_back ( h + 1 ) ;

          sort( a.begin () , a.end () ) ; 
          sort( b.begin () , b.end ()  );
          
          int max_width  = INT_MIN ,max_height = INT_MIN ;
          
          for( int idx =  0 ; idx < a.size ()-1 ; idx ++ )
          {
               max_width  = max (max_width , a [ idx + 1 ] - a[ idx ]-1 );
               max_height = max( max_height ,  b [ idx + 1 ] - b [ idx ]-1 );
          }
          cout << max_width * max_height << endl;
     }

     return 0 ;
}