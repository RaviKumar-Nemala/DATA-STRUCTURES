#include<bits/stdc++.h> 
using namespace std ;


void solve( int arr[] , int k , int n  )
{ 
     deque<int > s , g; 
     int sum = 0 ;
     for ( int i  = 0 ;  i < k ; i ++ )
     {
          int x = arr [  i ];  
          while ( !s.empty() and  x <=  arr [ s.back () ] ){
               s.pop_back();
          }
          while ( !g.empty() and x >= arr [ g.back()])
          {
                g.pop_back();
          }               
          s.push_back( i ) ;
          g.push_back( i);
     }

     for ( int i = k ; i <  n ; i ++ )
     {         
          sum += arr [ s.front () ] + arr[ g.front() ] ;

          int x  = arr [ i  ] ;
          
          while  ( !s.empty() and ( s.back() +  k )  < i )
          {
                    s.pop_back ();
          }
          while( !g.empty ()  and ( g.back () + k ) < i  )
          {
                    g.pop_back();
          }

               while ( !s.empty() and  x <=  arr [ s.back () ] ){
               s.pop_back();
          }
          while ( !g.empty() and x >= arr [ g.back()])
          {
                g.pop_back();
          }               
          s.push_back( i ) ;
          g.push_back( i);
     }
     cout << sum << endl; 

}


int main()
{ 
     int arr[] = {2, 5, -1, 7, -3, -1, -2} ; 
     int K = 4;
     solve( arr ,  K  , 7 ) ;

// Output : 18


     return 0;
}