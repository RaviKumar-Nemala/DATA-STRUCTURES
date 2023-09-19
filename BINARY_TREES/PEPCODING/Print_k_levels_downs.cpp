#include<bits/stdc++.h>
using namespace std;
struct Node{
     int data;
     Node*left;
     Node*right;
     Node(int dup_data){
          data = dup_data;
          left=NULL;
          right=NULL;
     }
};

void print_K_levels_down  ( Node *root , int k )
{

     if ( root == nullptr )
     return ; 
     if ( k == 0 )
     {
          cout << root -> data << " " ; 
     }

     print_K_levels_down( root -> left , k -1 ) ;

     print_K_levels_down( root -> right , k -1 ) ; 

}


void print_K_levels_down ( Node *root , int k , int temp )
{

     
     queue < Node* > q ; 
     q.push ( root ) ;
     q.push ( nullptr ) ; 
     int level = 0 ;
     while  ( !q.empty () )
     {

          Node * temp =  q.front () ;

          q.pop ( ) ; 
          
          if ( temp != nullptr )
          {

               if ( level == k )
               {

                    cout << temp -> data  <<" " ; 
               }
               if ( temp -> left )
               {

                    q.push ( temp -> left ) ;
               }
               if ( temp -> right )
                    q.push ( temp -> right )  ; 
               
          }
          else if ( !q.empty ( ) ) 
          {
               
               q.push ( nullptr ) ;
               level ++ ; 

          }

     }

}

int main () 
{

     Node *root = new Node  ( 1 ) ;

     root -> left = new Node  ( 2 ) ; 

     root -> right = new Node ( 3 )  ;

     root -> left -> left = new Node  ( 4) ;

     root -> left -> right = new Node  ( 5 ) ;

     print_K_levels_down  ( root ,  2 , 0 ) ; // op - > 4 ,5 
     
     print_K_levels_down ( root->left , 1  , 0  )  ;  //op - > 4 ,5 


     //this will print the elements of two levels down from the root node 

/*
          1

       2       3   

     4   5  

*/
}