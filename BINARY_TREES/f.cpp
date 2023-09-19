#include "tree_code.h"

bool check_for_bst ( Node *root , Node **prev  )
{
    if ( root == nullptr)
    {
        return true;
    }

    if ( !check_for_bst( root  -> left  , prev ) ) return  false;


    if ( *prev !=nullptr and ( *prev)-> data > root ->data ) 
    {
            return false;
    }

    *prev = root; 

    if ( !check_for_bst( root -> right , prev))
    {
        return false;
    }

    return true;


}

int main() 
{
     
     Node *root = new Node  ( 5 ) ;

     root -> left = new Node  ( 3 ) ; 


     root -> right = new Node ( 8 )  ;

     root -> left -> left = new Node  ( 2 ) ;

     root -> left -> right = new Node  ( 4 ) ;

/*

     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 


     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4 ) ;

     root -> left -> right = new Node  ( 5 ) ;

*/
     Node *prev = nullptr ; 
     cout << check_for_bst ( root , &prev ) << endl ;


}
