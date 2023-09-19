#include<iostream>
using namespace std;
int main(){
	int n;
	printf("enter the n value");
	cin>>n;
	cin.ignore();
	char word[n+1];
	cin.getline(word,n);
	cin.ignore();
  int current_length=0,max_length=0;
  int i=0;
  while(1){
  	if(word[i]==' '||word[i]=='\0'){
  		if(current_length>max_length)
  		max_length=current_length;
  		current_length=0;
	  }
	  else{
	  	current_length++;
	  }
	  if(word[i]=='\0'){
	  break;
}
	  i++;
  }
  cout<<max_length+1<<endl;
}
