#include<bits/stdc++.h>
using namespace std ;

struct node
{
     int data;
     node*left;
     node*right;
     node(int data)
     {
          this->data = data;
          this->left= nullptr;
          this->right = nullptr;
     }
};

void print_val ( vector < int > res)
{
     for ( auto it : res )
     {
          cout << it <<" " ; 
     }
     cout<< endl;
}

node * deserialize (vector< int  > values ) 
{
     queue <  node * > q ;

     int idx = 0 ;

     int curr_val =  values [ idx ] ;

     node * root= new node ( curr_val ) ; 

     int n = values.size();

     q.push(root) ;

     while ( !q.empty() )
     {

          node * curr_node = q.front();

          q.pop();

          idx ++;

          if ( idx < n and values [ idx ] != INT_MIN )
          {
               node *left_node = new node ( values [ idx ]) ;
               curr_node-> left= left_node ;
               q.push (left_node ) ; 
          }
          else 
          {
               curr_node ->  left = nullptr;
          }
          idx ++;

          if ( idx < n and values [ idx ] != INT_MIN)
          {
               node* right_node = new node( values[ idx ]) ;
               curr_node ->right = right_node ; 
               q.push (right_node) ; 
          }
          else 
          {
               curr_node -> right = nullptr;
          }
     }
     return root;
}



vector<int> serialize( node *root )
{

queue< node* > q;

vector<int>res ;

q.push ( root ) ;

     while( !q.empty())
     {
          node *curr_node = q.front();
          q.pop();
          
          if ( curr_node  != nullptr)
          res.push_back(curr_node -> data );
          else 
          {
               res.push_back( INT_MIN);
          }
          
          if( curr_node )
          {
                  q.push ( curr_node -> left);
               
                    q.push ( curr_node -> right);
          }
          
     }
     // print_val ( res ) ;
     return res; 
}

void inorder (node* root )
{
     if ( root == nullptr) return;
     inorder( root -> left ) ;
     cout << root -> data <<" " ;
     inorder (root -> right );
}

int main ()
{
     node * root = new node( 1 ) ;

     root -> left = new node ( 2 ) ;

     root -> right = new node ( 3)  ;

     root ->left -> left =new node ( 4) ;

     root -> left -> right = new node( 5) ;

     vector < int > res = serialize ( root );
     root = deserialize ( res ) ;
     inorder (root );
}