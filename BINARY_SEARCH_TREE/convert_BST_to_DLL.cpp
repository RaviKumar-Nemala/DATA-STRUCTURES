#include<bits/stdc++.h>

using namespace std ; 

struct Node 
{

     int data ; 

     Node *left ,*right ; 

     Node ( int data  )
     {
          this -> left = this -> right = NULL ;

          this -> data = data ;
     }

};

class Solution 
{

     Node *head  = NULL ; 
     
     Node *prev = NULL ; 
     

     public : 

     Node* solve ( Node *root )
     {


          if ( root == nullptr )
               return NULL ; 
          
          bst_to_Dll ( root ) ;
          
          return head; 


     }
          void  bst_to_Dll  ( Node *root  )
     {

          if ( root == nullptr )
               return  ; 
               
          bst_to_Dll ( root -> left  ) ; 

          if  ( prev == NULL )
     {
               prev = root ;
 
               head =  root ; 

     }

     else 
     
     {
        
          root -> left = prev ;

          prev -> right = root ; 

          prev = root ; 

     }

     bst_to_Dll ( root -> right  ) ; 

     return;

}

void inorder ( Node *root )
{

     if   ( root == nullptr )
     {
          return ; 
     }
     inorder ( root -> left  ) ;

     cout << root -> data << " " ; 

     inorder ( root -> right ) ; 
     return  ; 


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


};


void printval_left_side ( Node *root )
{

     Node *head = root ;

     while ( head != nullptr )
     {

          cout << head -> data  << " " ;

          head = head -> left ; 

     }

     return ; 

}
void printval_right_side ( Node *root )
{

     Node *head = root ;

     Node *temp = NULL ;

     while  ( head != nullptr )
     {

          cout <<head -> data << " " ;

         

          if ( head -> right == NULL)
          {
               
               temp = head ;

               break;

          }

      head = head -> right ;

          }


     cout<< endl ;

     //TEMP POINTS TO THE LAST VALUE IN THE DLL THEN IT IS A DLL THEN WE CAN GO TO THE FRONT ALSO

     // HERE WE ARE PRINTING THE VALUES FROM THE LEFT TO RIGHT 
     
     printval_left_side( temp ) ;


}

int main  () 
{

     string src = "6,4,9,2,5,7,10,#,#,#,#,#,#,#,#" ; 

     Solution obj ;

     Node *root = obj.deserialize ( src ) ;


     root  = obj.solve ( root ) ; 

     Node *head = root ;

     printval_right_side( head );

     return  0 ; 




/**
 *                       6
 * 
 *                 4           9 
 * 
 *               2   5       7    10
 * 
 * 
 */

}