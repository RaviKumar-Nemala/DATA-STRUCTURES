#include<bits/stdc++.h>

using namespace std ; 

struct Node 
{

     int data  ; 
     Node *left , * right ; 
     Node (  int  t )
     {
          this -> data = t ; 

          left = right = nullptr ; 
     }
     
};

bool Node_to_root ( Node *root ,int target ,  vector  < int  >&path )
{

     if ( root == nullptr )
     return false ; 


     path.push_back ( root -> data )  ; 

     if  ( root -> data == target )
     {

          return true; 
     
     }

    bool case_1 =   Node_to_root ( root-> left , target  , path ) ; 

     bool case_2 =  Node_to_root ( root -> right , target, path )  ;

     if ( case_1 or case_2 )
     {
          return true ; 
     }
     else 
     {
          path.pop_back ( ) ; 
          return false ; 

     }

}
bool util ( Node * temp )
{
     if ( temp == nullptr)
     {
          return false ;
     }
     if ( (temp->left  and  !temp->right  ) or ( temp->right and !temp-> left )  ) 
     {
          return true ;
     }
}
void single_child ( Node * root ,  Node *parent )
{

     if ( root == nullptr or parent == nullptr)
     return ; 

     
     if ( util ( parent ) )
     {
          cout << root -> data << " " ;
     }



     single_child ( root -> left ,root ) ; 

     single_child ( root -> right  , root ) ; 

     return;
}

bool root_Node ( Node *root  , int target_val ,vector < int  > &ans ) 
{

     if ( root == nullptr )
          return  false ;  

     if ( root -> data == target_val )
     {
          ans.push_back  ( root -> data ) ;
          
          return true ;
     
     }
     
     bool c1 = root_Node ( root -> left , target_val , ans) ; 

     if ( c1 )
     {

          ans.push_back ( root -> data ) ; 
          return true ;
     }

     bool c2 = root_Node ( root ->right , target_val  , ans ) ; 
     
     if ( c2 )
     {
          ans.push_back ( root -> data ) ; 
          return true ;
     }
     return false ; 
}
void printPath ( vector <  int > a )
{
     for ( auto it : a )
     {

          cout << it << " "  ; 

     }
     cout << endl ; 
     return ; 
}

int main ( )
{

     Node *root = new Node (  1 ) ;  

     root -> left = new Node ( 2 ) ; 

     //root -> left-> left = new Node ( 3  ) ; 

     //root -> left -> right = new Node ( 4 ) ;

    // root -> right = new Node  ( 5  ) ; 

     single_child  (root , nullptr ) ; 


     /*
                   1 
       
               2       5
       
            3    4
      */

     /*
     vector < int > ans; 

     int target_val = 0 ; 

     int test_cases  = 5 ; 


     while (test_cases >= 0)
     {
     
     cin.ignore() ; 

     cout << "ENTER THE TARGET_VAL : "  ; 

     cin >> target_val  ; 



     bool res =  root_Node ( root , target_val , ans ) ; 
     
     if ( res ) 
     
     {
     
          printPath ( ans );
     
     } 
     
     else 
     
     {
     
          cout << " PATH NOT FOUND " << endl ; 
     
     }

     test_cases -- ; 

     ans.clear ( ) ; 

     }

     */

     return 0 ; 
}