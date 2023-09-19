#include<iostream>
using namespace std;
//use reference 16.3//
string dup(string a){
	if(a.length()==0)  //LOOP WILL ITERATE UNTIL LENGTH IS EQUAL TO ZERO//
	return "";
   char ch=a[0];
   string temp=dup(a.substr(1)); 
   if(ch==temp[0])
   return temp;
   else
   return temp+ch;
}
int main(){
	string a="aba";
	cout<<dup(a)<<endl;
	
	
	
}
