#include"tree_config.h"

bool isValid ( vector < int > arr , int n , int max_limit ,  int students_limit )
{

     int no_of_students = 1;

     int sum = 0;

     for ( int idx = 0 ; idx < n ; idx ++ )
     {

          int current_ele = arr [ idx ];

          sum += current_ele ;

          if ( sum > max_limit )
          {
               
               no_of_students ++;
               //no sum will store no_of_pages where the next student  can read
               sum =  current_ele ;

          }

     }
     if ( no_of_students > students_limit )
          return false ;
     else
          return true;

}

int find_sum ( vector< int >&arr )
{
     int sum = 0;

     for ( auto it: arr )
          sum += it ;
     return sum ;
}

int maximaized_min_value_of_pages  ( vector < int > arr  , int student_limit )
{

int low = 0;

int  n =  arr.size() ;

int high = find_sum ( arr ) ;

int res  = -1 ;

while ( low <= high )
{


int mid_val = low + ( high - low )/2;


if ( isValid ( arr, n , mid_val , student_limit ) )
{
     
     res =  mid_val;

     high = mid_val - 1 ;

}
else
{
     
     low = mid_val + 1 ;

}

}


return res;

}

int main ()
{


     vector< int> arr = { 10 , 20, 30, 40,50};

     int student_limit =  2 ;

     cout <<" maximized min_pages  :"<< maximaized_min_value_of_pages( arr ,student_limit  );

     return 0;

}