#include<bits/stdc++.h>
using namespace std;

struct Node 
{
     int data ;
     Node   *left ;
     Node * right ;
     Node( int data)
     {
          this -> data=data ;
          this -> left= nullptr;
          this -> right = nullptr; 
     }
};


void postorder( Node * root )
{
     stack < Node *  > st1 ;

     stack < Node * > st2;

     st1.push ( root ) ;

     while ( !st1.empty())
     {
          Node * curr = st1.top () ;
          st1.pop();
          st2.push ( curr ) ;
         
          if( curr -> left )
          {
               st1.push ( curr -> left ) ; 
          }
           if ( curr -> right )
          {
               st1.push ( curr -> right ) ;
          }
     }

     while ( !st2.empty() )
     {
          cout << st2.top () -> data <<" " ;
          st2.pop () ;
     }
}


void preorder( Node* root )
{
     Node *curr = root ;

     stack <Node * > st;
     st.push ( root ) ;
     while ( !st.empty() )
     {
          curr = st.top () ;

          st.pop();
          cout << curr -> data <<" " ; 

          if ( curr -> right )
          {
               st.push ( curr -> right );
          }
          if ( curr -> left )
          {
               st.push ( curr -> left ) ;
          }
     }




}

void inorder ( Node  *curr )
{
     stack <Node* > st;

     Node *root = curr ;

     while( true )
     {
          if ( root != nullptr )
          {
               st.push ( root );
               root  = root -> left;
          }
          else 
          {
               if( st.empty() )
               {
                    break;
               }

               root = st.top (); st.pop ();
               cout << root -> data << " " ; 
               root = root -> right;
          }
     }


}



int main (){

     Node*root = new Node( 1 ) ;
     root ->left  = new Node ( 2 ) ;
     root -> right = new Node( 3 ) ;
     root -> left -> left  = new Node ( 4 ) ;
     root -> left -> right = new Node( 5 ) ; 
     root -> right -> left= new Node( 6 );
     root -> right -> right = new Node ( 7 );
     // inorder (root ) ; 
     // preorder( root );
     postorder( root ) ;
     return 0 ;
}