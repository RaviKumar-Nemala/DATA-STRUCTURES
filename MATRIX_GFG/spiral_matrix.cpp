#include<bits/stdc++.h>
using namespace std ;


void spiral ( vector<vector< int > >  arr )
{
     int row_size = arr.size() ;
     int col_size = arr[ 0 ] .size () ;


     int top = 0 ; 
     int right = col_size - 1 ;
     int left = 0;
     int bottom = col_size - 1; 

     int i  ;

     while ( top <= bottom and left <= right )
     {
          for ( i = top ; i <= right ; i ++)
          {
               cout << arr [top ] [ i ]  << " " ;
          }     
          top ++;
          for ( i = top ; i <= bottom ; i ++ )
          {
               cout << arr [ i ] [ right ] << " " ;
          }
          right --;
          // cout <<"left = " << left << endl; 
          // cout << "bottom = " << bottom << endl;
          if ( top <= bottom ){
          for( i = right ; i>= left ; i --)
          {
               cout << arr [ bottom ] [ i ] << " " ;
          }
          bottom --;
          }
          if ( left <= right ){
          for(  i = bottom ; i >= top ; i -- )
          {
               cout << arr  [ i ] [ left ] <<  "  " ;
          }
          left ++;
          }
     }

}

int main ()
{    
         
     int row_size = 4 ,  col_size = 4;
     
     int i , j; 
     
     vector< vector< int > > arr  ;

     for( i = 0 ; i <  row_size ; i ++ )
     {
          vector< int > temp ; 
          for ( j = 0 ; j < col_size ; j ++ )
          {
               int ele ; 
               cin >> ele ;
               temp.push_back ( ele ) ;  
          } 
          arr.push_back ( temp ) ;
     }

     spiral( arr ) ; 

     return  0 ; 
}