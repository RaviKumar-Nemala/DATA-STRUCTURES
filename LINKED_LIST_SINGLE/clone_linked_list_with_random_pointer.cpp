#include<bits/stdc++.h>
using namespace std;

class node{
     public:
     int data;
     node*next;
     node *random;
     node(int dup_data){
     data=dup_data;
     next= nullptr;
     random =  nullptr;
     }
};
 void add_node(node* &curr,int value){
        node *new_node=new node(value);
        if(curr==NULL){
             curr=new_node;
             return ;
        }
          node*temp=curr;
           while(temp->next!=NULL){
                temp=temp->next;
           }
           temp->next=new_node;
}

void display  ( node *curr )
{
     while ( curr-> next  != nullptr)
     {
          cout << curr -> data  <<" " ;
          curr  = curr -> next;
     }
     cout << curr -> data << endl;
     return;
}

node * get_node ( int data )
{
     return new node ( data);
}

node * clone_list (  node *head ) 
{
     //STEP -1 PLACE THE DUPLICE NODES AFTER EVERY NODE 
     // BEFORE = 1 -> 2 -> 3 -> 4 
     //AFTER  = 1 -> 1-> 2 -> 2-> 3-> 3-> 4-> 4

     node *curr = head;

     while ( curr != nullptr)
     {
          int curr_data = curr -> data;

          node*new_node = get_node( curr_data);

          new_node-> next= curr ->next;

          curr -> next = new_node;

          curr = new_node-> next;
     }

     display ( head );

     // STEP-2 copy the random pointers of the original nodes and the cloned nodes

     curr = head ;

     while ( curr != nullptr)
     {
        
          curr -> next-> random  = curr-> random ? curr-> random : nullptr;
          if ( curr -> next)
          curr = curr -> next -> next;

     }

     //STEP-3 seperate the cloned linked list from the original list

     node*cloned_list= head -> next;

     node *curr_cloned = head -> next;
     curr = head;


     while ( curr != nullptr)
     {
          curr -> next = curr -> next -> next;

          curr_cloned-> next = curr_cloned->next ? curr_cloned->next->next : nullptr;

          curr_cloned = curr_cloned->next;

          curr = curr -> next;
     }

     cloned_list->next-> data = 445 ; //manupulating the data on the cloned list does not impact on the original list 
     //same with random pointers changing the random pointers on the cloned list does not impact on the original list
     display (  cloned_list); //printing the cloned list 

     display ( head );  //printing the original list
}

int main ( )
{    
     node *first_node = get_node ( 1 );

     node *second_node = get_node (2 ) ; 

     node *third_node = get_node ( 3 ) ;

     node *fourth_node = get_node (  4) ;

     first_node -> next = second_node;

     second_node -> next = third_node ;

     third_node-> next= fourth_node ; 

     //PLACING THE RANDOM POINTERS
     first_node->random =  third_node;

     second_node->random =  fourth_node;

     third_node ->random  = second_node;

     clone_list( first_node );

     return 0;
}