#include<bits/stdc++.h>
using namespace std ;

class Two_Stacks 
{
     private :
     
     int *arr ;
     int cap ; 

     int last_idx_1 ;

     int last_idx_2 ; 
     
     int first_stack_max_size ; 
     public: 
     Two_Stacks ( int n )  {

          this  -> arr = new int[n];
          this -> cap = n ;   
          this ->last_idx_1  = -1 ;
          this-> last_idx_2 = -1;
          this -> first_stack_max_size  =  n/2 ;
     }

     bool is_empty_1( )
     {
          if ( last_idx_1 ==  -1 )
          {
               return true;
          }
          return false;
     }
     bool is_full_1()
     {
          if ( last_idx_1 == first_stack_max_size)
          {
               return true;
          }
          return false;
     }
     void push_1( int data)
     {    
          if( is_full_1())
          {
               cout <<"STACK OVER FLOW" << endl;
               return;
          }

               last_idx_1 ++;    
               this -> arr[ last_idx_1 ] = data;

     }
     
     bool is_full_2()
     {
          if( last_idx_2 == cap -1 ) return true;
          
          return false;
     }

     void push_2( int data)
     {

           if( is_full_2())
          {
               cout <<"STACK OVER FLOW" << endl;
               return;
          }
          if ( last_idx_2 == -1 ) last_idx_2 = cap/2 ;

               last_idx_2 ++;    
               this -> arr[ last_idx_2 ] = data;

     }

     void print_1()
     {
         int temp  = last_idx_1 ;  

         while ( temp >=0 )
         {
               cout << this->arr[ temp ]<< " " ; 
               temp --;
         }

     }

     void print_2()
     {    
          int temp = last_idx_2 ;

          while ( temp > ( cap/2))
          {
               cout <<  arr [ temp ] <<" " ; 
               temp --;
          }
          cout << endl;
     }

     void pop_1()
     {
          if ( is_empty_1() )
          {
               cout << "STACK IS EMPTY" << endl;
               return;
          }

          last_idx_1 --;
     }

     void pop_2()
     {
          if ( is_empty_2())
          {
               cout <<"STACK IS EMPTY" << endl;
               return ;
          }
          last_idx_2 --;
     }

     int  size_1()
     {
          
     }

     int size_2()
     {

     }

     bool is_empty_2()
     {
          if ( last_idx_2 <= cap/2)
          return true;
          return false;
     }
};




int main ()
{
     Two_Stacks  ts( 10 );

     ts.push_1 ( 1 ) ;

     ts.push_1 (  2 ) ; 
 
     ts.push_2 ( 3 ) ;

     ts.push_2 (  4 ) ;    

     ts.pop_1();

     ts.pop_2();

     ts.print_1() ;

     ts.print_2();

     return 0;
}