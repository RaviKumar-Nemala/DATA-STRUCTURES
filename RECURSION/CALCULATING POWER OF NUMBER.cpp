#include<iostream>
using namespace std;
int find_value(int number,int power){
	if(power==1)
	return number;
	else{
		return number*find_value(number,power-1);
	}
}



int main(){
	int number=2;
	int power =4;
cout<<find_value(number,power);
}
