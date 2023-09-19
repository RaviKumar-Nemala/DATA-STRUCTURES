#include<iostream>
using namespace std;

void per(string s,string ans){
	if(s.length()==0){
	  cout<<ans<<endl;
	  return;
	}
	int i;
	for(i=0;i<s.length();i++){
		char ch=s[i];
		string temp=s.substr(0,i)+s.substr(i+1);
		per(temp,ans+ch);
	}
}
int main(){
	string a="123";
	per(a,"");
}
