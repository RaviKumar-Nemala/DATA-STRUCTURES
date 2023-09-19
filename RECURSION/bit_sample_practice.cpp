#include<iostream>
using namespace std;

void sub_sets(int a[],int n){
   int i,j;
   int count=0;
   for(i=0;i<(1<<n);i++){
   	for(j=0;j<n;j++){
   		if(i&(1<<j)){
   			cout<<a[j]<<" ";
			}
		}cout<<endl;
		count++;
	}
	cout<<"\n"<<count<<endl;
}




int main(){
	int a[5]={1,2,3,4,5};
	sub_sets(a,5);
}
