#include<bits/stdc++.h>

using namespace std;


struct node 
{
     
     int data ;

     node * left ;

     node *right ;

     node ( int data )

     {

          this -> data = data ;

          this -> left= NULL;

          this -> right = NULL;

     }


};

 vector< node *> path;


class Solution
{

public:
    

     bool node_to_root ( node *root ,int key )
     {

          if ( !root)
               return false;

          if( root->data == key )
          {
               cout<<root->data << endl;
               path.push_back ( root) ;
               cout<<"lfja";

               return true;
          }

          bool left = node_to_root ( root-> left, key  ) ;

          bool right = node_to_root ( root->right , key );

          if( left or right )
          {
               path.push_back ( root ) ;
               return true;
          }
          else
          {
               path.pop_back();
               return false;
          }

     }


     void print_val ( )
     {
          for( auto it : path)
     {
          cout <<it-> data << "  " ;

     }
     return ;
     }



};


int main () 
{

     node *root = new node ( 1 );

     root -> left = new node  ( 2 ) ;

     root -> right = new node ( 3 );

     root -> left -> left = new node ( 4 );

     root -> left -> right = new node ( 5 ) ;

     root ->right ->left = new node ( 6 ) ;

     root -> right ->right = new node( 7 );

     root -> right-> left -> left = new node( 8 );

     root -> right-> left-> right = new node ( 9 );

     root -> right -> right -> left =  new node(12);

     root -> right -> right -> right = new node ( 11 ) ;


     Solution obj;

     obj.node_to_root( root  , 8 ) ;

     obj.print_val();



}

