#include "tree_config.h"


vector< int > find_idx ( vector< vector < int  > > nums , int key )
{

     int  row_idx = 0 ;

     int max_row_idx = nums.size () -1 ;

     int col_idx = nums.size() -1 ;

     int max_col_idx = nums.size() -1 ;

     vector< int > ans ;


     while( row_idx >=0 and row_idx <= max_row_idx and col_idx >=0  and col_idx<= max_col_idx )
     {


          int current_element   = nums [ row_idx] [ col_idx ];

          if ( current_element == key )
               {
                   

                    ans ={  row_idx , col_idx } ;
                    //cout << row_idx << endl;
                    //cout << col_idx << endl;

                    break;
               }
          else if( current_element > key )
          {
               col_idx --;
          }
          else if( current_element < key )
          {
               row_idx ++;
          }

     }

     return ans;


}

int main () 
{

vector < vector < int > > nums = { {  1 , 6 , 12 , 18 },

                                  { 5 , 7 , 13 , 24  } ,
                                   
                                   { 10 , 11 , 15 , 26 } ,
                              
                                    { 17, 18 ,  19 , 30 } } ;

int key = 19;

vector < int > ans = find_idx ( nums , key );


if( ans.size() == 0 )
{
     cout <<" ELEMENT IS NOT FOUND "<< endl;
}
else
{
     cout<< "ROW INDEX =  "<< ans [ 0 ]<< endl;

     cout<< " COLUMN INDEX = "<< ans [ 1 ]<< endl;

}

return 0 ;

}