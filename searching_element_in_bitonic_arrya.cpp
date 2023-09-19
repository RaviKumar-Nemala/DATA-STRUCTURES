#include"tree_config.h"

int find_peak_idx ( vector<int > arr  )
{

     int low = 0 ;

     int high = arr.size() -1;

     int n  = arr.size() - 1 ;

     int ans_idx = -1;

     while( low <= high )
     {

          int mid_idx =  ( low + ( high - low )/2 ) ;

          int mid_val = arr[  mid_idx ] ;

          if ( mid_idx > 0 and mid_idx < n -1 )
          {
               if ( mid_val > arr [ mid_idx + 1 ] and mid_val > arr [ mid_idx -1 ] )
               {
               
                    ans_idx = mid_idx ;
                
                    break;
               
               }

               if( mid_val < arr [ mid_idx + 1 ] )
               {
                    low = mid_idx + 1;
               }
               else
               {
                    high = mid_idx - 1 ;
               }
          }

          else if ( mid_idx == 0 )
          {
               if ( mid_val > arr [ mid_idx + 1 ] ) 
               {
               
                    ans_idx  = mid_idx;
               
                    break;
               }
               else
               {
               
                    ans_idx = mid_idx+1 ;
               
                    break;
               }
          }
          else if ( mid_idx == n -1 )
          {
               if ( mid_val > arr [ mid_idx - 1 ] )
               {

                    ans_idx = mid_idx ;

                    break;

               }
               else
               {
                    ans_idx = mid_idx - 1;

                    break;
               }
          }

          else if (  mid_val < arr [ mid_idx - 1 ] )
          {
               low = mid_idx + 1;

          }
          else
          {
               high = mid_idx -1 ;
          }
     }

     return ans_idx;
     

}

int _dsc_binary_search ( vector < int > arr , int key , int low ,int high )
{

     

     int ans_idx = -1;
     while ( low <= high )
     {

          int mid_idx = ( low + ( high - low ) /2 ) ;

          int mid_val = arr [ mid_idx ] ;

          if ( mid_val == key )
          {
          
               ans_idx = mid_idx ;

               break;
          
          }
          else if ( mid_val > key )
          {
               low = mid_idx + 1;
          }
          else
          {
               high = mid_idx - 1;
          }

     }

     return ans_idx;

}

int _asc_find_key ( vector < int > arr ,int key  , int low ,int high)
{
     
          int ans = -1;

          while( low <= high )
          {

               int mid_idx = ( low + ( high - low ) / 2 ) ;

               int mid_val = arr [ mid_idx ] ;

               if( mid_val == key )
                    {
                         ans  = mid_idx;
                         break;
                    }
               else if( mid_val > key )
               {
                    high  = mid_idx - 1 ;
               }
               else
               {
                    low = mid_idx+ 1 ;
               }

          }

          return ans;

}

int find_idx ( vector < int > arr , int key )
{

     int peak_idx = find_peak_idx ( arr );

     int ans_idx = _asc_find_key ( arr , key , 0 , peak_idx -1 ) ;

     if ( ans_idx != -1 )
     {
          return ans_idx;
     }
     else
     {
          return _dsc_binary_search ( arr , key ,peak_idx , arr.size() -1 ) ;
     }

}

int main () 
{

vector  < int >arr = { 1 , 13 ,15 ,16 , 18 , 7 , 6 ,5 ,4 };

// bitonci array :gradually increasing and then gradually decreasing

int key = 7 ;

int key_idx  = find_idx(  arr , key ) ;

if ( key_idx != -1 )
{
     cout <<" ELEMENT INDEX = "<< key_idx << endl;
}
else
     cout << "ELEMENT INDEX IS NOT FOUND"<< endl;

return 0 ;

}