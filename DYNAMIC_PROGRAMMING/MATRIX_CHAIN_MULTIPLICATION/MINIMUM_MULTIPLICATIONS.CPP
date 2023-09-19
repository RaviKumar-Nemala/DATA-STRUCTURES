#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class Solution{
     public:
     int Minimum_Multiplications(vector<int> &matrix){
          int i,j,k;
          int sum=INT_MIN;
          int temp=INT_MIN;
          return  Minimum_Multi_Util(1,matrix.size()-1,matrix);
     }
          private:
          int Minimum_Multi_Util(int i,int j,vector<int>&matrix){
               if(i>=j){
                    return 0;
               }
          int minimum=INT_MAX;
          int temp;
          for(int k=i;k<=j-1;k++){
                temp=Minimum_Multi_Util(i,k,matrix)+Minimum_Multi_Util(k+1,j,matrix)+matrix[i-1]*matrix[k]*matrix[j];
               if(temp<minimum){
                    minimum=temp;
               }
          }
          return minimum;
     }
};


int main(){
     //vector<int>matrix={40,20,30,10,30};
     vector<int>matrix={1, 2, 3, 4, 3};
     Solution obj;
    cout<<obj.Minimum_Multiplications(matrix);
}