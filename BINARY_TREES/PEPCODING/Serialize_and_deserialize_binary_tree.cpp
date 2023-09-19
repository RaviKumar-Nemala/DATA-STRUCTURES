#include "tree_code.h"

string  serialize (  Node *root ) 
{

     string s ; 
     
     queue< Node *> q ; 

     q.push ( root )  ; 

     while ( !q.empty ( ) )
     {
          
          Node *curr =  q.front ()  ;
          q.pop () ; 

          if ( curr == nullptr ) s.append ("#,");
          
          else  s.append ( to_string  ( curr -> data ) + ',' ) ; 

          if ( curr != nullptr )
          {
               q.push ( curr -> left ) ; 
               
               q.push (  curr -> right ) ; 

          }

     }

     return s ; 

}

void inorder( Node *root )
{

     if ( root == nullptr )
          return ; 
     inorder ( root -> left ) ; 
     
     cout << root -> data << " "; 
      
     inorder ( root -> right ) ; 

}

Node *deserialize (  string str )
{

     stringstream ss(str ) ; 

     queue <  Node * >  q ; 

     string s ; 

     getline (  ss, s , ',') ;
     
     int temp_data =  stoi (  s ) ;

     Node *root =  new Node  ( temp_data  ) ;

     q.push ( root ) ; 

     while ( !q.empty ( ) )
     {
          
          Node *curr =  q.front ( ) ;
          q.pop () ; 

          getline ( ss , s ,  ',');

          if ( s == "#")
          {
               curr -> left = nullptr ; 

          }

          else
          {
               temp_data =  stoi (  s ); 
               
              

               Node *left_node =  new Node  ( temp_data ) ;
               
               curr-> left = left_node; 

               q.push (  left_node ) ; 

          
          }

          getline ( ss , s , ',');

          if ( s == "#")
          {
               curr -> right =  nullptr ; 
          }
          else 
          {
               temp_data  =  stoi ( s ) ; 

             //  cout << temp_data << endl;
               Node *right_node  = new Node  ( temp_data ) ; 

               curr -> right = right_node ; 

               q.push ( right_node ) ;

          }

     }


     return root ; 

} 

int main  ()
{

Node *root =  new  Node ( 1) ; 

root  -> left = new Node ( 2 ) ; 

root -> right = new Node ( 3 ) ; 

root -> left -> left = new Node ( 4)  ; 

root -> left -> right = new Node  ( 5 ) ; 

inorder ( root ) ;  

cout << endl ; 

string res = serialize (root ) ; 

cout << res << endl ;


root =  deserialize (  res ) ; 

inorder( root ) ; 


}