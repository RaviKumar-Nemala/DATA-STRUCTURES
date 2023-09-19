#include<bits/stdc++.h>
using namespace std ;

class config{
     public:
     int start;
     int end;

};

bool get_min (pair<int,int>obj_1 , pair< int , int >obj_2)
{
     return (obj_1.first < obj_2.first);
}

void print_val( vector < pair<int ,int > > arr )
{
     for( auto  it : arr )
     {
          cout << it.first <<  "  " << it.second <<  endl ;
     }
     return;
}

void merge( vector<pair<int,int > > arr  ) 
{
     
     for(int idx = 1 ; idx < arr.size () ;idx++ )
     {
          int before_start = arr[idx-1].first;
          int before_end = arr[ idx-1].second;    

          int curr_start = arr[idx].first; 

          int curr_end = arr[ idx].second;

          if ( curr_start <= before_end)
          {    
               arr[ idx ].first = before_start ;
               arr[ idx ].second = max(before_end , curr_end ) ;
               pair<int,int> temp = make_pair(INT_MAX , INT_MAX);
               arr[ idx - 1] =  temp;
          }
     }

     for(  auto it : arr ) 
     {
          if ( it.first == INT_MAX or it.second == INT_MAX)
          {
               continue;
          }
          cout << it.first << " " << it.second <<  endl;
     }

     return;
}

int main ()
{
     vector<pair<int ,int > >  arr = { {1,3} , { 5,7} , { 2,4} , {6,8}};
     
     sort( arr.begin () , arr.end () , get_min);

     merge ( arr ) ;

     return 0;

}