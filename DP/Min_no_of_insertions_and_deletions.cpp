#include"config.h"


class Solution 
{
public :

int lcs (  string s1 , string s2 , int s1_len , int s2_len ) 
{

     if  ( s1_len == 0 or s2_len == 0 )
          return 0 ;

     else if ( s1 [ s1_len ] == s2 [ s2_len ] )
     {
          
          return 1 + lcs ( s1 , s2 , s1_len - 1 , s2_len -1 ) ;

     }
     else 
     {
          
          return max ( lcs ( s1 , s2 , s1_len , s2_len - 1 )  , lcs ( s1 , s2 , s1_len-1  , s2_len ) );

     }

}

void solve ( string s1 , string s2 )
{


int lcs_len = lcs ( s1, s2 , s1.size() , s2.size() ) ;

int no_of_deletions = s1.size() -  lcs_len ;

int no_of_insertions = s2.size() - lcs_len ;

cout << "no of insertions : " <<  no_of_insertions << endl;

cout <<" NO OF DELETIONS  : " << no_of_deletions << endl;

return ;

}

};


int main () 
{

     string s1 = "abcd";

     string s2 = "cdf";

     Solution obj; 

     obj.solve (  s1 , s2 ) ;
     
}