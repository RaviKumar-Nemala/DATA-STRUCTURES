#include "tree_code.h"

Node *leftClone ( Node *root )
{

     if ( root == nullptr )
     return nullptr ;

     Node *left  = leftClone ( root -> left ) ;

     Node * right = leftClone ( root ->right ) ;

//create the same node and attach the root -> left to this new node then one clone of the same node will be formed 

     Node * new_node = new  Node ( root -> data,  left , nullptr  );

     root -> left = new_node ;

     root -> right = right ; 

     return root ; 

}


Node* leftClone_to_Normal ( Node *root )
{

     if  ( root == nullptr )
     return nullptr ; 

    Node * new_left =  leftClone_to_Normal  ( root -> left -> left ); // left -> left will remove left clone of the node and gives the correct noed

     Node * new_right = leftClone_to_Normal ( root -> right ) ;  // no need to use the right -> right becuase node lo left side matrame clone chestunnamu right as it is untundi


     root -> left = new_left ;

     root -> right = new_right ; 

     return root ;

}

void preOrder ( Node *root )
{
     if ( root == nullptr )
     return ; 

     cout << root -> data <<" " ;

     preOrder ( root ->left );

     preOrder ( root -> right ) ;

     
     
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

     root = leftClone(root ) ; // making the left clone 

     preOrder ( root ) ;  cout <<endl ;

     root = leftClone_to_Normal ( root ) ; // removing the left clone 

     preOrder ( root ); 

     return 0 ; 


}

