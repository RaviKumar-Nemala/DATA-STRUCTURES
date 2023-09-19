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

int get_list_size (node *head )
{
     int count = 0 ;

     while ( head != nullptr)
     {
          count ++;
          head = head -> next;
     }
     return count;
}

int get_last_node ( node *head ) 
{
     while ( head -> next !=nullptr)
     {
          head = head -> next;
     }
     return head -> data;
}

int get_first_node ( node *head )

{
     return head -> data ;
}

int get_nth_node_from_end ( node *head ,int pos)
{
     if ( pos == 1 )
     {
          return get_last_node( head );
     }

     int total_length =  get_list_size ( head ) ;

     cout <<"TOTAL LENGTH = " << total_length <<endl;
     
     cout << "BEFORE POS = "<< pos << endl;

     pos = total_length - pos ;

     if ( pos == 0 ) 
     {
          return get_first_node ( head );
     }
     cout << "AFTER POS = " << pos << endl; 

     int count =  1 ; 

     node *temp = head ;

     while ( temp-> next != nullptr and  count  < pos -1 )
     {
          temp = temp -> next;
          count ++;
     }    
     return temp -> next -> data;

}

int get_nth_node_from_end_optimal (  node *head  , int pos )
{
/**
 * @brief move the fast pointer  n ( pos )  steps to front 
 * then start slow pointer to the head  
 * move the slow pointer and fast pointer by one step
 * when the fast pointer reaches to the end then slow pointer is at the required place
 */

     node *fast  = head ;

     node *slow = head ;

     while ( pos --)
     {
          fast = fast -> next;
     }

     while ( fast != nullptr  )
     {
          fast = fast -> next ;
          slow  = slow -> next;
     }
     int res = slow -> data;
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
     
     cout<<get_nth_node_from_end ( head , 5)<< endl;

     cout << get_nth_node_from_end_optimal(head ,1)<< endl;

     return 0; 
}