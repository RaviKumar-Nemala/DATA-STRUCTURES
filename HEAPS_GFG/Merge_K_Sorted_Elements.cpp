#include<bits/stdc++.h>
using namespace std ;

class config 
{
     public:

     int value;
     int ele_idx;
     int ele_arr_idx;
     
     config( int value , int ele_idx ,int  ele_arr_idx )
     {
          this->value =  value;
          this->ele_idx = ele_idx;
          this->ele_arr_idx = ele_arr_idx;
     }
     config ( ) 
     {

     }
     
};

class my_comp
{
     public:
     bool operator() (  config obj_1  , config obj_2)
     {
          return ( obj_1.value > obj_2.value ) ;
     }

};

class Solution 
{    

     private :  

     vector < vector <  int > >  my_arr ; 
      
     config get_next_val( int arr_idx , int next_ele_idx) 
     {    
          
          config next_obj ;

          int size =  this->my_arr[ arr_idx ].size();

          if ( next_ele_idx  >=  size ) 
          {
               next_obj.ele_idx = -1 ;
               return next_obj;
          }

          vector < int>  target_arr = this -> my_arr [ arr_idx ] ; 

          int next_val =    target_arr [ next_ele_idx  ] ; 

          int curr_arr_idx = arr_idx ; 

          next_obj.value =  next_val;

          next_obj.ele_arr_idx =  curr_arr_idx ; 

          next_obj.ele_idx =  next_ele_idx ; 

          return next_obj;
     }

     public:

     void merge_k_sorted ( vector<vector<int>>arr  )
     {
          this  -> my_arr = arr;

          vector < int > res ; 

          int idx = 0 ; 

          priority_queue < config , vector < config >  , my_comp> min_heap;  

          for( idx = 0 ; idx <  arr.size () ;idx ++)
          {
               config obj;    

               obj.value =  arr [ idx ][0];
               obj.ele_idx = 0 ;
               obj.ele_arr_idx = idx;

               min_heap.push( obj);
          }    

          while ( !min_heap.empty())
          {
               config top_element = min_heap.top() ; 
              
               min_heap.pop();
               
               int top_ele_value = top_element.value ;

               int top_ele_arr_idx = top_element.ele_arr_idx ; 

               int top_ele_idx = top_element.ele_idx  ; 

               res.push_back ( top_ele_value ) ; 

               config next_obj   = get_next_val(top_ele_arr_idx ,  top_ele_idx + 1 );

                    if ( next_obj.ele_idx != -1)
               {
                    min_heap.push ( next_obj);
               }

          }


          for ( auto it : res ) 
          {
               cout << it <<" " ; 
          }

          cout<< endl;
     }

};

int main () 
{
      
     config  obj (1 ,2,3);

     vector<vector <int > >  arr = {  { 1,2,3}  , { 7 ,8,9} ,  { 4 ,5,6 }};

     Solution  solution; 

     solution.merge_k_sorted( arr ) ;

     return 0;
}