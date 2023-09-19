#include"tree_config.h"

// https://youtu.be/EWrSxJ7-Rdc

bool is_bst ( vector < int> preorder , int n )
{

     int root = INT_MIN;

     stack < int > st ;

     for ( int i = 0 ;  i < n ; i ++ )
     {

          int new_element = preorder [ i ] ;


          if( new_element < root )
          {
               return false;
          }

          while ( !st.empty()  and st.top() < new_element )
          {

               root = st.top ();

               st.pop();

          }


          st.push ( new_element ) ;

     }

     return true;


}

int main () 
{

     // NOTES AVAILABLE

     vector < int > preorder = { 7 , 2 , 4 , 3 , 19 };

     if ( is_bst ( preorder , 5 ))
          cout <<" PREORDE IS A VALID BST";
     else
          cout <<" PREORDER IS NOT A VALID BST " ;

     return 0 ;

}