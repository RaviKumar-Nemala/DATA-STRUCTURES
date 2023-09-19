#include<bits/stdc++.h>
using namespace std ;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void add_ele( int ele ,  DLLNode ** tail )
{ 
    (*tail)-> next =new DLLNode(  ele );
    (*tail) = (*tail)-> next;
    return;
}
void printList(DLLNode *head)
{
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

DLLNode* rotate_k (  DLLNode * head  , int k )
{ 
     int count = 0 ;
     DLLNode* curr = head;
     DLLNode  * fast = head ;
     DLLNode * last = nullptr ;
     while( count < k  and curr != nullptr)
     {
          fast = curr -> next ;
          curr->next = last;
          curr ->prev = fast;
          last = curr ;
          curr = fast;
          count ++;
     }

     if ( fast != nullptr)
     {
        DLLNode* res = rotate_k ( fast  ,  k );
        res ->prev = head ;
        head -> next = res ;
     }
     return  last;
}

int main ()
{ 
     DLLNode * head = new DLLNode ( 1 ) ;
     DLLNode * tail =  head ;
     int n = 8;
     int k = 3;

     int arr[] = { 2 , 3 , 4, 5, 6, 7 , 8 } ;

     for ( int idx = 0 ; idx < n-1 ;idx ++ )
     { 
          add_ele (  arr[ idx ] ,  &tail);
     }
     // printList( head ) ;
     printList( rotate_k(head , k )) ;
     return 0 ;
}