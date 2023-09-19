#include<bits/stdc++.h>
using namespace std; 

 void optimal_sol(  int arr[] , int n )
     {
        int left = 0 ,  right = n -1 ; 
        
        while ( left < right )
        {
             while ( left < right  and arr [ left ] > 0 )
             {
                 left ++;
             }
             while ( right  > left and arr [ right ] < 0 )
             {
                 right --;
             }
             
             if ( left < right )
             {
                 swap ( arr [ left ]  , arr[ right ]) ; 
                 left++;
                 right --;
             }
             
        }
        
        int  pos_idx =   0 , neg_idx = left ;
        
        while ( pos_idx < n and neg_idx  <  n )
        {
            swap( arr [pos_idx] , arr[ neg_idx]) ;
            pos_idx += 2 ;
            
            neg_idx ++;
        }

        for ( int idx = 0 ; idx < n; idx ++){
            cout <<  arr [ idx ] <<"  ";
        }cout << endl;
        
     }

int main ()
{
     int arr[]   = {1, 2, 3, -4, -1, 4};
     optimal_sol(arr , 6 );
     return 0 ;
}