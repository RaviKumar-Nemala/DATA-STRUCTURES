#include<bits/stdc++.h>
using namespace std;


struct node 
{
     int data; 
     node *left;
     node*right;
     node ( int data)
     {
          this -> data = data ;
          this ->left = nullptr;
          this-> right  = nullptr;
     }

};

void left_view ( node *root)
{
     queue<node *>q; 

     q.push ( root ) ;

     while ( !q.empty())
     {
          int size =  q.size();

          for ( int i = 0 ; i < size ; i ++ )
          {
               node *curr_node = q.front ();
               q.pop ();

               if ( i == 0 )  cout << curr_node -> data << " " ; 

               if( curr_node -> left )
               {
                    q.push ( curr_node->left);
               }
               if ( curr_node -> right)
                    q.push ( curr_node -> right);
          }
     }

}



int main ()
{
node *root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->right->right=new node(5);
root->left->left=new node(4);
root->left->right=new node(3);
root->left->right->right=new node(7);

left_view( root ) ; 
 
return 0;

}