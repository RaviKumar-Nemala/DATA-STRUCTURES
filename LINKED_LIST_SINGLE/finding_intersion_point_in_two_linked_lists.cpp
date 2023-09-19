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
 int count_nodes(node*&head){
     node*temp=head;int count=0;
     while(temp!=NULL){
          temp=temp->next;
          count++;
     }
    return count;
}
int intersection(node*&head1,node*&head2){
     int first_legth=count_nodes(head1);
     int second_legth=count_nodes(head2);
     node*ptr1=NULL;
     node* ptr2=NULL;
     int difference=0;
     if(first_legth>second_legth){
          difference=first_legth-second_legth;
          ptr1=head1;
          ptr2=head2;
     }
     else{
          ptr1=head2;
          ptr2=head1;
     }
     while(difference){
          ptr1=ptr1->next;
          if(ptr1==NULL){
               return -1;
          }
          difference--;
     }
     while(ptr1!=NULL and ptr2!=NULL){
          if(ptr1==ptr2){
               return ptr1->data;
          }
          ptr1=ptr1->next;
          ptr2=ptr2->next;
     }
     return -1;
}
void display  ( node *ptr)
{
     while  ( ptr != nulltptr)
     {   }
}
void make_intersection(node*&head1,node*&head2,int pos){
     node*ptr1=head1;
     node*ptr2=head2;
     pos--;
     while(pos){
          ptr1=ptr1->next;
          pos--;
     }
     while(ptr2->next!=NULL){
          ptr2=ptr2->next;
     }
     ptr2->next=ptr1;
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
     add_node(head1,2);
     add_node(head1,3);
     add_node(head1,4);
     add_node(head1,5);
     add_node(head1,6);
     add_node(head2,9);
     add_node(head2,10);
     make_intersection(head1,head2,3);
     display(head1);
     display(head2);
     cout<<"\n";
     cout<<"PRINTING THE INTERSECTION POINT : ";
     cout<<intersection(head1,head2);






}
