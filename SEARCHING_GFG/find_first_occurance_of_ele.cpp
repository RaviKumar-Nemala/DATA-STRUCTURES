#include<bits/stdc++.h>
using namespace std;



int get_first_occurance( int *arr, int target , int  low , int high)
{
     int first_occurance = high + 1 ;

     while ( low <= high)
     {

          int  mid_idx  = ( low + high)/2;
          int mid_val = arr [ mid_idx];
          
          if ( mid_val == target )
          {
               if( mid_idx  < first_occurance )
                    first_occurance = mid_idx;
          }
          
          if ( mid_val >= target)
          {
               high = mid_idx -1;
          }
          else
          {
               low = mid_idx +1;
          }

     }

     return first_occurance;

}

int main()
{

     int arr[] = { 1 ,2 ,2 , 8 , 8 ,8 };
     int res = get_first_occurance( arr , 8 , 0 , 5);
     if( res != -1)
     {
          cout <<"PRINTING THE ELEMENT INDEX = " << res<<endl;
     }
     else 
     {
          cout<<"ELEMENT IS NOT FOUND"<<endl;
     }
     
     return 0;
}