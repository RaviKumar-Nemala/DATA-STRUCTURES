#include<iostream>
using namespace std;
class node{
 public :
 int data;
 node*next;
 node(int val){
data=val;
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

node*rev_list(node*&head,int k){
     node*current=head;
     node*next_ptr=head;
     node*prev=NULL;
     int count=0;
     while(next_ptr!=NULL && count<k){  //first we need to reverse k nodes in the list////////////////
         next_ptr=current->next; //afterreverseig the k nodes suppose k=2 initially head becomes the first node after reversing the head become the second node and it needs to be points the third node//
         current->next=prev;
          prev=current;
         current=next_ptr;
         count++;
     }
     if(next_ptr!=NULL){ //if the list contains only two nodes then next_ptr points the null//
          head->next=rev_list(next_ptr,k);//initially head becomes the first node after reversing the head become the second node and it needs to be points the third node//
     } //we know assignment of head starts from the last then before head address is already availabe on the parameter so we need to assing the parameter next part to our recursive swapping address//
     return prev;  //after swapping the prev pointer is becomes first changing value then in 1-2-3-4 then after first kth reversing 2-1-then 1 shold points the value of the 3 the address value of 3 is availale at next_ptr becaz it moves first//
}

bool search_recursive_gfg (  node *head , int target)
{
     if ( head == nullptr)
          return false; 
     else  if ( head -> data == target )
     {
          return true;
     }

     bool res = search_recursive_gfg( head->next , target);
     
     return res;

}



node *search_recursive (  node *head , node *&res , int target )
{    
     if  ( !head )
          {
              res = nullptr;
              return res;
          }
     else if ( head -> data == target)  
          {
               res = head ;
               
          }
     if ( res )
          return res;
     else 
     search_recursive ( head -> next , res , target);

}

node *  search (  node *head , int target )
{
     if ( !head )
          return head ;
     else if ( head -> data == target)
          return head ;

     while ( head !=nullptr)
     {
          if ( head -> data == target)
                    return head ;
          head = head -> next ;
     }
     return head ;
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
     node *head =new node(1);
     add_node(head,2);
     add_node(head,3);
     add_node(head,4);
     //i/p -> 1->2->3->4//
     //o/p-> 2->1->4->3->NULL;

//      node *res = search ( head , 1);
//      res = nullptr;
//      node *temp = nullptr;
//      res  = search_recursive( head , temp, 10); 

//      if ( res )
//      {
//           cout<< "PRINTING THE ELEMENT :  "<< res -> data<< endl;
//     }
//      else 
//      {
//           cout<<"ELEMET NOT FOUND IN THE LINKED LIST";
//      }


     if ( search_recursive_gfg( head , 77  ) ) 
     {
          cout<<"ELEMENT IS FOUND";
     }
     else 
          cout<<"ELEMENT IS NOT FOUND";

     return 0 ;
}