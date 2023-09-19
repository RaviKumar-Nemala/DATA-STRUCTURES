#include<bits/stdc++.h>
using namespace std;

struct node 
{

     int val ;

     node *left ; 
     
     node *right ;

     node   ( int val )
     {

          this -> val =  val ;
     
          this -> left = nullptr;

          this -> right = nullptr ; 

     }

};


bool isLeaf ( node *root )
{
     if ( root and !root->left and !root -> right )
     return true;
     else
     return false;


}


string post_order(   node * root , map  < string , int >  &mp )
{

          if ( !root )
               return "$";

          if ( isLeaf ( root ) ) 
          {
               
               return to_string ( root -> val  ) ;

          }


          string sub_tree_val = "";

          sub_tree_val += post_order (  root -> left , mp ) ;

          sub_tree_val += to_string( root -> val ) ;

          sub_tree_val += post_order ( root -> right,  mp );

          mp [  sub_tree_val ] ++;

          return sub_tree_val ;

}


void solve ( node * root )
{

     if ( !root )
     return ;

     map < string ,  int > mp ;

     string temp =  post_order ( root ,  mp );
     
     bool flag = true ;

     for ( auto it : mp )
     {

          if ( it.second >= 2 )
          {
          
               cout << true << endl;

               flag =false;
          
               break;
          
          }

     }

     if  ( flag )   
     {

          cout << false << endl ;


     }

}

class Solution 
{

     public :

     int max_sum  = INT_MIN ;

     void config ( node * root, int val )
     {

          root_to_leaf_max_sum ( root , val ) ;

          cout << max_sum << endl ;

     }


     int total = 0 ;

     void root_to_leaf_max_sum   (  node  *root , int total  )
     {

          if (!root )
          return  ;

          

          total =  total +  root -> val ;

          if ( isLeaf ( root ))
          {

               if ( total > max_sum )
               {
                    max_sum = total ;
               }
               return ;

          }

          root_to_leaf_max_sum ( root -> left  , total ) ;

          root_to_leaf_max_sum ( root ->right, total ) ;

          total = total - root->val ;

          return ;

     }
     




};

 int main (  )
{

     node * root = new node ( 1 ) ;

     root -> left = new node ( 2 ) ;

     root -> right = new node ( 3 ) ;

     root -> left -> left = new node ( 4 ) ;

     root -> left -> right = new node ( 5 ) ;
     
     root -> right -> right  =new node ( 2 ) ;

     root -> right -> right -> left = new node ( 4 );

     root -> right -> right -> right = new node ( 5);


     //solve ( root ) ;
     
     Solution obj  ;

     obj.config ( root, 0 );




}








