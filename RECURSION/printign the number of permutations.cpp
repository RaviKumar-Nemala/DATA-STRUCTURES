#include<iostream>
using namespace std;
//USE REFERENCE 16.4//
void permutate(string s,string ans){
 if(s.length()==0){
 cout<<ans<<endl;
 return ;
}
 int i;
 for(i=0;i<s.length();i++)
{
	char constant=s[i];
	string before_and_after_values=s.substr(0,i)+s.substr(i+1);
	permutate(before_and_after_values,ans+constant);
}
}
int main(){
	
	string name="ABC";
	permutate(name,"");
	
}
