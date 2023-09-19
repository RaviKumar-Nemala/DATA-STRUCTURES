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

void  even_after_odd(node* &head){
    node*even=head->next;
    node*odd=head;
   node* first_even=head->next;
   node*first_odd=head;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        if(odd->next){  //we have used this condition becaz at last point even is going to be the null and it is going towards the invalid memory address// 
        even->next=odd->next;
        even=even->next;
        }
    }
    even->next=first_odd;
    head=first_even;
    //return odd;
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
  int n=7;
  int a[n]={1,2,3,4,5,6,7};
  for(int i=0;i<n;i++)
  add_node(head,a[i]);
 // display(head);

even_after_odd(head);
display(head);
}

