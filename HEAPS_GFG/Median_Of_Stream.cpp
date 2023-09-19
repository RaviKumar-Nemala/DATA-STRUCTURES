#include<bits/stdc++.h>
using namespace std ;

class Solution 
{
     public : 


     void median_of_stream ( int arr[] , int n ) 
     {
          priority_queue < int >max_heap ; 
          
          priority_queue < int , vector <int >  , greater < int> >  min_heap;
          
          max_heap.push ( arr [0 ]) ;

          cout <<max_heap.top()<< endl;
          
          for ( int idx  = 1 ; idx  < n ; idx ++)
          {
               int curr_val = arr [ idx ] ; 

               int top_val   =max_heap.top () ;
          
               if (max_heap.size () >  min_heap.size ())
               {
                    if ( curr_val < top_val)
                    {
                    max_heap.push ( curr_val);
                         min_heap.push (max_heap.top());
                    max_heap.pop();
                    }
                    else 
                    {
                         min_heap.push ( curr_val);
                    }

                    cout << (min_heap.top() +max_heap.top () )/2.0 << endl;
               }
               else 
               {
                    if (  curr_val < top_val)
                    {
                    max_heap.push( curr_val);
                    }
                    else{
                         min_heap.push ( curr_val);
                         int temp = min_heap.top () ;
                         min_heap.pop();
                    max_heap.push ( temp);
                    }
                    cout <<max_heap.top () << endl;
               }

          }


     };




};



int main () 
{    
     int arr[] = {  12 ,15,10,5,8,7,16};

     Solution obj;

     obj.median_of_stream( arr , 7);


     return 0;
}