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

/**
 * @brief using the set to store the values of the each node ref in thelinked list 
 * iterate through each node if the node is already in the set then we can sey there is a loop in the list
 * 
 * TIME COMPLEXITY =  O(N)
 * SPACE COMPLEXITY = O(N)
 */
bool is_loop ( node *head )
{
     unordered_set  < node * > nodes_set ; 

     while ( head != nullptr )
     {
          if ( nodes_set.find ( head ) != nodes_set.end() )
               return true;
          nodes_set.insert(head);
          head = head -> next;
     }


     return false; 

}

int  main () 
{
     node *head = new node( 1 ) ;

     node *second_node = new node (2 ) ;
     head -> next = second_node;

     node *third_node   = new node ( 3 );
     second_node-> next = third_node;

     node *fourth_node = new node ( 4 );
     third_node -> next = fourth_node ;

     node * final_node = new node ( 5 ) ;
     // final_node -> next = third_node;//placing the loop
     final_node->next = nullptr;
     if ( is_loop ( head ) ) 
     {
          cout<<"THERE IS A LOOP IN THE LIST"<< endl;
     }
     else 
     {
          cout<<"NO LOOP IN THE LIST" << endl;
     }
}