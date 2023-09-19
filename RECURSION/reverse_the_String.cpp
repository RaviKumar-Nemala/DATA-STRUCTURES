#include<iostream>
using namespace std;
//REFERENCE 16.3//
void reverse(string a){
	if(a.length()==0)  //if the length of the string is zero which means no elements are presentd then return //
	return ; 
	string rev=a.substr(1);   //EACA AND EVERY TIME WE ARE REDUCING THE STRING BY ONE LOCATION //
  reverse(rev);  
  cout<<a[0]; 
}
int main(){
	reverse("ravi kumar");	
}
