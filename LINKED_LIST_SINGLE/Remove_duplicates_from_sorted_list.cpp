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

void remove_duplicates ( node *head ) 
{
     node *curr  = head ; 

     while ( curr  and curr -> next)
     {    
          
          if ( curr->data == curr -> next -> data)
          {
                node  *temp = curr -> next;
                curr -> next = curr -> next -> next;
                free ( temp );
          }
          else 
          {
               curr = curr -> next;
          }
     }

     return;

}

int main( )
{
     int arr [ 6 ] = {  10 , 20 , 30 , 30 , 40 , 40 } ;

     node *head = nullptr;

     for ( int i = 0 ; i < 6 ;  i ++ )
     {
          add_node  ( head , arr [ i ]);     
     }
     
     display(head );

     remove_duplicates ( head );

     display( head);

     return  0 ;
}

