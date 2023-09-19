#include<bits/stdc++.h>
using namespace std; 

void print_freq (int arr[]  , int  n )
{
     int freq = 1;

     for( int idx = 1 ; idx <  n ; idx++ )
     {
          if ( arr[ idx ] == arr [ idx -1 ]) 
          {
               freq ++;
          }
          else 
          {
               cout << arr[ idx-1] <<" FREQ = "<<freq<< endl;
               freq  = 1;
          }
     }
          cout << arr[ n-1] << " FREQ = "<< freq;
     return;
}


int main ()
{
     int arr[] = { 10,20,50,50,50};

     print_freq ( arr , 5);

     return 0;
}