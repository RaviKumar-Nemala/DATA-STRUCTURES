#include<bits/stdc++.h>
using namespace std;

struct node 
{
     int data ; 
     node*next;
     node ( int data) 
     {
          this -> data = data;
          this -> next= nullptr;
     }
};

void display ( node *head )
{
     while( head != nullptr)
     {
          cout << head -> data <<" " ;
          head = head -> next; 
     }
     cout << endl;
}

void add_node ( node *&head , int data )
{
     
     if (head == nullptr)
     {
          head = new node ( data );
          return;
     }
     node* curr = head ;

     while  (curr->next != nullptr)
     {
          curr = curr -> next;
     }

     curr->next = new node( data);

     return ;
}

node* merge ( node *head_1 , node *head_2)
{
     node *main_node = nullptr;
     node * main_head = nullptr;

     if ( head_1 -> data < head_2 -> data)
     {
          main_head =head_1;
         main_node = head_1 ;
          head_1 = head_1-> next;
     }
     else 
     {
          main_head = head_2;
          main_node= head_2 ;
          head_2  = head_2 -> next;
     }

     while ( head_1 != nullptr and head_2 != nullptr)
     {
          if ( head_1 -> data < head_2 -> data)
          {
               main_node -> next = head_1 ;
               head_1 = head_1 -> next;
          }
          else 
          {
               main_node  -> next = head_2 ; 
               head_2 = head_2 -> next;
          }
          main_node = main_node-> next;
     }

     if ( head_1 == nullptr)
     {
          main_node ->next= head_2;

     }
     else 
     {
          main_node -> next= head_1;
     }
     return main_head ; 

}

int main ()
{
     node *head_1 = nullptr;

     node* head_2 = nullptr;

     int arr [ 5 ]  = { 1 ,2,3,4,5};

     int arr_2 [  3 ] = {  -1 , 6 , 9 } ; 

     for ( int i = 0 ; i < 5 ; i ++ )
      {

          add_node ( head_1 , arr [ i ]  ) ; 

      }

     for ( int  i = 0 ;i  < 3 ; i ++ )
     {
          add_node( head_2  , arr_2[ i ] ) ; 
     }

     node * result =  merge ( head_1 , head_2) ; 

     display ( result ) ; 

     return  0;
}


