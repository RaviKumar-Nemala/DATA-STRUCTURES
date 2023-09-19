#include<bits/stdc++.h>
using namespace std ;

// in our cache memory the max list size is 4 
//if list is full then need to remove the least recently used item
#define LIST_MAX_SIZE  4

int list_size = 0 ; 



struct node 
{
     int data  ; 
     node *prev ; 
     node *next;

     node ( int data  ) 
     {
          this -> data = data;
          this -> prev  = nullptr;
          this -> next = nullptr;
     }
};

unordered_map  < int , node* > nodes_map;

node *first_ptr  = nullptr;

node *last_ptr = nullptr;

void place_at_first ( node*node_ref ) 
{
     
          // check if the node_is the first node in the list
          if( node_ref -> prev == nullptr)
          {
               return ;
          }
          //if the node is not the first then place it in the first place
          else 
          {
               node_ref -> prev-> next = node_ref-> next;
               
               first_ptr -> prev =  node_ref ; 

               node_ref -> next =  first_ptr;

               node_ref -> prev = nullptr;

               first_ptr = node_ref;
          }
     }       

void remove_last_node ()
{
     node  *temp = last_ptr;

     last_ptr = last_ptr -> prev;

     last_ptr -> next=  nullptr;

     free( temp );

}

void store_in_map ( int data , node*node_ptr)
{
     nodes_map[data] = node_ptr;
} 


void add_node (int data )
{
     if ( list_size == 0 )
     {
          node* new_node = new node (data) ;
          first_ptr =  new_node;
          store_in_map ( data , new_node);
          list_size ++;
          return;
     }

     node *node_ref = nodes_map [ data];

     if ( node_ref )
     {
          place_at_first ( node_ref );
          return;
     }
     if ( list_size >= LIST_MAX_SIZE)
     {
          remove_last_node (  );
     }     

     list_size ++;

     node *new_node = new node( data);

     first_ptr ->prev = new_node ;

     new_node -> next=first_ptr;

     first_ptr  = first_ptr -> prev;

     store_in_map ( data , new_node);
}

node * find_node (  int data ) 
{
     if( nodes_map.find ( data) != nodes_map.end() ) 
     {
          return nodes_map[ data]  ; 
     }
     else 
     {
          return nullptr;
     }
}


void display ( )
{
     node *head = first_ptr ;

     while ( head != nullptr)
     {
          cout << head -> data<<" " ; 
          head = head -> next;
     }
     cout << endl;
}

int main ()  {

     node *head = nullptr;

     int arr [] = { 10 ,  20,  10 , 30 , 40 ,50}  ; 

     for( int i  = 0 ; i <  6 ;i ++ )
     {
          add_node ( arr[ i ] )  ;
     }
     display( );
     return 0 ; 

}