//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
     
     vector < int >get_prefix ( int arr[] , int n )
     {
          int max_val = arr [ 0 ] ;

          int i  ; 
          vector < int >  prefix (  n ,  0) ; 
          for ( i = 0 ; i < n ; i ++ )
          {    
               prefix [ i ] = max ( arr [ i ] , max_val ) ;
          }
          return  prefix;
     }

     vector< int > get_sufix ( int arr [] , int n )
     {
          int max_val   = arr [ n - 1 ] ;    
          int i  ; 
          vector < int > sufix ( n , 0 ) ;

          for ( i  = n -1 ; i >= 0 ; i -- )
          {    
               sufix [ i ] = max ( max_val , arr [ i ] ) ;
          }

          return sufix;
     }
     
     public:
    long long trappingWater(int arr[], int n){

          vector < int > sufix = get_sufix  ( arr , n ) ;

          vector < int  > prefix = get_prefix ( arr , n ) ; 
          int max_water  = 0 ; 
          for  ( int i  = 0 ; i < n ; i  ++ ) 
          {
               max_water += ( min ( sufix [ i ] ,  prefix [ i ] ) -  arr [ i ] ) ;
          }

          return max_water;
    }
};   

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends