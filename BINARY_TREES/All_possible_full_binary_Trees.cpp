#include<bits/stdc++.h>
using namespace std ;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
   
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if ( n ==1 )
        {
            
            vector < TreeNode* > temp ; 
            
            TreeNode *node = new TreeNode ( 0 ) ;
            
            temp.push_back ( node ) ;
            
            return temp ; 
        }
        
        vector < TreeNode * >  ans ; 
        
        for ( int i = 1  ; i  < n ; i = i + 2 )
        {
            
    vector <TreeNode *> left_list = allPossibleFBT ( i ) ;
            
            
    vector < TreeNode *> right_list = allPossibleFBT ( n - i -1 ) ;
            
    
            for ( auto  left_node  : left_list )
            {
                for ( auto right_node : right_list)
                {
                    
                    TreeNode *root = new TreeNode ( 0 ) ;
                    
                    root -> left  = left_node ;
                    
                    root -> right= right_node;
                    
                    ans.push_back ( root  ) ;
                    
                }
            }
        }
        
    
        
        return ans ; 
        
    }
        
        
};