//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


void printVector(const vector<int>& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

// } Driver Code Ends
class Solution{
  public:
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    {      
          int n1 = A.size () ;

          int n2 = B.size() ;

          int n3 = C.size () ;

          int i  = 0 ;
          int j = 0 ;
          int k = 0 ; 
          
          vector< int > res ; 

          while  (  i < n1 or j < n2 or k < n3 )
          {
               int a = INT_MAX  ; 
               int b = INT_MAX;
               int c =INT_MAX;

               if ( i < n1 )
               {
                    a = A [ i ] ;
               }
               if ( j < n2 )
               {
                    b  = B [ j ] ;
               }

               if( k < n3 )
               {
                    c = C [ k ] ;
               }
               
               if ( a <= b  and a  <=c )
               {
                    res.push_back (a ) ; 
                    i ++;
               }

               else if( b <= a and b <= c )
               {
                    res.push_back ( b ) ;
                    j ++;
               }

               else 
               {
                    res.push_back  ( c) ;
                    k ++;
               }

          }

          for ( auto it : res )
          {
               cout << it << " " ; 
          }
          cout << endl;

    } 

};

//{ Driver Code Starts.

int main() 
{ 

 int N = 4 ; 
 vector < int >   A= { 1 , 2 , 3  , 4 } ; 
     int M = 5 ; 
     vector < int > B = {1 , 2 , 3 , 4 , 5 } ;  
int P = 6 ; 
     vector < int > C = {1 , 2 ,3 ,4 ,5, 6};


    Solution obj;
    obj.mergeThree(A, B, C);
 
    // obj.printVector(mergeThree(A, B, C)); 
    
   
    return 0; 
} 

// } Driver Code Ends