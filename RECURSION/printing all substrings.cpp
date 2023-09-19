#include<iostream>
using namespace std;

void sub_string(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return ;
	}
	char ch=s[0];
	string temp=s.substr(1);
	sub_string(temp,ans);
	sub_string(temp,ans+ch);
}
int main(){
	string s="abc";
	sub_string(s,"");
}
