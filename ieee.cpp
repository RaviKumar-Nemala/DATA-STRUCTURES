#include<bits/stdc++.h>
using namespace std ;

static bool comp ( int  a, int b ){
    return a < b;
}
int main () 
{
    vector < int > vals = {  5 , 4, 3 , 2 , 1 } ;
    sort ( vals.begin ()   , vals.end () , comp );
    for( auto it : vals )   
        cout << it <<" " ;
}