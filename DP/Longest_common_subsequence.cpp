#include"config.h"


class Solution 
{
public:

int solve ( string s1 , string s2, int s1_len , int s2_len )
{

if ( s1_len == 0 || s2_len == 0 )
     return 0 ;

if ( s1 [ s1_len - 1 ] == s2 [ s2_len - 1 ] ) 
     {
          return 1 + solve ( s1 , s2 , s1_len - 1 , s2_len - 1 ) ;
     }

else 
{

    return  max ( solve ( s1 , s2 , s1_len - 1 , s2_len ) , solve ( s1 , s2 , s1_len , s2_len - 1 ) ) ;    

}

}

};

int main () 
{

string s1 = "abcdef";

string s2 = "abghkef";

Solution obj ;

cout << obj.solve(s1 , s2 , s1.size() , s2.size () ) <<endl;

}


