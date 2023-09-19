#include<iostream>
#include<stack>
using namespace std;
#include<vector>
//here is the problem of span of stock's price of today//
//if the before days prices is lesser then the today's price then we increse the days of today's price //
//for example prices are 100,80,60,70,60,75,85//
//initially for 100 there is no before days default no of span days will be 1//
// for 80 there is no lesser elements are presented before again the no of span days for 80 is 1//
// for 60 no of span days are 1// 
//for 70 we see before value is 60 it is samller then we increase then no of span days for 70 as one then no of spandays for 70 ->2//
//similarly for 75->no of span days are 4
//for 85->6//
vector<int> find_span(vector<int>s){//we are getting the price values here
     int days;
     vector<int>ans;
     stack<pair<int,int>>st;//first int indicates the price and second indicates the days//
     //stack<int>st;
     for(auto price:s){
           days=1;//dafaultly all span days are 1//
           while(!st.empty() and st.top().first<=price){//we are using stack here  in which before elements are presented on the stack and we compare current element price with before element price which are presented at stack//
                days+=st.top().second;//if the price of the before element is lesser than current price then increment the days of current //
                st.pop();//then pop that element again check the current element with the last before element price //until before price is greater then the current price or stack is empty//
           }
           st.push({price,days});//initialyy stack is empty so we need to push the first element on the stack and after the above while loop is dont we need to store that price and days value on the stack so this is essential 
     ans.push_back(days);//we are storing the span days  for every element here//
}
return ans;
}
 int main(){
      vector<int>s={100,80,60,70,60,75,85};
      vector<int>temp=find_span(s);
      for(auto s:temp){
           cout<<s<<endl;
      }
 }
