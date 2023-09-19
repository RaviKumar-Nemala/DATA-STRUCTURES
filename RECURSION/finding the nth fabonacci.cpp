#include<iostream>
using namespace std;
int find_nth_fabonacci(int n){
	if(n==0||n==1)
	return n;
	else {
		return find_nth_fabonacci(n-1)+find_nth_fabonacci(n-2);
	}
}
int main(){
	int n=2;
cout<<find_nth_fabonacci(n);
}
