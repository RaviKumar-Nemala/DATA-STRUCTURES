#include<iostream>
using namespace std;

class node{
     public:
     string data;
     node*next;
     node(string value){
          data=value;
          next=NULL;
     }
};
     void add_node(node* &head,string value){
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

   void display(node *head){
        node*temp=head;
        while(temp!=NULL){
             cout<<temp->data<<" \n";
             temp=temp->next;
        }
   }
   void add_first(node* &head,string data){
     node *new_node=new node(data);
     new_node->next=head;
     head=new_node;
   }
   void del_first_node(node * &head){
        node *temp=head->next;
        head=NULL;
        head=temp;
   }
   void del_last_node(node * &head){
        node*temp=head;
        while(temp->next->next!= NULL){
             temp=temp->next;
        }
        node*mover=temp;
        free(temp->next);
       mover->next=NULL;
   }
   void at_position(node* &head,string value,int pos){
       pos--;
       node*new_node=new node(value);
       node*temp=head;
       while(pos!=1){
            temp=temp->next;
            pos--;
       }
       new_node->next=temp->next;
       temp->next=new_node;
}
void del_at_position(node *&head,int pos){
     node * temp=head;
     pos--;
     while(pos!=1){
          temp=temp->next;
          pos--;
     }
     node*mover=temp->next->next;
     free(temp->next);
     temp->next=mover;
}
void iteration_list(){
     node*head=NULL;
     string data;
     int size=3;
     for(int i=0;i<3;i++){
         cin.ignore();
        cout<<"enter the data of the first node"<<" ";
        getline(cin,data);
        add_node(head,data);
     }
     display(head);
}
node* rev_list(node * &head){
     node*first=head;
     node*prev=NULL;
     while(first!=NULL){
          first=head->next;
          head->next=prev;
          prev=head;
          head=first;
     }
     first=prev;//here first = prev we assigned beacz first reaches to the next part of the last link;
     display(first);
     return first;
}
node *rev_list_recursive(node* &head){
     node*new_head=NULL;
     if(head->next==NULL||head==NULL){  //in this algo it reaches the last node then it start assignig value//
          return head;
     }
     new_head=rev_list_recursive(head->next);//it go on resurvie until the last elemetn occurs//
     head->next->next=head;//once it raches the end then assign before before value to its previous value ..
  // previous value is already sotred on the parameter head//
     head->next=NULL;
return new_head;  //each and every time new _head value becomes same//finally it returns that newlist//
}

int main(){
     node*head=NULL;
     //iteration_list();
     add_node(head,"first member");
     add_node(head,"second_kumar");
     add_node(head,"third_member");
     add_node(head,"fourth_member");
     head=rev_list_recursive(head);
     display(head);
     //head=rev_list(head);
     //cout<<"\n";
     //head=rev_list(head);
   //  add_first(head,"adding the node");
     //add_first(head,"adding second node at front");
     //del_first_node(head);
     //del_last_node(head);
     /*at_position(head,"new_inserted_At_2",2);
     at_position(head,"last_pos",6);
     del_at_position(head,2);
     display(head);*/
}