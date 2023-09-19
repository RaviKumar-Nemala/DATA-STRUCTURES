#include<bits/stdc++.h>
using namespace std ;

bool is_valid_suffle ( string s1 , string s2  ,string suffle)
{
     int i , j , k ;
     i = 0 , j = 0  , k = 0 ; 
     int l1 = s1.size() , l2 = s2.size();
     if( suffle.length() != s1.length() + s2.length() )
          return false;
     
     while(  k < suffle.length())
     {
          char ch = suffle [ k ] ;
          if ( i < l1 and  ch == s1[ i ])    
               i++;
          else if ( j< l2 and ch == s1[j])
               j++ ;
          else
               return false;
     }     
     if(  i < l1 || j < l2 )   return false;
     return true;  

}


int main ()
{
     string s1 = "xy";
     string s2 ="12";
     string suffle="xy12";
}