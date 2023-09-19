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

node *swap_by_k ( node *head,  int k ) 
{
     if ( head ==  nullptr)
          return head;
     node *curr = head ;
     node * next = head;
     node *prev = nullptr;
     int count = 0;
     while ( curr != nullptr and count < k )
     {
          count ++;
          next =curr  -> next;
          curr-> next= prev;
          prev = curr ;     
          curr = next;
     }    
     if ( curr !=nullptr)
     {
          head -> next = swap_by_k ( curr , k );
     }
     return prev;
}

int main ()
{
     int arr [  5 ] =  { 1 , 2 , 3 , 4 , 5  } ; 

     node  * head = nullptr ; 

     for ( int i  = 0 ; i < 5 ; i ++ )
     {
          add_node ( head , arr [ i ] ) ; 
     }
     add_node( head , 6) ;

     display( head );
     
     display ( swap_by_k ( head , 2 ) ) ;

     return 0 ;     
}