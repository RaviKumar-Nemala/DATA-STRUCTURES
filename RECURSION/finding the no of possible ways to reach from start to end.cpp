#include<iostream>
using namespace std;
//here is the program which counts the no of possible ways to reach the destination from the given source//
int  board(int start,int end){
	if(start==end)
	{
		return 1;
	}
	if(start>end)
	return 0;
   int i;
   int count =0;
   for(i=1;i<=6;i++){
   	count+=board(start+i,end);
	}
	return count;
}
int main(){
	cout<<board(0,3)<<endl;
}
