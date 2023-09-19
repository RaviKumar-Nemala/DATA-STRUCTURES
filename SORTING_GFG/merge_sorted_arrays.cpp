#include<bits/stdc++.h>
using namespace std;



vector<int > merge ( int arr_1[] , int arr_2[] , int n1 , int n2  )
{
     vector < int > res ; 

     int idx_1 =  0;

     int idx_2 = 0 ;

     while( idx_1 < n1  and idx_2 < n2)
     {
          int first_val = arr_1 [ idx_1];

          int second_val = arr_2  [idx_2];

          if ( first_val  < second_val)
          {
               res.push_back ( first_val ) ;
               idx_1 ++;
          }
          else 
          {
               res.push_back ( second_val);
               idx_2 ++;
          }
     }

     while ( idx_1 < n1 )
     {
          res.push_back( arr_1[idx_1 ++]);
     }
     while ( idx_2 < n2 )
     {
          res.push_back( arr_2 [ idx_2 ++]);
     }

     return res;

}



int main ()
{

     int arr_1 []= {  5,6,7};
     int arr_2[] = { 1 ,2,3};

     vector< int > res = merge ( arr_1 , arr_2 ,3,3 );

     for( auto it : res )
     {
          cout << it <<" " ;
     }

     cout << endl;


     return 0 ;
}