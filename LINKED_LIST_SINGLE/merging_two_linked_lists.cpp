#include<iostream>
using namespace std;

class node{
     public:
     int data;
     node*next;
     node*prev;
     node(int dup_data){
     data=dup_data;
     next=NULL;
     }
};
 void add_node(node* &head,int value){
        node *new_node=new node(value);
        if(head==NULL){
             head=new_node;
             return ;
        }
          node*temp=head;
           while(temp->next!=NULL){
                temp=temp->next;
           }
           temp->next=new_node;
 }

 node*merge(node*&head1,node*&head2){
      node*ptr1=head1;
      node*ptr2=head2;
      node*dummy_node=new node(-1);
      node*result=dummy_node;
      while(ptr1!=NULL and ptr2!=NULL){
          if(ptr1->data<=ptr2->data){
               result->next=ptr1;
               ptr1=ptr1->next;
          }
          else{
               result->next=ptr2;
               ptr2=ptr2->next;
          }
          result=result->next;
      }
      while(ptr1!=NULL){
           result->next=ptr1;
           ptr1=ptr1->next;
      }
      while(ptr2!=NULL){
           result->next=ptr2;
           ptr2=ptr2->next;
      }
      return dummy_node->next;
 }
 node*merge_recursive(node*&head1,node*&head2){
      if(head1==NULL)
      return head2;
      if(head2==NULL) return head1;

      node*result;
      if(head1->data<head2->data){
           result=head1;
           result->next=merge_recursive(head1->next,head2);
      }
      else{
           result=head2;
            result->next=merge_recursive(head1,head2->next);
      }
      return result;

 }
 void display(node *head){
        node*temp=head;
        while(temp->next!=NULL){
             cout<<temp->data<<"->";
             temp=temp->next;
        }
        cout<<temp->data;
        cout<<"\n";
   }
   int main(){
        node*head1=NULL;
        node*head2=NULL;
        add_node(head1,1);
        add_node(head1,3);
        add_node(head1,5);
        add_node(head1,7);
        add_node(head1,9);
        add_node(head2,-1);
        add_node(head2,5);
        add_node(head2,7);
        add_node(head2,9);
        node*result=merge(head1,head2);
       //node*result=merge_recursive(head1,head2);
     //    display(head1);
     //    display(head2);
        display(result);
   }