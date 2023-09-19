// C++ program to find Minimum
// number of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

// Returns Minimum number of
// jumps to reach end
int minJumps(int arr[], int n)
{

     int no_of_steps = arr [ 0 ] ;

     int jumps =  1 ;

     int max_reach  = INT_MIN ;

     for ( int i = 1 ; i < n ; i ++ )
     {

          int current_val =arr [ i ] ;

         
          max_reach =  max ( current_val + i ,  max_reach ) ;

          no_of_steps --;

          if ( no_of_steps == 0 )
          {

               jumps ++;

               if ( i>= max_reach )
               {
                    return -1 ;
               }

               no_of_steps =  max_reach - i ; 

          }

     }

     return jumps;
     
}

// Driver program to test above function
int main()
{
    int arr[] = { 1, 3, 6, 1, 0, 9 };
    int size = sizeof(arr) / sizeof(int);
    cout << "Minimum number of jumps to reach"
         << " end is " << minJumps(arr, size);
    return 0;
}