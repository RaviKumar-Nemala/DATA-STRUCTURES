#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{
     public:
     
          int  boolean_paranthesization(string s){
               
               int first_index=0;
               int last_index=s.length()-1;
               bool is_true=true;
              return no_of_ways_paranthesize(first_index,last_index,s,is_true);
          }

     private:
          int no_of_ways_paranthesize(int i , int j , string s,bool is_true){
               if(i>j)
                    return 0;
               
               if(i==j)
               {
                    if(is_true){
                         return s[i]=='T';
                    }
                    else{
                         return s[i]=='F';
                    }
               }
                          int ans=0;
               for(int k=i+1; k<=j-1; k+=2)//K IS ALWAYS POINTS TO THE OPERATOR THERE IS A OPERATOR IN BETWEEN TWO VARIABLES IN  ORDER TO POINT OUT K EVERY TIME TO AN OPERATOR IT NEEDS TO INCREMENTED BY 2//
               {
                   
                    int left_true=no_of_ways_paranthesize(i,k-1,s,true);
                    int right_true=no_of_ways_paranthesize(k+1,j,s,true);
                    int left_false=no_of_ways_paranthesize(i,k-1,s,false);
                    int right_false=no_of_ways_paranthesize(k+1,j,s,false);
               
               if(s[k]=='|'){
                    if(is_true){
                    ans+=(left_true*right_true)+(left_true*right_false)+(left_false*right_true);
                    }
                    else
                    {
                         ans+=(left_false*right_false);
                    }
               }
               else if(s[k]=='&'){
                    if(is_true){
                         ans+=(left_true*right_true);
                    }
                    else{
                         ans+=(left_true*right_false)+(left_false*right_true)+(left_false*right_false);
                    }
               }

               else if(s[k]=='^'){
                    if(is_true){
                         ans+=(left_true*right_false)+(left_false*right_true);
                    }
                    else{
                         ans+=(left_false*right_false)+(left_true*right_true);
                    }
               }

               }
          return ans;
          }
};


int main(){
     string s="T|F^F&T";
     s="T|T&F^T";
     // There are 4 ways
	// ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
	// (T|((T&F)^T))
     Solution obj;
     cout<<obj.boolean_paranthesization(s);
}