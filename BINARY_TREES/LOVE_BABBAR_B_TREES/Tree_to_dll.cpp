#include <iostream> 
using namespace std ; 

struct Node
{

     int data ; 
     Node *left ;
     Node * right ; 
     
};

Node *addNode ( int data  )
{

     Node *temp =  new Node() ;
     temp -> data =  data ; 
     temp -> left = nullptr ;
     temp-> right = nullptr ;

     return temp ;

}
class Solution
{
    public:
    
    
    Node *prev = nullptr ; 
    
    Node *head = nullptr ;
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        
         util ( root );
        
        return head ; 
        
    }
    
    void util ( Node * root  )
    {

        if ( root == nullptr )    
            return  ; 
        
        util  (  root -> left ) ;
        
        if ( prev == nullptr )
        {
            prev = root ; 
            head = root ;
        }
        else 
        {
            
            prev -> right =  root ; 
            
            root -> left = prev ; 
            
            prev = root ; 
        }
        
        util( root -> right  ) ;
    }
};

int main () 
{




}