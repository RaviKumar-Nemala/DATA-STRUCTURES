#include<iostream>
#include<stack>
using namespace std;
int main(){
     stack<char>st;
     string s="((a+b))";//here you can see extra pair of braces are present so we can say redunt braces are present in this string if we take eg: (a+(a+b)) in this example redunt braces are not present//
     bool ans ;
     for(int i=0;i<s.size();i++){
          if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'){
               st.push(s[i]);
          }
          else if(s[i]=='(')
               st.push(s[i]);
          else if(s[i]==')') //if this occurs then what ever the top element on the stack must be an operator then only the brace is required if the top of the stack is an closed brace then we say one open and one closed braces presented without having the operator in that case we simply make our bool ans as true
          {
               if(st.top()=='('){//this is esential case
                    ans=true;
               }
               while(st.top()=='+'||st.top()=='*'||st.top()=='/'||st.top()=='-'){
                    st.pop();//if in case the top of the stack is consists of any one of the following then we simply pop that element 
               }
               st.pop();//this is used to pop the ')' brace//
          }
     }
     if(ans)
     cout<<"redunt braces are present"<<endl;
     else  cout<<"redunt braces are not present"<<endl;
}