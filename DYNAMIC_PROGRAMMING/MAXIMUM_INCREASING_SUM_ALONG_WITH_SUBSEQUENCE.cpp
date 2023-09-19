#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
     public: 
          int max_incr_sum(int arr[] , int n )
          {
               int  max_incr_at_point[n];
               int i , j ;
               vector<int>values(n);
               for (i= 0 ; i < n ; i++ )
               {
                    max_incr_at_point[i]  = arr[i];
               }


               for ( i  = 0 ; i < n ;i ++)
               values[i] = i ;

               for ( i = 1 ; i <  n  ; i ++ )
               {
                 for( j = 0 ; j < i ; j++)
                 {
                      if(arr[j] < arr[i] )
                      {
                         if(max_incr_at_point[j] + arr[i] >  max_incr_at_point[i]){
                         max_incr_at_point[i] = max_incr_at_point[j] + arr[i];
                         values[i] = j;
                      }
                      }
                 }
               }

               int max_val = INT_MIN;int temp=0;
               for ( i = 0 ;  i < n ; i++ ){
               if( max_val < max_incr_at_point[i] ) 
               {
                    temp = i;
                    max_val = max_incr_at_point[i];
               }
          }
          //cout<<temp;

          vector<int>ans;
          int prev = 0;
          do {
               cout<<arr[temp]<< " ";
               prev = values[temp];
               temp= prev;
          }while(values[temp]!=temp);
          cout<<arr[temp] << " ";
               for(auto it : ans )
               cout<< it <<" ";

                return max_val;
          
          
          return max_val;
}
};

int main(){
     int  arr[]= { 4,6,1,3,8,4 };
     Solution obj;
     cout<<obj.max_incr_sum(arr,6);
}
