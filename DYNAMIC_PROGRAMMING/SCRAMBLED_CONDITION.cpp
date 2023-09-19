#include<iostream>
using namespace std;

class Solution{
     
     public:
          
          bool Scramble(string a,string b){
               return Scramble_util(a,b);
          } 
     
     private:

          bool Scramble_util(string a,string b){

               if(a.compare(b)==0) //IT BOTH STRING ARE EQUAL THEN NO NEED TO SCRAMBLE THOSE STRINGS
               return true;

               if(a.length()!=b.length()) //IF THE GIVEN STRINGS LENGTHS ARE NOT EQUAL THEN SCRAMBLING IS NOT POSSIBLE//
               return false;

               if(a.length()<=1) //IF ONE STRING LENGTH IS BECOMES EMPTY THEN THIS CASE IS HELPFUL//
               return false;
          
               bool flag= false;
               int n=a.length();
               
               for(int i=1;i<=n-1;i++){
                    bool case_1,case_2;

          //HERE CASE 1 IS USED TO FIND THE RESULT IF WE SWAP THE CHILD NODES OF THE NON LEAF NODES//
          //CASE 2 IS USED IF WE DO NOT SWAP THE LEAF NODES//
          //IF ANY OF THE CASE IS GETS TRUE THAT MEANS THERE IS A SCRAMBLING ISPOSSIBLE//
          //ONCE WE FIND THE TRUE VALUE WE SIMPLY BREAK THE LOOP THEN RETURN TRUE NO NEED TO CHECK THE  SUBPARTS AGAIN.//

               if ( Scramble_util( a.substr(0,i) , b.substr(n-i,i) ) && Scramble_util( a.substr(i,n-i), b.substr(0,i) ) )
                case_1=true;
               else
                    case_1=false;     
               
               
               if ( Scramble_util( a.substr(0,i) , b.substr(0,i) ) && Scramble_util( a.substr(i,n-i) , b.substr(i,n-i) ) )
               case_2=true;
               else
               case_2=false;

                    if(case_1||case_2){
                         return true;
                         break;
                    }

                    } 
               return false;

          }
};

int main(){
     Solution obj;
     string a="great";
     string b="rgeat";
   a=   "ACTOR"; 
   b= "CATOR";

     cout<<obj.Scramble(a,b);
}