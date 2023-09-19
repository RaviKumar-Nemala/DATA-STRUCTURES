#include<iostream>
using namespace std;

class LCS{
     public:
     int longest_common_subsequence(string a,string b){
          int n1=a.length();
          int n2=b.length();
          int result=util_lcs(a,b,n1,n2);
          return result;
     }
private:
     int util_lcs(string str1,string str2,int n1,int  n2){
          if(n1==0||n2==0){
               return 0;
          }     
          if(str1[n1-1]==str2[n2-1]){
               return util_lcs(str1,str2,n1-1,n2-1)+1;
          }
          else{
               return max(util_lcs(str1,str2,n1-1,n2),util_lcs(str1,str2,n1,n2-1));
          }
      }
};
int main(){
     string a="abcdef";
     string b="abdefik"; //lcs=abdef len=5//
     LCS obj;
 cout<<obj.longest_common_subsequence(a,b);
}