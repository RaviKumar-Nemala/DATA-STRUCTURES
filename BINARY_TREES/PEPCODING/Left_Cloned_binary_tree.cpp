#include<bits/stdc++.h>

using namespace std;


struct Node
{
     int data; 
     Node *left ; 
     Node *right ;

     Node  ( int d )
     {

          data = d ;
          left = nullptr ;
          right = nullptr ;
     }

     Node  ( int d , Node * l , Node *r)
     {
          data = d ; 
          left = l ;
          right = r ; 
     }


};


void preOrder ( Node *root )
{
     if ( root == nullptr )
     return ; 

     cout << root -> data <<" " ;

     preOrder ( root ->left );

     preOrder ( root -> right ) ;

     
     
}

Node *leftClone ( Node *root )
{

     if ( root == nullptr )
     return nullptr ;

     Node *left  = leftClone ( root -> left ) ;

     Node * right = leftClone ( root ->right ) ;

     Node * new_node = new  Node ( root -> data,  left , nullptr  );

     root -> left = new_node ;

     root -> right = right ; 

     return root ; 




}




int main () 
 {
       
        
     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4) ;

     root -> left -> right = new Node  ( 5 ) ;

 /*
          1

       2       3   

     4   5  
     
     */

     preOrder ( root ); 
     cout << endl ; 
     
     preOrder ( leftClone ( root )  ) ;

     return  0 ; 

 }