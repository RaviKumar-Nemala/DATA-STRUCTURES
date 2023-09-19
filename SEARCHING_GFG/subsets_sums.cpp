#include<bits/stdc++.h>
using namespace std ;


void  sequences( vector< int > arr , vector<int > temp , int idx , int n , vector< int > &res )
{
     if( idx == n )
     { 
          int sum = 0 ;
          for( auto  it  : temp)
          {
               sum += it ;
          }
          res.push_back ( sum );
          return;
     }
     temp.push_back( arr [idx ] ) ;
     sequences( arr ,  temp , idx + 1 ,n ,  res );
     temp.pop_back();
     sequences( arr , temp ,  idx + 1 , n,  res );
}
void print_val( vector< int > vals )
{
     for( auto  it :  vals)
     {
          cout << it << " " ;
     }cout << endl;
}
void solve( vector < int > &arr  , int A , int B )
{
     int n= arr.size () ;

     vector< int > v1 , v2 ;
     vector<int > temp;
     sequences(arr  , temp , 0 , n/2, v1 );

     sequences( arr , temp,  n/2 , n ,  v2);

     print_val ( v1 ) ;

     print_val ( v2 );

     sort( v2.begin () , v2.end () );
     int total  = 0 ;
     for( int idx =  0 ; idx < v1.size () ; idx ++)
     { 
          int target1 = A - v1[ idx ];
          int target2 = B - v1 [ idx ];
          int low = lower_bound( v2.begin () , v2.end(),target1 )-v2.begin();
          int high = upper_bound( v2.begin() , v2.end() , target2) - v2.begin();
          total += ( high - low );
     }
     cout << total << endl;
}

int main()
{ 
     //reference = yogesh
     vector< int >  arr= { 1 , -2 , 3 } ;
     int  A = -1 , B = 2 ; 
     solve ( arr ,  A , B ) ;
     return 0 ;
}