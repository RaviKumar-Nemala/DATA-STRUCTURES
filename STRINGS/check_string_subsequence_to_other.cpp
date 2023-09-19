#include<bits/stdc++.h>
using namespace std ;

void is_subsequence_optimal( string main_str, string target_str )
{
     int i , j; 

     i = 0 , j = 0 ;

     for(  i =  0 , j =0 ;  i < main_str.length() and j < target_str.length()  ;i ++)
     {
          if ( main_str [ i ]  == target_str [ j ] ) 
          {
               j ++;
          }    
     }

     if( j == target_str.size () ) 
     {
          cout << "SUBSEQUENE IS FOND"<< endl;
     }
     else 
     {
          cout<< "SUBSEQUENCE IS NOT FOUND"<< endl;
     }
}

void is_subsequence ( string main_str,  string target_str )
{    
     string temp = "";

     for( char ch : main_str)
     {
          if( target_str.find(ch) != target_str.npos)
          {
               temp += ch;
          }
     }

     if( temp.find( target_str ) != temp.npos) 
     {
          cout <<"SEQUENCE IS FOUND"<< endl;
     }
     else 
     {
          cout << "SEQUENCE IS NOT FOUND"<< endl;
     }

}

int main()
{
     string str = "ABCDE";

     string str2 = "AE";

     // is_subsequence( str , str2 ) ; 

     is_subsequence_optimal( str  ,str2) ;

     return  0;
}