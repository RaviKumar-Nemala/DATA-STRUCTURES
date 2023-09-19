#include<iostream>
using namespace std;
#include<bits/stdc++.h>
    
class Solution{
     private :
          bool is_present_in_dict(string word  )
          {
               string dict [] = { "pep" , "coding" , "pepcoding" , "ice" , "cream" , "man" , "go" , "mango" , "loves" };
               int i;
               int size =  sizeof(dict) / sizeof(dict[0]);

              for ( i = 0  ; i<size ; i ++)
              {
                   if(dict[i].compare(word) == 0)
                   return true;
              }
              return false;
          }

     public: 

          bool is_match(string s)
     {
          if(s.length() == 0)
          return true;
          if(s.length() ==1 )
          return is_present_in_dict(s);
          int n = s.length();
          bool dp[n+1];
          memset(dp , false , sizeof(dp));
          for(int  i = 0  ; i <= n ; i++ )
          {
               if(dp[i] == false and  is_present_in_dict(s.substr(0,i)))
               dp[i] =  true;

               if(dp[i] == true)
          {
               if( i== n )
               return true;
               
               for (int j = i+1 ; j<=n ; j++)
               {
                    if(dp[j]==false and is_present_in_dict(s.substr(i, j-i)))
                    dp[j] = true;
                    if(j ==  n  and dp[j] == true)
                    return true;
               }
          }
          }
          return false;
     }
};

int main(){
     string s = "pepcodinglovesicemango";
     Solution obj;
     cout<<obj.is_match(s);
}