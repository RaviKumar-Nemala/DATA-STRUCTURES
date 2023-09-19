#include<bits/stdc++.h>
using namespace std ;


bool is_sorted ( int arr [] , int n )
{
     for ( int idx = 0 ; idx < n-1 ; idx ++ )
     {
          if ( arr[ idx ]  < arr[ idx + 1 ])
               continue;
          else 
               return false;
     }
     return true;
}


int main ()
{
     int arr [] = { 10,20,30,40};
     
     if ( is_sorted ( arr , 4))
     {
          cout <<"ARRAY IS SORTED"<< endl;
     }
     else 
          cout<<"ARRAY IS NOT SORTED"<<endl;

     return 0;
}