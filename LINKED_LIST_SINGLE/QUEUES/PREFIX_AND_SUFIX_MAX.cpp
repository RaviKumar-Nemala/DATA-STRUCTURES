#include<iostream>
#include<vector>
using namespace std;
//in this program we are going to find the total amount of water is going to be store on the array //////////////////////////////////
//if you don't understand take the reference of the take to next level channel//'
int main(){
     int n=12;
     int arr[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    int prefix_sum[n];
    int suffix_sum[n];
     int max_no=0; 
     int i=0,temp;
     
     vector<int>::iterator it;
    for(i=0;i<n;i++){
         max_no=max(max_no,arr[i]);
         prefix_sum[i]=max_no;
     }
     for(i=0;i<n;i++){
     cout<<prefix_sum[i]<<" ";
}
max_no=0;
for(i=n-1;i>=0;i--){
     max_no=max(max_no,arr[i]);
     suffix_sum[i]=max_no;
}
cout<<endl;
 for(i=0;i<n;i++){
     cout<<suffix_sum[i]<<" ";
}
int result=0;
max_no=0;
for(i=0;i<n;i++){
     result+=min(suffix_sum[i],prefix_sum[i])-arr[i];
}
cout<<result<<endl;

}
