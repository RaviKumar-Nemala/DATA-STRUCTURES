
//REFERENCE  = https://youtu.be/lQIXz5NJYLs

#include<bits/stdc++.h>
using namespace std;

struct node 
{
     int val ; 

     node * left ;
     
     node * right ;

     node ( int val )
     {
          this -> val = val ;
          
          this -> left = nullptr ;

          this ->right = nullptr ;

     }

};


node*  get_predecesor (  node * root  )
{

         if ( !root )
               return nullptr;

         while ( root -> right  )
         {
               root = root -> right ;
         }

         return root ;

}

node* get_successor ( node * root )
{

          if ( !root )
               return nullptr;

          while ( root -> left )
          {
               root = root -> left ;
          }

          return root ;

}


void solve  ( node * root , int key , node* &pred , node* &succecor)
{

          if (!root )
          return ;

          int curr_node_val = root -> val ;

          if ( key == curr_node_val )
          {

               if ( root -> left )
               {
                    pred = get_predecesor  ( root -> left ) ;

               }
               if  ( root -> right )
               {
                    succecor = get_predecesor (  root-> right ) ;
               }
               return;
          }
          if( key < curr_node_val )
          {
               succecor =  root ;
               solve ( root -> left ,  key , pred , succecor ) ;
          }
          if ( key > curr_node_val  )
          {
               pred = root  ;

               solve ( root-> right , key , pred , succecor ) ;
          
          }

          return ;

}



int main ( ) 
{

     
     node * root = new node ( 20 ) ;

     root -> left = new node(  8 ) ;

     root -> right = new node ( 22 ) ;

     root -> left -> left = new node ( 4) ;

     root -> left -> right = new node  (12 ) ;

     root -> left -> right ->left = new  node ( 10);

     root -> left -> right -> right  = new  node ( 14) ;


     node* pred = nullptr ;

     node *succ = nullptr ;

     int key = 22 ;

     solve ( root,  key , pred , succ ) ;

     if ( pred )
     cout << "PREDESOR OF : "<< key << " = "<< pred->val<< endl;
     if( succ)
     cout<< "succecor of :"<< key <<" = "<< succ -> val << endl;

}



