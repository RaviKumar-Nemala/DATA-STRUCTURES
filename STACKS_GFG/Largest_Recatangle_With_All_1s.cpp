#include<bits/stdc++.h>
using namespace std ;


int largest_area_histo ( vector < int > arr  )
{
     stack < int > st ;
     int n = arr.size();
     
     int max_val = INT_MIN;
     for ( int idx = 0 ; idx < n ;idx ++ ) 
     {
          int curr_val = arr [ idx ] ; 

          while ( !st.empty() and arr[ st.top() ] >= curr_val )
          {
               int top_idx = st.top ();
               st.pop ();
               int histo_len = arr[ top_idx ] *( st.empty() ? idx : ( idx -  st.top () -1 ));
               max_val = max( max_val , histo_len);
          }
          st.push( idx ) ;
     }

     while ( !st.empty() )
     {
          int top_idx = st.top() ;
          st.pop();
          int histo_len = arr[top_idx]  * ( st.empty() ? n : ( n - st.top () -1 ));
          max_val = max( max_val , histo_len ) ; 
     }

     return max_val;
}

int max_rectangle_len ( vector < vector < int > >  vals  ) 
{
     int max_len = INT_MIN;

     max_len = largest_area_histo( vals[0]) ; 

     for( int idx= 1 ; idx  < vals.size () ; idx ++)
     {
          
          for ( int col = 0 ; col < vals[idx].size () ;  col ++ ) 
          {
               if ( vals [ idx ] [ col]  != 0 )
               {
                    vals [ idx][col] += vals [ idx-1][col];
               }
          }

          max_len = max( max_len , largest_area_histo( vals [ idx ]  ) ); 
     }

     cout<< "MAX LENGTH OF ONES = "<< max_len<< endl;
}

int main ()
{ 
 
 vector<vector < int > >  vals =  {{ 0 , 1, 1 , 0 } ,
                                   { 1 , 1, 1 , 1 } , 
                                   { 1 , 1, 1 , 1  } ,
                                   { 1 , 1, 0,  0 } };

     //in the above rectange we need to find the largest rectangle which contins all the ones
     //output = 8 ( from row = 1 or row = 2 ) ; 
     
     //APPROACH FOR EACH ROW TRY TO ADD THE UPPER ROW VALUES THEN FINDOUT THE MAX HISTO LENGH
     // for row =1  arr [ 1] [ 0] +=  arr [0][0]
     // for row =1    {  0 , 1 , 1 , 0 }
      //              {  1 , 1 , 1 , 1 } 
     // after adding = { 1  , 2 , 2 , 1 } pass this result to the histo get the max_hist len

     // for row = 2  try to add the values of the row =1 
     // if the element is zero don't add the above element value simply ignore the element 
max_rectangle_len( vals ) ; 

     return 0 ; 
}