#include<bits/stdc++.h>
using namespace std ;

void reverse( vector <int > &arr  )
{
     int low = 0 ;
     int high = arr.size () -1;
     while ( low <= high)
     {
          swap ( arr [ low ] ,  arr[ high]);
          low ++;
          high --;
     }
     return;
}

int main()
{

     vector< int > arr = { 5,20,12,20};

     // reverse( arr.begin ( ) , arr.end());

     reverse( arr  ) ;

     for (auto it : arr) cout << it <<" " ; 

     return 0;
}