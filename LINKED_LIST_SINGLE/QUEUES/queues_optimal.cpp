#include<iostream>
#include<stack>
using namespace std;
class queue{
     public:
     stack<int>s1;
     void push(int data){
       s1.push(data);
     }
     int pop(){   
          if(s1.empty()){  //it is the initial condition if no elements are initially at the stack then we would say stack is empty//
               cout<<"queue is empty"<<endl;
               return -1;
          }
          int x=s1.top();//furst we store top element on the stack into varaible x`//
          s1.pop();//then stack gots on pop() operation 
          if(s1.empty()){//after poping if the stack is empty then that value that we store before that 'x ' would become the first value then we simply return that value//
               return x;
          }//it is the essential condition it is not only use ful for if the stack consists of only element after performing our required element is always stored in the element x and x becomes our popping element becaz in queue removing the element is always possible on the front that is why we recursively call the function until the stack is becomes empty  once stack is empty the before element has to be popped////////////////////////////////
          int item=pop();//here we calling the function recursively after function has done the element is which we get is stored on this item from the value x//
          s1.push(x);//once we get the item the remaining elements are stored on the stack//
          return item;//our required element is on the item variable so we need to return that value to the previous function calls`
     }
     bool empty(){
          if(s1.empty()){
          return true;
          return false;
     }
     }
};
int main(){
queue obj;
obj.push(1);
obj.push(2);
obj.push(3);
obj.push(4);
obj.push(5);
while(!obj.empty()){
     cout<<obj.pop()<<endl;
}
}