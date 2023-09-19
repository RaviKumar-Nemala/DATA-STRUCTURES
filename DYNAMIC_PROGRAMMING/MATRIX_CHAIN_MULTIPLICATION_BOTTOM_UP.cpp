// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

          void  print_brackets ( int i , int j , vector<vector<int > > brackets  , char &s)
          {
               if(i == j ){
               cout<<s;
               s++;
               return ;
               }
               cout<<"(";
               print_brackets(i , brackets[i][j] ,brackets , s );
               print_brackets(brackets[i][j]+1 , j ,brackets , s );
               cout<<")";
              // return ;
          }
    int matrixMultiplication(int N, int arr[])
    {
        // code he
        vector<vector<int > > brackets(N-1, vector<int>(N-1) );

        //memset(brackets , 0 , sizeof(brackets));
        for (int i = 0 ; i < N-1; i++)
        {
             for (int j =  0 ; j < N-1; j ++)
             brackets[i][j] = 0;
        }
           int i, j; 
           int g ;
          int  dp[N-1][N-1];
          int n1 = N-1;
          int min_var;
          for ( g=0 ; g < N-1 ; g ++)
          {
              for( i = 0  , j  = g ; j <N-1 ; i++ , j++)
              {
                 if(g==0)
                 dp[i][j] = 0 ;
                 else if (g==1)
                 {
                     dp[i][j]  = arr[i] * arr[j]* arr[j+1];
                 }
                 else
                    {
                         min_var = INT_MAX;
                    for ( int k = i  ;  k < j ; k ++)
                    {
                        int lc = dp[i][k];
                        int rc = dp[k+1][j];
                        int mc = arr[i]*arr[k+1]*arr[j+1];
                        int total =  lc +  rc + mc ;
                        if(total < min_var ){
                        min_var = total;
                        brackets[i][j] = k-1;
                    }
                    dp[i][j] = min_var;
                }
              }
          }
          }
          for (auto it : brackets)
          {
               for (auto g : it){
               cout << g <<" ";
               }
          }
          /*
          char name = 'A';
          print_brackets(0 , N-2, brackets,name);
          return dp[0][N-2];
          */

}
};


// { Driver Code Starts.

int main(){
   /* int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        */
       int N =5;
       int arr[N] = {2,3,6,4,5};
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    return 0;
}
  // } Driver Code Ends