#include<bits/stdc++.h>
using namespace std ;

void bucket_sort ( int arr [] , int  n  , int no_of_buckets ) 
{


     //need to move the elements into the apprioriate buckets
     // then sort the buckets the individually 
     //then combine all the buckets

     int max_val = INT_MIN;
     for ( int i = 0   ; i < n ; i ++ )
     {
          if(  arr [ i ] > max_val)     max_val = arr [ i ] ; 
     }
     
     cout << max_val << endl;

     //need to increment the max_value by one otherwise we get the index out of bound exception while storing the elements in the corresponding buckets
     max_val++;
     vector<int>buckets[no_of_buckets];

     for ( int idx = 0 ; idx < n ; idx ++ )
     {
          int bucket_idx = ( no_of_buckets * arr[ idx]  ) / max_val; // this formula gives the  index of the bucket where the element has to be stored

          buckets[bucket_idx].push_back ( arr [idx]) ; 
     }

     for  ( int i = 0 ; i < no_of_buckets ; i ++ )
     {
          if ( buckets[i].size () >=1 )
          sort( buckets[i].begin() , buckets[i].end());
     }

     for(  auto it : buckets )
     {
          for ( auto it_2 :  it )       
               cout <<  it_2 << " " ;
          cout << endl;
     }

     return;

}


int main ()
{
     
     int arr[] = { 30,40,10,80,45,12, 70};
     int n = 7;
     int no_of_buckets = 4; 
     bucket_sort( arr , n , no_of_buckets );

     return  0 ;
}