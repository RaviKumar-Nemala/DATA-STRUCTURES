#include<iostream>
using namespace std;
#include<deque>
#include<vector>
//here is a program whick is used to find the max of the element in a given range k///
//example if the arr consists of 1,2,3,4,5,6// if k=3
//then we need to find the max of first 1,2,3 elements then shift one positon thenfind max of 2,3,4 then shift onepositon thenfind max of 3,4,5 and so on and we need to store all of the max elements //
int main(){
     int n=6;
     vector<int>ans;//this vector is used to store the ans of max elements
     vector<int>arr(n);//this is used to giving theinput//
     deque<int>dq;//it is essential
     int k;
     cout<<"enter the k value: ";
     cin>>k;
     for(auto &i:arr){
          cin>>i;
     }
     for(int i=0;i<k;i++){//this loop will find the max of from 0 to kth position eg: for 1,2,3,4,5 if k=2 then this loop will find max (1,2) only //rememaining will be done on next loop
          while(!dq.empty() and arr[i]>arr[dq.back()]){//initially dq is empty then this while statement is not executed //
              dq.pop_back();//arr[i]>arr[dq.back()]; is used if the dq is not empty and then next element is greater than index value of the deque (arr[dq.front()]) then that new i value would become greater value  then we need to pop()our dq index and store our new i index value//
          }//NOTE:WE ONLY STORING THE INDEXES OF THAT MAX ELEMENT IN THE DEQUE NOT THEIR VALUES //
          dq.push_back(i);//so for the first time we need to push our first index value on the dq//
     }//after completion of this loop dq is going to store the index of the greater element of first kth elements//
     ans.push_back(arr[dq.front()]);//by using that index value we need to store that value of that index in our answer vector//
     for(int i=k;i<n;i++)//remaininelements max values can be done here//
{
     if(dq.front()==i-k){
          dq.pop_front();
     }
     while(!dq.empty() and arr[i]>arr[dq.back()]){//we are using same condition as before 
          dq.pop_back();
     }//NOTE:before loop will find for ex:1,2,3,4,5,6 for k=3 before loop find the indexof max i.e(2->index of value3)//if you notice here loop starts from kth position  even though next max value series are(2,3,4) but we already find the max of first 3 values so need to include 2 here if you don't understand look at your book//
     dq.push_back(i);//here we are storing the max index value
     ans.push_back(arr[dq.front()]);//here we are storing the max value
}
for(auto i:ans){
     cout<<i<<endl;
}
}