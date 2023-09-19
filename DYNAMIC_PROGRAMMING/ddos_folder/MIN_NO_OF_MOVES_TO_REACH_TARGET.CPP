// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	        // Code here
	        
	    int x1 = KnightPos[0];
	    int x2 = KnightPos[1];
	    int y1 = TargetPos[0];
	    int y2 = TargetPos[1];
        int arr[1000][1000] ={0};       /* for(int i = 0 ; i <101 ; i++)
        {
            for(int j = 0 ; j <101 ; j++)
            arr[i][j] = 0;
        }*/
        queue<pair<int , int > > q;
        q.push(make_pair(x1-1, x2-1 ));
        while(!q.empty())
        {
            auto current = q.front();
            int i = current.first ; 
            int j = current.second;
            q.pop();
            if((i+1)>=0 and (i+1) <  N and (j+2)>=0 and (j+2) < N and arr[i+1][j+2] == 0)
            {
                arr[i+1][j+2]=arr[i][j] + 1;
                q.push(make_pair(i+1,j+2));
            }

            if((i+1)>=0 and (i+1) <  N  and (j-2)>=0 and (j-2) <  N and arr[i+1][j-2] == 0)
            {
            arr[i+1][j-2] = arr[i][j] + 1 ;
             q.push(make_pair(i+1,j-2));
            }

            if((i-1) >=0 and (i-1) <  N and (j+2) >= 0 and (j+2) <  N and arr[i-1][j+2] == 0)
            {
            arr[i-1][j+2] = arr[i][j] + 1;
            q.push(make_pair(i-1 , j+2));
            }
            
            if((i-1) >=0 and (i-1) < N and (j-2) >= 0 and (j-2) <  N and arr[i-1][j-2] == 0){
            arr[i-1][j-2] = arr[i][j] + 1;
            q.push(make_pair(i-1 , j -2 ));
            }


            if((i-2) >= 0 and (i-2) < N and (j+1)>=0 and (j+1) < N and arr[i-2][j+1] == 0){
            arr[i-2][j+1] =  arr[i][j] + 1;
            q.push(make_pair(i-2 , j+1));
        }

            if((i-2) >= 0 and (i-2) <  N and (j-1)>=0 and (j-1) < N and arr[i-2][j-1] == 0){
            arr[i-2][j-1] = arr[i][j] + 1 ;
            q.push(make_pair(i-2 , j-1 ));
        }

            if((i+2) >= 0 and (i+2) < N and (j-1)>=0 and (j-1) < N and arr[i+2][j-1] == 0){
            arr[i+2][j-1] = arr[i][j] + 1;
            q.push(make_pair(i+2 , j-1 ));
            }
            
            if((i+2) >= 0 and (i+2) <  N and (j+1)>=0 and (j+1) < N and arr[i+2][j+1] == 0){
            arr[i+2][j+1] = arr[i][j] + 1;
             q.push(make_pair(i+2 , j+1 ));
        }

        }
        return arr[y1-1][y2-1];
	}
};
	
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends