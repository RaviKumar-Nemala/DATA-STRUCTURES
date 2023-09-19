#include<bits/stdc++.h>
using namespace std; 

struct Node 
{
     int data ; 
     Node *left ; 
     Node *right ;
     Node ( int temp )
     {
          data = temp ;
          left = nullptr ;
          right = nullptr ;
     }

     Node  ( int temp   , Node * l  , Node * r)
     {
          data  = temp ;
          left = l ;
          right = r ; 

     }
     
};



