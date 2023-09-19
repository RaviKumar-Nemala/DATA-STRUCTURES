#include<iostream>
using namespace std;
//use reference 16.3//
string shift_x_to_last(string name){
	if(name.length()==0)
	return "";
	char ch=name[0];
	string temp=shift_x_to_last(name.substr(1));
	if(ch=='x')
	return temp+ch;
	else 
	return ch+temp;
}





int main(){
	string name="afbdxadfxsxxxxadf";
	cout<<shift_x_to_last(name)<<endl;
	
	
}
