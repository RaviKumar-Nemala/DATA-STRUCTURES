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
void even_after_odd(node*&head){ //we are going to place odd numbers at one place and even numbers at one place//
     node*first_even=head->next;;//if we have a linked list like 1->2->3->4->5->6  then result would be 1->3->5->2->4->6//
     node*odd=head; //initially we need print odd numbers so first odd number is the first element of the linked list so we place our odd pointer on the first head //
     node*even=head->next;//here 2 is the first even number which is at 2nd position so we need to place our even pointer at head->next//we also placed first_even beacz once the odd numbers printer we need to attach the first even number address to the last odd numbers link so we maintain another pointer //
     while(odd->next!=NULL && even->next!=NULL){ //
          odd->next=even->next;//odd number holds the next odd number reference on its next part then it moves to that number//
          odd=odd->next;
          even->next=odd->next;;//similiaraly even number hold its next evn number reference on its next place then it moves to that number//
          even=even->next;
     }//this procedure is continues until it reaches to the end//
     odd->next=first_even; //once the odd pointer reaches end we need to assign its next point to our first even number reference//

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
even_after_odd(head);
display(head);
}


