#include<bits/stdc++.h>
using namespace std ;


// works for the +ve values only 
// finding the min val in the stack in O(1) witht O(1) space
class My_Stack 
{
     public: 
     vector<int> st;
     int  min_val  = INT_MAX;
     void push( int data )    
     {
          if ( is_empty() )
          {
               min_val = data ;
               st.push_back( data);
               return;
          }
          //if the new added element is lesser then the min val 
          if ( data <= min_val)
          {
               int new_min = data;
              data= data - min_val; // new_val becomes negative by the time of popping elelemt if we encounter elment with the negative element then we say it is the min val
               min_val = new_min; //updating the min value
          }
          st.push_back( data);

     }

     int get_min_val  () 
     {
          return min_val;
     }
     bool is_empty()
     {
          if ( st.size () == 0 )   return true ;
          return false;
     }

     void pop () 
     {
          if ( is_empty ())
               return; 
          
          int top_val = st[ st.size () -1 ] ; 

          if( top_val <= 0 ) //this condition occurs when the top value is the minimum among all the values in the stack
          {
               int next_min = min_val - top_val; // this formula gives the next min val in the stack

               min_val  = next_min;
          }
          st.pop_back();
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