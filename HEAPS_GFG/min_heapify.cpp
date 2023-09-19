#include<bits/stdc++.h>
using namespace std;

class Min_heap  
{
     private :

     int *arr ;
     int size ;
     int capacity ;

     public:
     Min_heap ( int capacity )
     {
          size = 0 ;

          arr = new int [ capacity ];

     }

     void display ()
     {
          for ( int i = 0 ;i < size ;i ++ )
          {
               cout << arr [ i ] <<" " ; 
          }
          cout << endl;
     }

     int parent( int idx )
     {
          return ( idx -1 )/2;
     }
     void insert(  int value ) 
     {
          if ( size == capacity ) 
          {
               cout<<"HEAP IS FULL";
               return ;
          }
          size ++;
          
          arr [ size -1 ] =  value ;

          for ( int idx = size -1 ; idx !=0 and  arr[ parent(idx)] > arr[idx] ; )
          {
               int parent_idx = parent( idx ) ; 

               swap ( arr [ parent_idx ] , arr [ idx ] );

               idx = parent_idx;
          }

          return;
     }

     void decrease_key ( int idx_val , int replace_val)
     {
          arr [ idx_val ] = replace_val;

          while( idx_val != 0 and  arr [ parent( idx_val )] < arr[ idx_val]) 
          {
               swap( arr [ idx_val ] , arr [ parent(idx_val)]);

               idx_val =  parent ( idx_val);
          }

          return;
     }
     //replace the element withe some least element
     // then that least element will be the top of the heap
     // then call the extract min then it will removes that least element and restructure the heap again
     void delete_element( int idx_val )
     {
          decrease_key ( idx_val  , INT_MAX);

          extract_min ( );    
     }

     //removes the min value and restructure the heap by calling the min_heapify function
     int extract_min( )
     {
          swap( arr [ 0 ]  , arr [ size -1 ] ) ;
          
          size --;  

          min_heapify( 0 );

          return arr [ size ];

     }

     void min_heapify( int idx )
     {
          int left_idx = 2*idx + 1 ;

          int right_idx = 2 *idx + 2 ;

          int current_val =  arr [ idx ] ;

          int min_idx = idx ;

          if ( left_idx and  arr [ left_idx ] < current_val )
          {
               min_idx =  left_idx;
          }
          if ( right_idx and arr [ right_idx] < current_val)
          { 
               min_idx = right_idx;
          }

          if ( min_idx != idx ) 
          {
               swap( arr [ min_idx ] ,  arr [ idx ])  ;
               min_heapify( min_idx);
          }
     }

};

int main ()
{
     Min_heap obj( 6 ) ;

     int arr[] = { 1 ,3 ,5, 2 ,4 } ;

     for ( int i = 0 ;i  < 5 ;i ++ )
     {
          obj.insert( arr[ i ] ) ; 
     }

     obj.delete_element( 1);//after insert function array structure is going to be chaned so 1 refers to the different element not  the elemnent on our local array

     obj.display();


}


