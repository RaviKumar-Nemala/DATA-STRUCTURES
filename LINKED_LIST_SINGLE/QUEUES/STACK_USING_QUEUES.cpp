#include<iostream>
using namespace std;
#include<queue>
class stack_using_queue{
     public:
     queue<int>q1;
     queue<int>q2;
     int n;
     stack_using_queue(){
          n=0;
     }
     void push(int ele){ //this is the method 1 here push operation is costly////////////////////////////////
          q2.push(ele);//initially take the two queues first take the element on the second queue//
          n++;//n indicated the size of the stack it is not the fixed size here//
          while(!q1.empty()){//once we load the element on the q2 what ever the elements on the q1 are going to store on the q2  note that we are implementing the stack operations therefore it follows lifo principle so in that case we are taking the element from q1 using front method to sotre on the q2// once the q1 becomes empty then we again copy the q2 values on q1 by simply swaping the queus// after that again we take the new element on the q2 then again we copy the values on the q1 using front method until the q becomes empty //
               q2.push(q1.front());//once this process is over last value of the stack is going to be the first element of queue by front() function we take that value//
               q1.pop();
          }
          queue<int>temp;//this is used to swap the queues
          temp=q1;
          q1=q2;
          q2=temp;
     }
     void pop(){
          q1.pop();
          n--;
     }
     int top_value(){
          return q1.front();//top value in stack principle lifo principle satisfy here//
     }
     bool is_full(){
          if(n==5)//here i temparaly declare the size of the n value (stack size)
          return true;
          return false;
     }
     bool empty(){
          if(n==0)
          return true;
          return false;
     }
};
int32_t main(){
     stack_using_queue s1;
     int i=0;
     while(i!=10){
     s1.push(i);
     i++;
     }
     while(!s1.empty()){
          cout<<s1.top_value()<<endl;
          s1.pop();
     }
}