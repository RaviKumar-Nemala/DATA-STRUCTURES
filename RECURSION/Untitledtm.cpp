// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int set_bit(int num,int pos){
	return (num&(1<<pos))!=0;
}
int main() {
    // Write C++ code here
    std::cout << "Hello world!"<<endl;
   int a[3]={1,7,6};
  int i,j;
  int n=3;
  for(i=0;i<(1<<n);i++){
  	for(j=0;j<n;j++){
  		if(set_bit(i,j)){
  			cout<<a[j]<<" ";
		  }
		  }cout<<endl;
	  }
  }
