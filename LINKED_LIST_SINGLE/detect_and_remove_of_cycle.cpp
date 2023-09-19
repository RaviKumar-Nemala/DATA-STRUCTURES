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

bool is_cycle(node *&head){//this boolean function is used to check weather the given list has a cycle chain involved or not//
     node * fast=head;
     node*slow=head;
     while(fast!=NULL && fast->next!=NULL){//it is possible by simply taking the two pointers called as fast and slow//
          fast=fast->next->next;//increment the fast value every time 2steps //
          slow=slow->next;//increment the slow value every time 1 step//
          if(fast==slow){//if there is a loop in our list then these two pointers must meet then we return true//
               return true;
          }
     }
     return false;//if there is no cycle chain involved then we can say there is no chain involved//
}

void make_cycle(node*&head,int pos){
     node *temp=head;//in order to make cycle we need to take the parameter as pos it gives at which position that we need to make our cycle//
     node * start_cycle=NULL;
     int count=1;
     while(temp->next!=NULL){
          if(count==pos){//if our position is equal to the count value then we need to start the our  cycle from this part//
               start_cycle=temp;//start cycle is used to take the reference part of that node that we want  make the reference//
          }
          temp=temp->next;
          count++;
     }
     temp->next=start_cycle;//once the list reaches the end then we need toassign our temp pointer next to previously stored start_chain pointer then it become a cycle chain//
}
void display(node *head){
        node*temp=head;
        while(temp!=NULL){
             cout<<temp->data<<" \n";
             temp=temp->next;
        }
   }
   void remove_cycle(node *&head){
        node *fast=head;//it is the crucial part if we want to remove our the cycle_chain then we need two pointers
        node*slow=head;
        do{
             fast=fast->next->next;
             slow=slow->next;
        }while(slow!=fast);//in this loop we need to identify at which position that the chain has started //
        fast=head;//after finding the loop then take any one of the node and make the value as head it points to the first
        while(fast->next!=slow->next){
             fast=fast->next;//now increment both pointers one by one note that fast pointer coming from first  i.e from the head node
             slow=slow->next;//slow pointer value doesn't change which means it continuing its before existing value
        }//againg these two are meeted at one point i.e our chain_node and our last node is always points to that chain node//last node value is stored on the slow pointer not fast pointer becaz fast pointer value is coming from the front where as the slow pointer value is comint from the back
        slow->next=NULL; //so make the slow pointer to the NULL then it doesn't point to that chain node//
   }


  
   
int main(){
     node*head=NULL;
     //iteration_list();
     add_node(head,"first member");
     add_node(head,"second_kumar");
     add_node(head,"third_member");
     add_node(head,"fourth_member");
     add_node(head,"fifth_member");
     add_node(head,"sixth_member");
     make_cycle(head,2);
     if(is_cycle(head))
     cout<<"there is a cycle"<<endl;
     else
     cout<<"there is no cycle"<<endl;
     remove_cycle(head);

     display(head);
}
