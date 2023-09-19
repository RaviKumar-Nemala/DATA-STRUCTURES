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

int get_mid_val_optimal ( node *head )
{ 
     int res = -1 ;

     if ( head == nullptr)    return res;

     node *fast = head ;

     node *slow = head ;

     while ( fast  and fast -> next != nullptr)
     {
          fast = fast -> next -> next  ;

          slow = slow -> next;
     }

     res  = slow -> data ;
     
     return res ;
}

int get_mid_val ( node *head )
{
     int res = -1;

     if ( !head )return res;

     int count = 0;

     node *curr_ptr = head ; 

     while ( curr_ptr != nullptr)
     {
          curr_ptr = curr_ptr-> next;
          count ++;
     }
     curr_ptr = head ;
     for ( int  i = 0 ; i < count / 2; i ++ )
     {
          curr_ptr = curr_ptr -> next;
     }

     res =  curr_ptr -> data;

     return res;
}


int main ()
{
     int arr [  5 ] = {  10 ,20 , 30 , 40 ,  50};

     node *head = nullptr;

     for ( int i = 0 ; i < 5 ; i ++ )
     {
          add_node ( head , arr [ i ] ) ;
     }
     cout << get_mid_val ( head ) <<endl;
     cout << get_mid_val_optimal( head )<<endl;
     return 0;
}