#include"tree_config.h"




int get_last_occurence ( vector < int>nodes , int target , int low ,int end )
{

     int res = 0 ;

     while ( low <= end )
     {

          int mid_idx = (low + end) /2;

         // cout << "MID IDX " <<mid_idx<< endl;

          int curr_ele = nodes [ mid_idx ] ;

          if ( curr_ele == target  )
          {


               //cout <<" df"<< mid_idx << endl;

               res =  mid_idx ;


               low  = mid_idx + 1 ;// for finding the  last occurence
               
          }
          
          else if( curr_ele < target)
          {

               low = mid_idx + 1 ;

          }
          else{

               end = mid_idx - 1 ;

          }    
          
     }

     return res ; // it returns the last occurence  idx of the  target elemet

}



int get_first_occurence ( vector < int>nodes , int target , int low ,int end )
{

     int res = 0 ;

     while ( low <= end )
     {

          int mid_idx = ( low + end )/2;

          int curr_ele = nodes [ mid_idx ] ;
          cout <<" MID_IDX "<< mid_idx << endl;
          if ( curr_ele == target  )
          {

               res =  mid_idx ;

               end = mid_idx - 1 ;//for finding the first occurence

              
          }
          
          else if( curr_ele < target)
          {

               low = mid_idx + 1 ;

          }
          else{

               end = mid_idx - 1 ;

          }    
          
     }

     return res ;// it returns the first occurence  idx of the  target elemet

}
int main (){


vector< int >  arr = { 1, 2 , 3  , 4  ,  4, 4 , 4 , 5,  6 } ;

int target = 4 ;

int low = 0 ;

int high = arr.size() - 1 ;

int first_occurence_idx = get_first_occurence ( arr , target , low ,high );

int last_occurence_idx = get_last_occurence ( arr, target , low , high );
cout<< " fid "<< last_occurence_idx << endl ;

cout <<"FIRST OCCURENCE : " << first_occurence_idx << endl ;


cout <<" LAST OCCURENCE :"<<last_occurence_idx << endl ;

int frequency = last_occurence_idx - first_occurence_idx  + 1 ;

cout <<" frequency of the "<< target << "  " << frequency << endl;

return 0 ;

}