#include<bits/stdc++.h>
using namespace std ;

class Solution
{

public:


     int  solve ( string s1 , string s2 , int n1 , int n2 )
     {

          if ( n1== 0 or n2 ==0 )
               return  0 ;
          
           if( s1 [ n1 -1 ] ==  s2 [ n2 -1 ] ) 
          {
               cout <<"found"<< endl; 
               return 1 + ( solve ( s1 , s2 ,n1-1 , n2-1 ) );
          }

          else
          {
               return max ( solve ( s1 , s2 , n1 , n2-1) , solve ( s1 , s2 , n1-1 , n2 ) ) ;
          }

     }



};



int main() 
{

string s1 = "abcdgef";

string s2 = "abcd";

Solution obj ;

 cout<<obj.solve(s1 , s2  , s1.size() , s2.size()  ) ;

     return  0 ; 
}