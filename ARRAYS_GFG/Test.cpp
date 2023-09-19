//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    
    int peak_ele_idx ( int arr[] , int num ) 
    {
          int start = 0 ; 
           
           int end = num -1 ;

           while( start <= end )
          {
               int mid_idx =  ( start + ( end - start)/2) ;

               if ( mid_idx == 0 )
               {
                    if(  arr [mid_idx + 1 ] < arr [ mid_idx ])
                    {
                         return mid_idx;
                    }
                    else 
                    {
                         return mid_idx + 1 ; 
                    }
               }
               else if ( mid_idx == ( num -1 ) ) 
               {
                    if (  arr[ mid_idx -1 ] <  arr [ mid_idx ])
                    {
                         return mid_idx ; 
                    }
                    else 
                    {
                         return mid_idx  -1 ;
                    }
               }
               else 
               {
                    if( arr[ mid_idx]> arr[ mid_idx -1 ] and arr[mid_idx] > arr[mid_idx +1 ])
                    {
                         return mid_idx;
                    }
                    else if ( arr[mid_idx] < arr[mid_idx-1] )
                    {
                         end = mid_idx -1;
                    }
                    else
                    {
                         start = mid_idx + 1; 
                    }
               }
          }
    }
    
    
    public:
    
    bool checkRotatedAndSorted(int arr[], int num){

             
        

    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        Solution ob;
        
        //function call
        flag = ob.checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}
// } Driver Code Ends