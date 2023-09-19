#include<bits/stdc++.h>
using namespace std;

class node{
     public:
     int data;
     node*next;
     node(int dup_data){
     data=dup_data;
     next= nullptr;
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

// given the node reference we need to delete the node in the O( 1 ) tc 
void delete_node ( node *&ref  ) 
{
     if ( ref == nullptr)
          return; 
     if ( ref -> next )
     {
          node  *next_node = ref -> next;
          ref -> next = next_node -> next;
          ref -> data = next_node -> data;
          free ( next_node);
     }
     return;
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

     cout <<"AFTER DELETING THE NODE"  << endl;

     delete_node ( head -> next -> next->next->next);

     display  ( head );

     return 0;
}
