#include<iostream>
using namespace std;

void count_sort(int a[],int n){
     int i;
     int max_no=a[0];
     for(i=0;i<n;i++){
          max_no=max(max_no,a[i]);
     }
     int count[max_no];
   for(i=0;i<=max_no;i++){
         count[i]=0;
     }
     for(i=0;i<n;i++){
          count[a[i]]++;
     }
     for(i=0;i<=max_no;i++){
          count[i]+=count[i-1];
     }
     int output[n];
     for(i=n-1;i>=0;i--){
        output[--count[a[i]]]=a[i];
     }
     for(i=0;i<n;i++){
         a[i] = output[i];
     }
     for(i=0;i<n;i++){
          cout<<a[i]<<" ";
     }
}

int main(){
     int a[6]={6,5,4,3,2,1};
     count_sort(a,6);
}
