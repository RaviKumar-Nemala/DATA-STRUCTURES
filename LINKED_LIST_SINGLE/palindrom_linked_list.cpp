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

// using the efficient approach to find out given list is palindrome or not
// reverse the second half of the linked list ( after the mid element)
//compare first element with second half first element 
// compare second element with the second half second element  
//if any mismatch found return false 
// if reach to end then return true;

node *get_mid_node ( node *head)
{
     if ( head and !head-> next)
          return head;

     node *fast = head ;
     node *slow = head ;

     do   
     {
          fast = fast -> next  -> next;
          slow = slow -> next;
     }while( fast != nullptr and fast -> next != nullptr);

     cout << "PRINTING THE MID VALUE =" <<slow ->data  << endl;

     return slow ;
}

node *reverse ( node *head ) 
{
     node *prev =  nullptr;

     node *curr = head ;
     node *next= head ;

     while (next!= nullptr )
     {    
          next= curr -> next;
          curr-> next= prev;
          prev = curr;
          curr = next;
     }

     return prev;
}

bool is_palindrome_linked_list ( node *head)
{

     node * mid_node = get_mid_node ( head ) ; 

     node *second_half_rev_head = reverse ( mid_node -> next );

     node *first = head ;
     node *rev_first= second_half_rev_head ; 
     while ( rev_first !=nullptr)
     {
          if ( first -> data != rev_first -> data)
          {
               return false;
          }
          else 
          {
               rev_first = rev_first -> next;
               first = first -> next;
          }
     }
     return true;
}

int main ( )
{
     // int arr [ 5 ]  = { 1 ,2  , 3 , 2 ,5 } ; 
     
     int arr [ 4 ]  = { 1 ,3 ,2 , 1 } ;

     node *head = nullptr;

     for ( int i   = 0 ;i  < 4 ;i  ++ ) 
     {
          add_node ( head , arr [i  ] ) ; 
     }

     if ( is_palindrome_linked_list ( head   ) ) 
     {
          cout <<" LIST IS THE PALINDROME " ;
     }  
     else 
     {
          cout<<"LIST IS NOT THE PALINDROME";
     }
     return 0;
}