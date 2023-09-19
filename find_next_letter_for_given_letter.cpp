#include"tree_config.h"

char find_next_letter( vector < char  > arr , int low , int high , char target )
{
     //if we can't find the floor for the given element then -1 will be returned

     int res = -1 ;

     while ( low <= high )
     {

          int mid = ( low + high ) / 2;

          char curr_letter  = arr  [ mid ];

          //if target == curr_letter but we need to look for the next greater element from the target element 
          // so it will be exactly on the next idx from the target idx 
          // if our target element is at last idx next idx from the last idx will be over flowed
          // ( mid+1 )<= high will helpful to remove the over flow
          
          // ensure the  target element should not be the last element in the array

          if( curr_letter == target  and mid + 1 <= high )
          {
               res = mid  + 1 ;
              
               break;
          }
          // if we found the element which is greter than the target then store its idx in the res varaible
          else if ( curr_letter > target )
          {

               res = mid;

               cout << res << endl; 

               high = mid -1;

          }
          else
          {
               low = mid + 1 ;
          }

     }
     
   
     return res ;
     

}


int main () 
{


vector < char > arr = {  'a' , 'b' ,'c' , 'e' , 'f'};

char target = 'f';

int res =  find_next_letter ( arr, 0 , arr.size() -1 , target ) ;

// if there is no next greter element found in the array then this case will be helpful
if ( res == -1)
{
      cout<<" NEXT GREATER ELEMENT IS NOT FOUND :"<< endl;
}
else
{
  
  cout <<"NEXT GREATER ELEMENT : "<< arr [ res ] << endl;   

}

     return  0 ;

}