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
void add_node(node*&head,int data){
     node *n=new node(data);
     if(head==NULL){
          head=n;
          return;
     }
     else{
          node *temp=head;
          while(temp->next!=NULL){
               temp=temp->next;
          }
          temp->next=n;
     }
}
void even_after_odd(node*&head){
     node*first_even=head->next;
     node*odd=head;
     node*even=head->next;
     while(odd->next!=NULL && even->next!=NULL){
          odd->next=even->next;
          odd=odd->next;
          even->next=odd->next;;
          even=even->next;
     }
     odd->next=first_even;
}
void display(node*head)
{
     while(head->next!=NULL){
          cout<<head->data<<" ->";
          head=head->next;
     }
     cout<<head->data;
}
int main(){
  node*head=NULL;
  int a[6]={1,2,3,4,5,6};
  for(int i=0;i<6;i++)
  add_node(head,a[i]);
even_after_odd(head);
display(head);
}


