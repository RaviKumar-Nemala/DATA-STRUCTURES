#include<bits/stdc++.h>
using namespace std ;

class My_Stack 
{
     private :
     vector<int> data  ; 
     int last_idx = -1;
     public : 

     void push  ( int data ) 
     {
          this->data.push_back ( data ) ;
          last_idx ++ ;
     }

     int  top () 
     {
          return  this-> data[  last_idx ] ;
     }

     int size () 
     {    
          return ( last_idx + 1 );
     }

     void  pop ()
     {
         this-> last_idx --;
         
     }

     void print_val (  )
     {
          int temp =last_idx ;
          while ( temp >= 0 )
          {
               cout << this  -> data [ temp]  <<" "  ; 
               temp --;
          }
          return;
     }

};

int main ()
{    
     My_Stack my_stack;

     my_stack.push ( 1 ) ;

     my_stack.push ( 2 ) ;

     my_stack.push(  3 ) ;

     my_stack.push ( 4) ;

     my_stack.pop();

     my_stack.print_val ();

     cout<< endl << my_stack.size() <<  endl ;
     return 0;
}