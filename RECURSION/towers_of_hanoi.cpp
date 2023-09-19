#include<iostream>
using namespace std;
void towers_of_hanoi(int n,char src,char dest,char helper){
	if(n==0)
	return ;
	towers_of_hanoi(n-1,src,helper,dest);
 cout<<"move from : "<<src<<"to : "<<dest<<endl;
 towers_of_hanoi(n-1,helper,dest,src);
}


int main(){
	int n=3;
	towers_of_hanoi(n,'A','C','B');	
}
