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
node* append(node*&head,int pos){  //in this problem  we need to append the list of numbers according the given position////////////////////////////////
  //example if the list is 1->2->3->4->5->6 if position is 3 then the o/p become 4->5->6->1->2->3 we need to append the list//
     int count=1;
     node*new_head=NULL;  //in order to append like that first we need to change the actual list//
     node*new_tail=NULL;  //after changing the links new_head_becomes the first node and new_tail becomes the last_node//
     node*tail=head;//it is used to traverse the list//
     int length=count_nodes(head); //if the pos is 3  and the total list is of size 6then our new_head points to the 4th node//
      pos=pos%length;///in order to do like that we need to use count the nodes first we find the length of the list//
     while(tail->next!=NULL){
      if(count==(length-pos)){//if the count value is equal to the substraction  of length of the list  and the postion that we giving then it would becmod our modified last_node//
           new_tail=tail;
      }
      if(count==(length-pos+1)){//if the length is equal to the sub of length and pos +1 then that is our first head(modified value)//
           new_head=tail;//here +1 is used becaz of the count varaible starts from 1//
      }
      tail=tail->next;
      count++;
     }
     tail->next=head;//after traversal the last node points to the head (actual first node)
     new_tail->next=NULL;//it becomes the last node//
     return new_head;//it becomes the new_head value//
}
void display(node *head){
        node*temp=head;
        while(temp!=NULL){
             cout<<temp->data<<" \n";
             temp=temp->next;
        }
   }
int main(){
     int k=2;
     node*head=NULL;
      add_node(head,1);
     add_node(head,2);
     add_node(head,3);
     add_node(head,4);
     add_node(head,5);
     add_node(head,6);
    head= append(head,3);
     display(head);
}



