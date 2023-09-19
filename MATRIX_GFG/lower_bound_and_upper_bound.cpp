#include<bits/stdc++.h>
using namespace std ;


int main ()
{

vector< int > arr = { 10 , 10,  40 , 50, 60 , 70 , 70  } ;

vector< int > ::iterator  it ;

int n = 6 ;

it = upper_bound ( arr.begin () , arr.end () , 60 ) ;

// cout << ( it - arr.begin () )  << endl; 
if ( it == arr.end () ) 
{
     cout <<"NO GREATER ELEMENT IS FOUND " << endl; 
}
else
{
     cout << it- arr.begin() <<endl;
}

return  0;

}