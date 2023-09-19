#include<bits/stdc++.h>
using namespace std ;


void display(priority_queue<int>max_heap)
{
     while ( !max_heap.empty() )
     {
          cout << max_heap.top() <<" " ;
          max_heap.pop();
     }
     cout<<endl;
     return;
}

void display_min_heap ( priority_queue<int , vector<int>  , greater<int> >  min_heap)
{
     while (!min_heap.empty() )
     {
          cout << min_heap.top ()<<" "; 
          min_heap.pop();
     }
     cout << endl;
     return;
}

int main () 
{
     int arr [ 5 ] = { 1, 2 ,3,4,5};

     //default priority queue is the max_heap

     priority_queue<int>max_heap ( arr , arr + 3);//directly inserts the first 3 elements of the array in to the heap
     display(  max_heap);

     //syntax for the min_hea p

     priority_queue< int , vector<int> , greater < int > > min_heap ( arr , arr + 4 ) ;//initializing the min_heap with the first four elements

     display_min_heap( min_heap);

     return 0;
}