#include<iostream>
using namespace std; 
int fact(int n){
	int fact=1;
	int i=1;
	for(i=1;i<n;i++)
	fact*=i;
	return fact;
}



int main(void){
	int n=4;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			cout<<(fact(i))/(fact(i-j)*fact(j))<<" ";
		}
		cout<<endl;
	}
}
