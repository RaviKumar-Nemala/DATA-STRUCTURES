#include<iostream>
using namespace std;

class node{
     public:
     int data;
     node*next;
     node(int dup_data){
          data=dup_data;
          next=NULL;
     }
};
class queue{
     public:
     node*first=NULL;
     node*last=NULL;
     bool is_empty(){
          if(first==NULL){
               return true;
          }
          else 
          return false;
     }
     void push(int data){
          node*n=new node(data);
          if(first==NULL){
               first=n;
               last=n;
          }
          else{
          last->next=n;
          last=n;
     }
}
     void pop(){
          if(first==NULL)
          {
               cout<<"queue is under flow"<<endl;
               return;          
          }
          else{
               node *temp=first;
               first=first->next;
               free(temp);
          }
     } 
     int peek(){
          if(is_empty()){
               return -1;
          }    
          else{
               return first->data;
          }
     }
};
int main(){
  queue obj;
  for(int i=1;i<=100000;i++){
  obj.push(i);
}
while(!obj.is_empty()){
     cout<<obj.peek()<<endl;
     obj.pop();
}
}