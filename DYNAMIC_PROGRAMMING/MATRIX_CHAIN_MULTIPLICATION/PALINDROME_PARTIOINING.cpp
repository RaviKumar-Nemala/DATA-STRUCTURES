#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution{
     
 public:

     int Palindrome_Partioning(string s){
          int i=0;
          int last_index=s.length()-1;
          return Min_Partions(0,last_index,s);
     }

    
 private:

     bool is_palindrome(int i, int j , string s){

               while(i < j){
                    if(s[i]==s[j]){
                         i++;
                         j--;
                    }
                    else{
                         return false;
                    }
                    
               }
               return true;
     }

      int Min_Partions(int i,int j,string &s){

           if(i>=j){
                return 0;
           }

          if(is_palindrome( i ,j , s)){
               return 0;
          }

          int minimum=INT_MAX;
          int temp;

     for(int k=i;k<=j-1;k++){
          temp=Min_Partions(i,k,s)+Min_Partions(k+1,j,s)+1;
          if(temp<minimum){
               minimum=temp;
          }
     }

     return minimum;

      }
};

int main(){
     //string s="nitin";
     string s="cbabd";
     s="ababbbabbababa";
     Solution obj;
     cout<<obj.Palindrome_Partioning(s);
}