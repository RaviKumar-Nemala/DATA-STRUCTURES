#include<bits/stdc++.h>
using namespace std;

vector<int > get_intersection( int arr_1[],int arr_2[] ,int n1 , int n2 )
{
     vector<int > res  ;

     int idx_1 = 0 ,idx_2  =0;

     while( idx_1 < n1 and idx_2 < n2 )
     {
          int first = arr_1[ idx_1 ];
          int second = arr_2 [ idx_2] ;

          if ( idx_1 > 0 and arr_1[ idx_1 ] == arr_1[idx_1 - 1])
          {
               idx_1 ++;
               continue; 
          }

          if ( first < second ) 
          {
               idx_1++;
          }
          else if ( first > second )
          {
               idx_2 ++;
          }
          else 
          {
               res.push_back( first ) ;
               idx_1 ++;
               idx_2 ++;
          }

     }

     return res;
}

void print_val ( vector< int > arr )
{
     for ( auto it: arr )
     {
          cout << it <<" " ;
     }
     cout << endl;
}
int main()
{
     int arr_1 [] = { 2, 20,20,40,60};

     int arr_2 [] = { 10,20,20,20 , 40};

     int n1 = 5 , n2 = 5 ;

     vector< int> res= get_intersection( arr_1 , arr_2 ,n1 ,n2 );

     print_val ( res ) ;
     return 0 ;
}