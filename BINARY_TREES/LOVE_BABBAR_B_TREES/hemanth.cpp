#include<bits/stdc++.h>

using namespace std ;



int find_idx (  int   vec[]  , int n , int key_val )
{

  for ( int i = 0 ; i < n  ; i ++ )
  {

    if ( vec [ i ] ==  key_val )
    {
      return i ; 
      break ;
    }
  
  }

}
int main () 
{
  

    int n = 7 ; 

    int vec [ n  ] ;

    int k = 0 ;

    int a = 1 ; 

   for  ( int i = 0 ; i < n ; i ++ )
   {
     vec [ i ]   = a ; 
     a++; 
   }


  int mid = n / 2 ; 

  
  int key =  4;  


  int ele_idx  = find_idx ( vec  , n , key  ) ; 



  if ( ele_idx >= n ) 
  {
    cout << "KEY ELEMENT IS NOT FOUND  " ;

   return 0;
  }

  int temp = vec [ ele_idx ] ; 

  int temp_vec [ ] = { 0 } ;


if ( ele_idx  > mid ){

  

  int k = 0 ;

  for (  int i = mid ; i < ele_idx ; i++  )
  {

    int data = vec [ i ] ;

    temp_vec [ k++ ] =  data  ;
    
  }


  int  swap_val = key;



  for ( int k = 0  , i = mid ; i < ele_idx  ; i ++ ,  k ++)
  {

    vec [ i + 1 ]  = temp_vec [ k ] ; 


  }

  vec [ mid ] =  key ;

}

  else 
  {

    for ( int k = 0 , i = ele_idx+1 ; i <= mid ; i ++ )
    {
      
      int data = vec [ i ] ; 

      temp_vec [ k ++] =  data  ;

    }

    for ( int k = 0 ,  i = ele_idx ; i < mid ; i ++ , k ++ )
    {

      vec [ i ] =  temp_vec [ k ] ;

    }

    vec [ mid ] = key ;

  }

  for  (  auto it : vec )
  {

    cout << it << " " ; 

  }


}