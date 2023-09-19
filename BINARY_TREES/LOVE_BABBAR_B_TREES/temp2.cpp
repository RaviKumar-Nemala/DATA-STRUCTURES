#include<bits/stdc++.h>
using namespace std ;


struct Node 
{
    
    vector < Node *> child_nodes ;
    
    int data ;
    
    Node   ( int data )
    {
        this -> data = data;
        
    }
    
    void addChild( Node *child )
    {
        this -> child_nodes.push_back ( child ) ;
    }
    
};


map < int ,vector < Node *> > mp;


class Solution {
public:
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        if ( n ==1 )
        {
            return 0 ;
        }
        
        
        Node * root = new Node ( headID ) ;
        
        mp [ root->data ].push_back ( { } ) ;  
        
        for ( int i = 0 ; i < manager.size () ; i ++ )
        {
            
           if ( manager [ i ] == -1 )
               continue ;
        
            int parent = manager [ i ] ;
            
            Node * child  = new Node( i ) ;
            
            
            if ( mp .find ( parent ) != mp.end () )
                
            {
                
                mp [ parent ].push_back ( child ) ;
            
                
            }
            
            mp [ child->data ].push_back( { } );   
            
        }






    
    }
};