#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution{
     public:

     int max(int a, int b){
          return (a>b) ? a : b;
     }
          int Egg_Drop(int no_of_eggs, int no_of_floors){
               if(no_of_floors==0||no_of_floors==1)
               return no_of_floors;

               if(no_of_eggs==1)
               return no_of_floors;
               
               int res;
               int min=INT_MAX;
               int x;
               for( x=1;x<=no_of_floors;x++){
                    res = max(Egg_Drop(no_of_eggs-1 , x-1) , Egg_Drop(no_of_eggs , no_of_floors-x) );
                    if(res < min)
                    min=res;

               }
               return min+1;
          }
};

int main(){
     Solution obj;
     int no_of_eggs=2;
     int no_of_floors=7;
     cout<<obj.Egg_Drop(no_of_eggs , no_of_floors);
}