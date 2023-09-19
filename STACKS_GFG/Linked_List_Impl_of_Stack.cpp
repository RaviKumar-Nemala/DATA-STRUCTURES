#include<bits/stdc++.h>
using namespace std ;

class My_Stack 
{
     private : 
     struct node 
     {
          int data ; 
          node *next;
          node (int data)
          {
               this -> data = data ;
               this -> next = nullptr;
          }
     };

     node * head = nullptr;
     
     int size  ; 
     public:
     
     My_Stack () 
     {
          this->size = 0 ; 
     }

     void push ( int data )
     {
          node * temp = new node ( data );
          this->size ++;
          if ( head == nullptr)
          {
               head  = temp;
               return;
          }

          temp-> next=  head;
          head = temp;
     }
     bool isEmpty()
     {
          if ( head == nullptr)return true;
          return false;
     }

     void pop ( ) 
     {
          if ( head == nullptr){ cout <<"STACK IS EMPTY" << endl;
          return; 
          }

          node *temp = head ;

          head = head -> next ;

          delete( temp );

          this->size --;
     }    

     int get_size ( )
     {
          return this-> size ;
     }

     void print_val ()
     {
          node * temp = head ;
          while ( temp != nullptr)
          {
               cout <<temp -> data << " " ;
               temp = temp -> next;
          }
     }

};

int main ()
{
     My_Stack my_stack;

     my_stack.push ( 1 ) ;

     my_stack.push ( 2 ) ;

     my_stack.push(  3 ) ;

     my_stack.push ( 4) ;

     my_stack.pop();

     my_stack.print_val ();cout<< endl;

     cout << my_stack.get_size () << endl;
     return 0;
}