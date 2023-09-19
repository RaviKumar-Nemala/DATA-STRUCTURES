#include<bits/stdc++.h>
using namespace std ;

class My_Stack 
{
     public: 
     vector<int> st;
     vector<int> aux_st;
     void push( int data )    
     {
          st.push_back( data ) ;
          //we use the two stacks here inorder to get the min value in the O(1)time
          // the auxilary stack is used to store the min value
          // the top element of the auxilary is always holds the  min value among all the element in the main stack
          //if newly inserted element is smaller then the top element of the aux stack
          // then update the aux stack with the new element
          if( aux_st.size () == 0 or aux_st[ aux_st.size () -1 ] > data )
          {
               aux_st.push_back( data);
          }
     };

     int get_min_val  () 
     {
          return aux_st[ aux_st.size () -1 ] ; 
     }
     bool is_empty()
     {
          if ( st.size () ==0 ) return true ;

          return false; 
     }
     void pop () 
     {
          if ( is_empty () )  return;

          int curr_ele = st[ st.size() -1 ] ; 
          st.pop_back();
          // if the curr_ele is same as the top ele of the aux stack ( min_val ) then remove the curr_ele  from the aux_stack too 
          if( curr_ele == aux_st[ aux_st.size () -1 ] )
          {
               aux_st.pop_back();
          }
     }

     void print_val ()
     {
          for ( int idx = st.size() -1 ; idx >= 0 ; idx -- )
          {
               cout << st [ idx ] << " " ; 
          }
          cout << endl;
     }
};


int main ()
{
     My_Stack  st  ;
     
     st.push ( 5);

     st.push ( 10);

     st.push ( 20);

     st.push ( 2);

     st.push (6 );

     st.push ( 4);

     st.print_val ( ) ;

     cout << st.get_min_val()<< endl;

     st.pop();

     st.pop();

     st.pop();

     cout <<st.get_min_val()<<endl;

     return 0 ;     
}