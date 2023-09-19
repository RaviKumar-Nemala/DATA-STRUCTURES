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
void add_at_first (  node *&head  , int data )
{
     node *new_node = new node ( data);
     new_node -> next = head ;
     head = new_node;
     return;
}

void insert(  node *&head, int  data)
{   

     node *new_node = get_node ( data ) ; 

     if (  data <  head -> data)
     {
          add_at_first ( head , data );
          return;
     }
          
     node *temp = head ;

     while ( temp->next != nullptr  and temp ->next-> data < data )
     {
               temp = temp -> next;
     }

     if ( temp -> next)
     {
          new_node -> next = temp -> next;

          temp -> next = new_node;
     }
     else 
     { 
          temp -> next = new_node; 
     }

     return;
}

/**
 * given the sorted linked list 
 * need to insert the element in the appropriate position so that after the insertion list should be sorted
*/
int main ( )
{
     int arr [  5 ] = {  10 ,20 , 30 , 40 ,  50};

     node *head = nullptr;

     for ( int i = 0 ; i < 5 ; i ++ )
     {
          add_node ( head , arr [ i ] ) ;
     }
     display ( head );
     insert( head , 60);
     display  (head );
     return 0; 
}