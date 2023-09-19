#include<bits/stdc++.h>
using namespace std;



void display ( int arr [] ,int n )
{
     for ( int i = 0  ; i < n ;i  ++)
     {
          cout << arr [ i ] << " " ;
     }
     cout << endl;
}



int  optimal_solution( int arr[] , int n , int sum )
{

     priority_queue<int , vector<int>  , greater<int> > min_heap( arr , arr +n);
     int count  = 0;
     cout << "ADDED VALUES = ";
     while ( !min_heap.empty())
     {
          int curr_val = min_heap.top();
          min_heap.pop();
          if ( sum > curr_val)
          {
               cout << curr_val <<" " ;
               sum -= curr_val;
               count ++;
          }
          else
          {
               break;
          }
     }
     cout << endl;

     return count;

}



int  naive_solution( int arr [] , int n ,int sum )
{    
     vector < int >temp ( arr , arr+ n);

     sort( temp.begin () , temp.end());

     int count =  0 ;

     for ( auto it: temp)
     {
          if (  it  < sum )
          {
               count ++;
               sum -=  it;
          }
          else 
          {
               break;
          }
     }

     return count;

} 

int main()
{
     int arr  [] = { 10 , 4 ,  5 , 16 , 9 };

     int sum = 25 ;

     cout<<optimal_solution ( arr,5 , sum )<< endl;

     return 0;
}