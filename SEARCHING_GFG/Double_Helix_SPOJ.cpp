#include<bits/stdc++.h>
using namespace std ;

void solve ( vector< int > first , vector< int >  second )
{
     int s1  = 0 , s2 = 0 ;
     int n1 = first.size() , n2 = second.size () ;
     int i = 0 , j = 0 ; //
     int max_total =  0 ;
     while( i < n1  and j  < n2 )
     { 
          if ( first[ i ] < second [j ]) 
          {
               s1 += first [ i++ ];
          }
          else if ( second [ j ] < first [  i ]) 
          {
               s2 += second [ j ++];
          }
          else 
          {
               max_total = max_total + max( s1 , s2 ) +  first  [ i ];
               s1 =  0 ; 
               s2   = 0 ;
               i++, j ++;
          }
     }

     while (  i  < n1 )
     {
          s1 += first [ i  ++];
     }
     while ( j < n2 )
     { 
          s2 += second [  j ++];
     }

     max_total  = max_total +  max ( s1 , s2 ) ;

     cout << max_total<< endl;
}

int main ()
{
     vector<int >first =  { 3 , 5 , 7 , 9 , 20 , 25 , 30 ,40, 55 , 56 , 60, 62};
     vector< int > second = {1 , 4 , 7 , 11, 14 , 25 , 44, 47 , 55 , 100};


     return 0;
}