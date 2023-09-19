#include<bits/stdc++.h>
using namespace std ;

vector<int > get_union(int arr_1[] , int arr_2 [] , int n1 , int n2 )
{
     vector < int  >res ;

     int idx_1 = 0 , idx_2 = 0 ;

     while( idx_1 < n1 and idx_2 < n2 )
     {
          if ( idx_1 > 0 and arr_1[idx_1] == arr_1[idx_1 -1 ])
          {
               idx_1 ++;
               continue;
          }

          if ( idx_2 >  0 and  arr_2[idx_2 ] == arr_2[idx_2])
          {
                    idx_2 ++;
                    continue;
          }

          int first_val  = arr_1 [ idx_1];
          int second_val = arr_2[ idx_2 ] ;
          
          if ( first_val < second_val)
          {
               res.push_back( first_val );
               idx_1 ++;
          }
          else 
          {
               res.push_back ( second_val );
               idx_2 ++;
          }

     }     

     while ( idx_1 < n1 )
     {
          if( arr_1[ idx_1]  == arr_1[ idx_1 -1 ])
          {
               idx_1 ++;
               continue;
          }
          res.push_back( arr_1 [ idx_1 ]);
          idx_1 ++;
     } 

     while (idx_2 < n2 )
     {
          if ( arr_2[ idx_2] == arr_2[ idx_2 -1 ])
          {
               idx_2 ++;
               continue;
          }
          res.push_back ( arr_2[ idx_2 ]);
          idx_2 ++;
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


int main () 
{
     int arr_1 [] = { 2 , 20 ,20,40,60};int n1 = 5;
     int arr_2[] = { 10,20,20,20};int n2 = 4;

     print_val( get_union( arr_1 , arr_2,n1 ,n2) ) ;

     
     return 0 ;
}