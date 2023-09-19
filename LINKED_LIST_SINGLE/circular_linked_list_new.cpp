#include<bits/stdc++.h>
using namespace std ;

struct node {
     int data ; 
     node *prev ;
     node *next ;
     node ( int data)
     {
          this -> data = data ;
          this ->prev = nullptr ;
          this -> next = nullptr;
     }
};

void display ( node *head )
{ 
     node *temp = head ;
     while ( temp -> next  != head )
     { 
          cout << temp -> data << " ";
          temp =temp -> next;
     }
     cout<<temp->data<<endl;
     return;
}
node * get_node ( int data)
{
     node  *new_node = new node ( data);
     return new_node;
}
void add_node ( node *&head , int data)
{
     node *new_node = get_node ( data);

     if ( head == nullptr)
     {
          new_node ->prev = new_node  ;
          new_node -> next = new_node;
          head = new_node;
     }
     else 
     {
          node *temp  = head ;
          while( temp -> next  != head)
          {
               temp = temp -> next;
          }
          new_node->prev  = temp ;
          new_node -> next = head ;
          head -> prev  = new_node;
          temp->next = new_node;
     }

     return;
}

void add_at_first ( node *&head , int data  )
{
     if ( head == nullptr)
     {
          head = get_node ( data );
          head ->prev = head ; head -> next = head;
     }
     else 
     {
          node *new_node = get_node ( data);
          
          node *last_node = head -> prev ;
          new_node->prev = last_node;
          new_node->next = head ;
          last_node->next = new_node;
          head ->prev = new_node;
          head = new_node;
     }
     return;
}

void add_at_last ( node *&head , int data ) {

     node *new_node = get_node ( data );

     if( head == nullptr)
     {
          new_node ->prev = new_node ;
          new_node ->next = new_node;
          head = new_node;          
     }
     else 
     {
          head ->prev->next = new_node;
          new_node->prev = head ->prev;
          head->prev = new_node;
          new_node->next = head;
     }
     return;
}

void add_at_any ( node *&head , int data , int pos )
{
     node *new_node = get_node ( data) ;

     if ( pos ==1 )
     { 
          add_at_first ( head , data );
     
     }
     else 
     {
          int count = 1 ; 
          node *temp = head ;
          while (  temp -> next != nullptr and count  < pos -1)
          {
               count ++;
               temp = temp -> next;
          }

          node  * adj_node    = temp -> next;     

          new_node -> prev = temp ; 
          new_node->next = adj_node;
          adj_node -> prev = new_node;
          temp->next = new_node;
     }
     return;

}

void delete_first ( node *&head  )
{
     node *new_first = head -> next;

     node *last_node  = head -> prev;

     new_first  ->prev  = last_node;

     last_node->next = new_first;

     free ( head );

     head = new_first ;

     return;
}

void delete_last ( node *&head  )
{ 
     node *latest_last =  head -> prev -> prev ;

     latest_last -> next =  head ;

     free ( head ->prev );
     
     head ->prev = latest_last;

     return;
}

void delete_at_any ( node *&head , int pos  )
{ 
     
     if ( pos == 1 )
     {
          delete_first ( head );
     }
     else 
     {
          int count = 1 ; 

          node *temp = head ;
          while ( temp -> next  != nullptr  and  ( count  <  pos -1 )) 
          { 
               temp = temp -> next ;
               count ++;
          }
          
          node * del_node = temp -> next;

          temp -> next = del_node -> next;

          del_node ->next ->prev = temp;

          free (del_node);
     }

     return;
}

int main (  )
{
     node *head = nullptr; 

     vector <int >data = { 1, 2,3,4,5};

     vector < int > ::iterator it = data.begin(); 

     for ( ; it !=data.end(); it++)
     {
          add_node (head , *it );
     }

     // add_at_first( head , 11);

     add_at_last ( head , 22);

     display ( head );

     add_at_any ( head , 33 ,  2);

     display ( head );
     
     delete_first ( head );

     display ( head );

     delete_last ( head );

     display ( head );

     delete_at_any( head , 3);

     display ( head );

     return 0;

}
