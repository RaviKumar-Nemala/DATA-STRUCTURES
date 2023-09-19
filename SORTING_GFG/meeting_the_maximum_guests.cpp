#include<bits/stdc++.h>
using namespace std ;

struct result 
{
     int time_val ;
     int max_guests;
};

result get_max_guests ( vector<int> arrival , vector < int > depature)
{
     int n1 = arrival.size () ;
     int n2  = depature.size ();

     sort(arrival.begin () , arrival.end());
     sort( depature.begin () , depature.end());

     int i = 1 ; 
     int j = 0 ;   
     int curr_guests  = 1 ;
     int max_guests =  1 ;
     
     int time_val = arrival[0];

     while ( i < n1 and j < n2 )
     {
          if ( arrival[i] <= depature [ j ])
          {
               curr_guests ++;
               i ++ ;
          }
          else 
          {
               j ++;
               curr_guests --;
          }
          if ( curr_guests > max_guests)
          {
               time_val = arrival[ i-1 ];
               max_guests = curr_guests ;
          } 
     }

     result res ;
     res.time_val = time_val ;//timeval specifies when we should enter inorder to meet the maximum guests 
     res.max_guests  = max_guests;
     
     return res;
}

int main ()
{
     vector < int > arrival = { 900 , 600,700};
     
     vector <int > depature =  { 1000 , 800 , 730};
     //function returns the max guests that  we can able to meet 
     //when we enter at some point of time 
     result res = get_max_guests( arrival , depature);

     cout << res.time_val <<" " << res.max_guests << endl; 

     return  0;
}