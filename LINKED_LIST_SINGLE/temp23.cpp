#include<bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     Node *left ;
     Node *right;
     Node ( int data)
     { 
          this -> data = data;
          this -> left = nullptr;
          this->right = nullptr;
     }
};
int get_max_idx(  vector <int > &preorder ,int start , int end , int key )
{
      for  ( int idx =  start ; idx <= end ;  idx ++ )
      {
          if (  preorder  [idx]  > key )
          {
               return idx;
          }
      }

      return  end + 1 ; 

}
Node * build_tree ( vector < int > &preorder  , int start , int end ) 
{    
     static int idx = 0 ;

     if ( idx >= preorder.size ()  or start >  end )
     {
          return nullptr;
     }

     Node *root =new Node( preorder [ idx ] ) ;

     idx ++;

     if ( start == end )
     {
           return root ; 
     }

     int div_idx = get_max_idx ( preorder , start , end , root -> data ) ;

     root-> left = build_tree(  preorder , idx , div_idx -1 ) ;

     root -> right = build_tree ( preorder,  div_idx , end);

     return root ;

}

void inorder ( Node  * root )
{
     if ( !root )
     {
           return ;
     }

     inorder( root -> left ) ;

     cout << root -> data << " " ;
     
     inorder ( root -> right ) ; 

}

int main () 
{
     vector < int > preorder = { 10, 5, 1, 7, 40, 50 } ;

     Node * root = build_tree(preorder ,  0 ,  preorder.size()  - 1 ) ;

     inorder ( root ) ; 

     return 0;
}