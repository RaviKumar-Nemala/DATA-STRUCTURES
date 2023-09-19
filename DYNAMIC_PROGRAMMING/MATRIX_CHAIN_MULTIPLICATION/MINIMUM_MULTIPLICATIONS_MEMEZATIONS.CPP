#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int dp[100][100]={0};

class Solution{

     public:
     
     int Matrix_Multiplication_Memozation(vector<int>&matrix){
          
          return Min_Multiplication_Util(1, matrix.size()-1 , matrix);
          
     }

     private:

     int Min_Multiplication_Util(int i, int j , vector< int > &matrix){
          if(i>=j){
               return 0;
          }

          if( dp[i][j] != 0)
          {
               return dp[i][j];
          }

          int minimum=INT_MAX;
          int temp;
          for(int k=i;k<=j-1;k++){
               temp=Min_Multiplication_Util(i,k,matrix)+Min_Multiplication_Util(k+1,j,matrix) + matrix[i-1]*matrix[k]*matrix[j];
               if(minimum>temp)
               minimum=temp;
          }
          return dp[i][j]=minimum;
     }

};


int main(){
     //vector<int>matrix={40,20,30,10,30};
     vector<int>matrix={1, 2, 3, 4, 3};
     Solution obj;
     cout<<obj.Matrix_Multiplication_Memozation(matrix);
}