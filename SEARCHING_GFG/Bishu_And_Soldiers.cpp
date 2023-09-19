#include<bits/stdc++.h>
using namespace std ;

vector< int > get_prefix_sum ( vector< int > arr  )
{
     vector< int >prefix ( arr.size () , 0 ) ;
     int total = 0;
     for( int idx = 0 ; idx < arr.size() ; idx ++ ){
          total += arr[ idx ] ; 
          prefix[ idx ] = total;
     }
     return prefix;
}

int search ( vector < int > arr , int ele)
{
     int low = 0 , high = arr.size()-1 ; 
     int ans = -1 ;

     if  ( ele  > arr[ high ] )
          return  arr.size();
     else if ( ele < arr[ 0 ] ) return  0 ;

     while ( low <= high )
     {
          int mid_idx =  (low +high)/2;
          int mid_val = arr[ mid_idx ];
          if ( mid_val == ele )
          { 
               // cout << mid_idx << endl;
               ans = mid_idx ;
               low = mid_idx + 1 ;
          }
          else if ( mid_val > ele )
          {
               high  = mid_idx -1 ;
          }
          else 
          {
               low = mid_idx +1;
               ans  = mid_idx;
          }
     }
     return  ans;
}

int main ()
{
     int  n ; 
     vector< int > arr;
     int idx ;
     int powers_list ;

     cin >>  n ; 
     for( idx = 0 ; idx < n ; idx ++ )
     {
          int ele ;
          cin >> ele;
          arr.push_back( ele);
     }

     sort( arr.begin () , arr.end()) ;

     for( int idx = 0 ; idx < arr.size () ; idx ++)
          cout << arr [ idx ] << " " ;
     cout << endl;

     vector<int > prefix = get_prefix_sum( arr ) ;

     cin >> powers_list  ;
     
     for( int idx  = 0 ; idx <  powers_list ; idx ++ )
     { 
          int curr_pow;
          cin>> curr_pow;
          int  small_idx  =  search(  arr ,  curr_pow ) ;
          if( small_idx == 0 )
          {
               cout <<  0 << " " << 0 << endl;
          }
          else if ( small_idx == n )
          {
               cout << n <<" "<< prefix[ n -1 ] << endl;
          }
          else 
          { 
               cout <<  small_idx + 1<< " " << prefix[ small_idx ] << endl;
          }
     }

     return 0 ;
}