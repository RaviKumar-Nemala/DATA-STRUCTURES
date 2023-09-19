#include<bits/stdc++.h>
using namespace std;

class Solution{
     public : 
      int Longest_Bitonic_Subsequences( vector<int>arr , int n )
     {

          vector<int>lis(n , 1 );
          vector<int>lds(n , 1 );

          int i, j ; 

          for ( i = 1 ;i < n ; i ++ )
          {
               for ( j = 0 ; j < i ; j++)
               {
                    if ( arr[j] < arr[i] )
                    {
                         lis[i] = max(lis[i],  lis[j] + 1 ) ;
                    }
               }
          }

          for( i = n-2 ;  i >= 0 ; i -- )
          {
               for(j = n-1 ; j > i ;  j--)
               {
                    if( arr[j]  > arr[i] )
                    {
                         lds[i] = max(lds[i] , lds[j] + 1 ) ;
                    }
               }
          }    
               int temp=INT_MIN;
          for( i =0 ;i < n ; i++)
          {
               if( ( lis[i] +  lds[i] - 1 ) >  temp )
               temp = lis[i] +  lds[i] - 1; //here -1 is used because both lis and lds are included ith element to get the longest increasing and longest decreasing subsequence then we should remove from any one of them that is why we used -1 here//
          }
          return temp;
     }
};

int main(){
     vector<int> arr = { 10,22,9,33,21 ,50 ,41,60 , 80 ,3};
     Solution obj ;
     cout<<obj.Longest_Bitonic_Subsequences(arr , 10);
}