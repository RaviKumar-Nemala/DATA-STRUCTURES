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
    vector<TreeNode*> generateTrees(int n) {
            
            return helper ( 1 ,  n ); 
    }
    
    vector<TreeNode * > helper ( int start, int end )
    {
        
            vector < TreeNode * > list ; 
        
                if ( start  > end )
                {
                    
                   list.push_back ( nullptr ) ;
                    
                    return list ;
                    
                }
        
                if ( start == end )
                {
                    
                    list.push_back ( new TreeNode ( start ) ) ;
                    
                    return list ;
                    
                }
        
        for ( int i = start ; i <= end ; i++ )
        {
            
            vector < TreeNode * > left_list = helper ( start , i - 1 );
            
            
            vector< TreeNode * > right_list = helper( i+1 , end ) ;
            
            
            
            for ( auto left_node  : left_list )
            {
                
                for ( auto right_node : right_list )
                {
                    
                    TreeNode *root = new TreeNode ( i ) ; 
                    
                    root -> left   = left_node;
                    
                    root -> right = right_node ;
                    
                    list.push_back ( root );
                    
                }
                
            }
            
            
            
        }
        
        
        return list ;
        
        
    }
    
    
    };





/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:


Input: n = 3 ( 1  , 2 , 3 ) 

       
        1           1          2             3       3    
            2         3       1     3       2       1
              3      2                      1         2
     
total bst for n = 3  = 5 



Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
*/


void preorder( TreeNode *temp )
{

     if( temp == NULL )
     return ;


     cout << temp -> val <<"  " ;

     preorder ( temp -> left ) ;


     preorder( temp -> right ) ; 

}
int main()
{

     Solution obj ; 
     vector< TreeNode*> temp = obj.generateTrees (3) ;

     for( auto it : temp )
     {

          preorder( it ) ;

          cout << endl; 

     }



} 