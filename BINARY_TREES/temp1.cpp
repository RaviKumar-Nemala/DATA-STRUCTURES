#include<iostream>
#include <bits/stdc++.h>
using namespace std; 

struct Node 
{
     int data ;
     Node*left ;
     Node *right ; 

     Node( int t )
     {
          this ->data  = t ; 
          left = right = NULL;

     }
};

void leftView ( Node * root )
{

     if ( root == nullptr )
          return ; 

     queue < Node *> q ; 
     q.push ( root  ); 

     while (!q.empty () )
     {

          int n =  q.size() ;
          
          for ( int  i = 0 ;i < n ;i ++ )
          {

               Node *temp = q.front () ; 

               if( temp == NULL )
               {
                    continue ;
               }
               q.pop();

               if (  i == 0 ) 
               {

                    cout << temp -> data <<" " ;


               }
               if ( temp -> left )
               {
                    q.push ( temp -> left );
               }

               if ( temp -> right )
               {
                    q.push ( temp -> right );
               }


          }

     }
}

void rightView ( Node *root )

{

     if  ( root == nullptr )
     {
               return ;
     }

     queue < Node * > q ;

     q.push ( root  ) ;


     while ( !q.empty () )
     {

          int n = q.size() ;

          for (int i = 0 ; i < n ;  i ++ )
          {
               Node *temp = q.front () ; 

               q.pop () ;

               if ( i == n-1 )
               {
                    cout << temp -> data << " " ; 
               }

               if( temp -> left )
               {
                    q.push ( temp -> left ) ;
               }

               if ( temp -> right )
               {
                    q.push ( temp -> right ) ;
               }


          }


     }
     


}

vector   < int > diagonal_traversal_anti_clock ( Node *root )
{

          vector < int > ans ; 

          if ( root  == nullptr)
               return ans ; 
          
          queue < Node * > q ; 
          q.push ( root ) ;
          
          while (!q.empty () )
          {

               Node * curr = q.front ()  ; 

               q.pop ( ); 

               while  ( curr ) 
               {
               
                    
                    if ( curr -> right ) 
                         q.push ( curr -> right )  ;

                    ans.push_back ( curr -> data ) ;
                    curr  = curr -> left ;                     

               }


          }
          return ans ; 

}
 vector < int  > diagonal_traversal ( Node *root )

{
     if ( root == nullptr )
          return  { } ;
     
     queue< Node* >   q; 

     q.push ( root  ) ;

     vector < int > ans ;


     while ( !q.empty () )
     {

          Node *curr = q.front ()  ; 

          q.pop ( ) ; 

          while  (curr != nullptr )
          {

               if ( curr -> left )
               {

                    q.push ( curr -> left ) ;


               }


               cout << curr -> data << " ";
              // ans.push_back ( curr -> data ) ;


               curr = curr -> right; 

          }


     }

     return ans ; 
}


void printVal ( vector < int > ans )
{

     for ( auto  it : ans )
     {    
          cout << it <<  "  "  ; 
     }

     return  ;
}
int main()
{

     Node *root = new Node ( 1 ) ; 

     root -> left = new Node ( 2 ) ;

     root -> left -> left = new Node ( 3 ) ;

     root -> left -> right = new Node( 4 ) ;

     root -> left -> left -> left = new Node( 5 ) ;

     leftView ( root );

     cout << endl; 

     rightView ( root );

     cout << endl  ; 


     vector < int > ans = diagonal_traversal ( root ) ;


     cout << endl ; 

     printVal ( diagonal_traversal_anti_clock ( root ) )  ; 


} 
     

     







