#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;
void reverse_sentence(string a){
     stack<string>my_stack;
     int i;
     for(i=0;i<a.length();i++){
          string word="";
          while(a[i]!=' '&&i<a.length()){
               word+=a[i];
               i++;
          }
          my_stack.push(word);
     }
     while(!my_stack.empty()){
          cout<<my_stack.top()<<" ";
          my_stack.pop();
     }
}
int main(){
     string temp="what the fuck?";
     cout<<temp<<endl;
     reverse_sentence(temp);
}