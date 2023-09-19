#include<bits/stdc++.h>
using namespace std;

bool is_valid( int pages[] , int max_students , int n , int max_pages)
{
     int sum = 0;
     int no_of_students = 1 ;

     for( int idx =0 ;idx< n ;idx++)
     {
          sum += pages [ idx ] ;
          if ( sum > max_pages)
          {
               sum = pages [idx ] ;
               no_of_students ++;
          }
     }
     
     if ( no_of_students > max_students )
               return false; 
     else
     return true;
}

int find_sum ( int pages[] , int n )
{
     int sum = 0;
     for ( int idx = 0 ;idx <n ; idx ++)
          {    
               sum+=pages [ idx ];
          }
          return sum;
}

int book_allocation ( int pages[] , int max_students ,  int n )
{
     int low =0 ;
     int high = find_sum ( pages , n );
     cout << high << endl;
     int res = -1;

     while ( low <= high)
     {
          int mid_val = ( low + high )/2;
          if (is_valid(pages,max_students,n,mid_val))
          {
               res = mid_val;
               high =mid_val -1 ;
          }
          else 
          {
               low = mid_val + 1;
          }
     }

     return res;

}


int main ()
{
     int arr[] = {10,20,30,40};
     int no_of_students= 2 ;
     cout<<book_allocation(arr,no_of_students,4);
     
     return 0;
}