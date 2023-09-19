#include<bits/stdc++.h>
using namespace std;

struct node 
{
     int data;
     node *next ;
     node *prev;
     node( int data )
     {
          this -> data = data ;
          this -> next  = nullptr;
          this -> prev = nullptr;
     }
};

bool _is_empty ( node *head )
{
     return  !head ? true : false;
}

node *get_node ( int data ){
     return new node ( data);
}

void add_node ( node *&head,  int data )
{
     node *new_node = new node( data);
     if ( _is_empty ( head ))
     {
          head = new_node;
     }
     else
     {
          node *temp  = head ;

          while ( temp -> next != nullptr)
          {
               temp = temp -> next;
          }

          new_node -> prev =  temp ;
     
          temp -> next= new_node;

     }
     return;
}

void display ( node *head )
{
     while ( head ->next != nullptr)
     {
          cout << head -> data <<" ";
          head  = head -> next;
     }
     cout << head -> data << endl;
     return;
}

void add_util ( int *arr , int length , node *&head )
{
     for (int i = 0;   i < length  ; i ++ )
     {
          add_node ( head , arr [i ]);
     }
     return;
}

void add_at_first (  node *&head  , int data)
{
     node *new_node = get_node ( data);
     if ( head == nullptr)
          head = new_node;
     head -> prev = new_node;
     new_node-> next= head ;
     head = new_node;
     return;
}
void add_at_last ( node *&head, int data )
{
     node *new_node = get_node ( data ); 

     if ( head == nullptr){
          head = new_node;
          return;  
     }

     node * temp =head ;
     while ( temp -> next )
     {
          temp = temp -> next;
     }

     temp -> next = new_node ;
     new_node-> prev= temp;
     return;
} 

void add_at_any ( node *&head,  int data  , int pos ) 
{
     node *new_node = get_node( data);

     if ( pos == 1 )
     {
          head ->prev = new_node;
          new_node->next = head ;
          head = new_node;
          return;
     }

     int count =1 ;

     node *temp = head ;

     while (temp ->next  !=nullptr and count < pos-1 )
     {
          count ++;
          temp = temp -> next;
     }
     if ( temp -> next ){
     temp->next->prev = new_node;
     new_node -> next = temp -> next ;
     new_node->prev = temp;
     temp-> next = new_node;
     }
     else
     {
          new_node->prev = temp ;
          temp->next = new_node;
     }
     return;
}


void delete_at_first ( node *&head )
{
     node *temp = head; 
     head = head -> next;
     free(temp);
     return;
}

void delete_at_last ( node *&head)
{
     node *temp = head ; 
     
     while ( temp -> next -> next != nullptr)
     {
          temp = temp -> next;
     }
     
     free ( temp -> next );
     temp -> next = nullptr;
     return;

}

void reverse_list ( node* &head )
{
     node  *curr_node = head ;
     node *prev = nullptr;
     node *next_node = head ;
     
     while ( next_node )
     {
          next_node = curr_node-> next ;
          curr_node->next = prev;
          prev = curr_node ;
          curr_node = next_node;
     }

     head = prev;
     return;
}
int main ( int no_of_args , char **args)
{
     node *head = nullptr;
     int arr [5 ] = { 1 , 2,3 , 4, 5 };
     add_util ( arr , 5 , head );
     display( head );
     add_at_first ( head , 22);
     add_at_last( head , 66);
     display ( head);
     delete_at_first(head);
     display ( head );
     delete_at_last( head ) ;
     display ( head );

     add_at_any( head,  99 ,6) ;
     display ( head );

     reverse_list ( head );
     display ( head);
}