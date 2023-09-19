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

void display  ( node *head )
{
     while ( head-> next  != nullptr)
     {
          cout << head -> data  <<" " ;
          head  = head -> next;
     }
     cout << head -> data << endl;
     return;
}

node * get_node ( int data )
{
     return new node ( data);
}

node*  rev_list_recursive (  node *curr , node *prev )
{
     if ( curr == nullptr)    return prev;

     node *next = curr ->next ;

     curr ->next = prev;

     return rev_list_recursive ( next , curr);
}


node *reverse_itrative ( node *head  )
{
     if ( head -> next != nullptr)    
          return nullptr;

     node *new_head = head  -> next ;   

     new_head -> next = head ;

     head -> next = nullptr;

     return new_head;

}



int main  ()
{
     node *head = nullptr ;

     int arr  [ 5] =  { 1 , 2,  3, 4,  5 } ;
     for  ( int  i  = 0 ;i < 5 ;i  ++ )
     {
          add_node ( head , arr [i ]) ;
     }
     display ( head );

     cout <<"AFTER REVERSING THE LIST"<< endl;

   head = rev_list_recursive ( head , nullptr);

     display( head);

     return 0;
}