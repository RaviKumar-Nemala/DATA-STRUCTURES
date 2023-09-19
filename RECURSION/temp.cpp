#include<iostream>
using namespace std;
//use reference  16.2//
bool is_sorted(int a[],int n){
	if(n==1)
	return true;
	else{
		bool result=is_sorted(a+1,n-1);
			return (a[0]<a[1] & result);
	}
}
int main(){
	int a[5]={1,2,3,4,5};
	 cout<<"IS ARRAY IS SORTER : "<<is_sorted(a,5)<<endl;
}
