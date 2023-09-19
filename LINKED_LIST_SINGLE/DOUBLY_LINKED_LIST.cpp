#include<iostream>
using namespace std;

class node{
     public:
     string data;
     node*next;
     node*prev;
     node(string dup_data){
     data=dup_data;
     next=NULL;
     prev=NULL;
     }
};
int count_nodes(node*);
void rem_first(node*&head){
     node*temp=head;
     head=head->next;
     head->prev=NULL;
     free(temp);
}
void del_last(node*&head){
     node*temp=head;
     while(temp->next!=NULL){
          temp=temp->next;
     }
     temp->prev->next=NULL;
     delete temp;
}
void del_particular_node(node*&head,int loc){
    if(loc==1){
         rem_first(head);
         return;
    }
    else if(loc==(count_nodes(head))){
         del_last(head);
         return;
    }
    else{
         node*temp=head;
         loc--;
         while(loc!=1)
         {
          temp=temp->next;
              loc--;
         }
         node*mover=temp->next;
         temp->next=mover->next;
         mover->next->prev=temp;
         free(mover);
    }
}
void insert_first(node*&head,string value){
     node *n=new node(value);
     if(head!=NULL){
          n->next=head;
          head->prev=n;
          head=n;
     }
     else{
   head=n;
     }
}
void add_node(node*&head,string value){
     if(head==NULL){
          insert_first(head,value);
          return ;
     }
     node*n=new node(value);
     node *temp=head;
     while(temp->next!=NULL){
          temp=temp->next;
     }
     temp->next=n;
     n->prev=temp;
}
void display(node *head){
        node*temp=head;
        while(temp!=NULL){
             cout<<temp->data<<" \n";
             temp=temp->next;
        }
   }
int count_nodes(node*head){
     node*temp=head;int count=0;
     while(temp!=NULL){
          temp=temp->next;
          count++;
     }
     return count;
    // cout<<"\nprinting the count  of the nodes: "<<count<<" ";
}
int main(void ){
     node*head=NULL;
     add_node(head,"first_node");
     add_node(head,"second_node");
     add_node(head,"third_node");
     add_node(head,"fourth_node");
     add_node(head,"last_node");
     //insert_first(head,"before first");
     del_particular_node(head,4);
     display(head);
     //count_nodes(head);

}