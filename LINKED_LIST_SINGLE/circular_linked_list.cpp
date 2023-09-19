#include<iostream>
using namespace std;

class node{
     public:
     int data;
     node*prev;
     node*next;
     node(int dup_data){
          data=dup_data;
          prev=NULL;
          next=NULL;
     }
};
void add_first(node*&head,int data){
     node* n=new node(data);
     if(head==NULL){
     n->prev=n;
     n->next=n;
     head=n;
     }
     else{
          node*temp=head;
          while(temp->next!=head){
               temp=temp->next;
          }
          n->next=head;
          n->prev=head->prev;
          temp->next=n;
          head=n;
          free(n);
     }
   }
void add_node(node*&head,int data){
     if (head==NULL){
         add_first(head,data);
         return;
     }
     else{
     node*temp=head;
     while(temp->next!=head){
          temp=temp->next;
     }
     node *n1=new node(data);
     temp->next=n1;
     n1->prev=temp;
     n1->next=head;
     head->prev=n1;
}
}
void display(node*head){
  node*temp=head;
  node*temp1=head;
 while(temp->next!=head){
      cout<<temp->data<<"->";
      temp=temp->next;
 }
}
void remove_last_node(node*&head){
     node*temp=head->prev;
     temp->prev->next=head;
     head->prev=temp->prev->prev;
}
void remove_first(node *&head){
     node*temp1=head;
     node*temp2=head->next;
     temp2->prev=temp1->prev;
     temp1->prev->next=temp2;
     head=temp2;
}
int count_nodes(node*head){
     node*temp=head;int count=0;
     do{
          count++;
     }while(temp->next!=head);
     return count;
}
void remove_pos(node*&head ,int pos){
     if(pos==1){
          remove_first(head);
     }
     else{
     pos--;
     node*temp=head;
     while(pos!=1){
          temp=temp->next;
          pos--;
     }
     node*temp2=temp->next;
     temp2->next->prev=temp;
     temp->next=temp2->next;
}
}
int main(){
     node*head=NULL;
     add_node(head,1);
     add_node(head,2);
     add_node(head,3);
     add_node(head,4);
     add_node(head,5);
     add_node(head,6);
     /*add_first(head,0);
     add_first(head,44);
     remove_first(head);
     remove_first(head);*/
     //remove_pos(head,3);
     remove_pos(head,3);
     display(head);
}