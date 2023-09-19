// C++ program to find Minimum
// number of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

// Returns Minimum number of
// jumps to reach end
int minJumps(int arr[], int n)
{
    
    vector < int > dp ( n , INT_MAX );

    
     int  i , j ;

     dp [0 ] = 0 ;

    for ( i = 1 ; i < n ; i ++ )
    {
          for ( j = 0 ; j < i ; j ++ )

          {

               if ( j + arr[ j ] >= i and dp [ j ] != INT_MAX)
               {
                    dp [ i ] = min ( dp[ i ] , dp [ j ] + 1 ) ;

               }
          }
    }
    return dp [ n - 1 ] ;

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