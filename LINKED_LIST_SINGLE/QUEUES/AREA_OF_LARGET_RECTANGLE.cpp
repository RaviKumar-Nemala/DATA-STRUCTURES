#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void Area_Of_Largest_Rectangle(vector<int>&arr){
     int n=arr.size();
   int left_min[n];
   int right_min[n];
   stack<int>st;
   int i;
   for( i=0;i<n;i++){
        while(!st.empty() && arr[i]<=arr[st.top()]){
             st.pop();
        }
        if(!st.empty()){
       left_min[i]=st.top()+1;
       st.push(i);
        }
        else{
             left_min[i]=0;
             st.push(i);
        }
   }
   while(!st.empty()){
        st.pop();
   }
   for(i=n-1;i>=0;i--){
        while(!st.empty() &&arr[i]<=arr[st.top()]){
             st.pop();
        }
        if(st.empty()){
        st.push(i);
        right_min[i]=n-1;
        }
   else{
        st.push(i);
        right_min[i]=st.top()-1;
   }
}
int max_ans=0;
for( i=0;i<n;i++){
     max_ans=max(max_ans,arr[i]*(right_min[i]-left_min[i]+1));
}
cout<<max_ans<<endl;
}
int main(){
     vector<int>temp={1,3,2,1,2};
     Area_Of_Largest_Rectangle(temp);
}