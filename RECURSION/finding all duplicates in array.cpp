#include<iostream>
using namespace std;

void dup(int a[],int n){
  int  temp[n];
	int i,j;
	for(i=0;i<n;i++){
		 temp[i]=0;
	}
	for(i=0;i<n;i++){
		j=a[i];
		if(temp[j]==0){
			temp[j]=j;
		}
		else{
			temp[j]=11;
		}
	}
	for(i=0;i<n;i++){
		if(temp[i]==11)
		cout<<i<<endl;
	}
}
int main(){
 int  a[4]={1,2,2,1};
	dup(a,4);
}
