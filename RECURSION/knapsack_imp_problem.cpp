#include<iostream>
using namespace std;
int knapsack(int val[],int wei[],int cap,int n){
	if(n==0||cap==0)  
	return 0;
	if(wei[n-1]>cap)
	return knapsack(val,wei,cap,n-1);
	return max(knapsack(val,wei,cap-wei[n-1],n-1)+val[n-1]/*first case*/,knapsack(val,wei,cap,n-1)/*second case*/); 
}//in fist case we are adding the knapsack value so the total capacity is substracted to the wiegth of that element //
//it returns some value//
//in seconde case we are not adding the value and we are getting the corresponding element value //
//we are finding the maximum value of both cases then we returns that max value//
int main(){
	int val[3]={100,50,150};
	int wei[3]={10,20,30};
	int cap=50;
	int n=3;//here no of elements are 3 so n=3//
	cout<<knapsack(val,wei,cap,n);
}
