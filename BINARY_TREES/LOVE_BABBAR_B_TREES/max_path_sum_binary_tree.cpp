#include<iostream>
using namespace std;
#include<limits.h> 
#include<algorithm> 


  //Definition for a binary tree node.
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
    int sum =  INT_MIN ;
    
    
    int maxPathSum(TreeNode* root) {
        
        if ( root  == nullptr )
            return  0 ; 
        int temp =  util ( root ) ;
        
        return sum ; 
        
    }
        
        int util ( TreeNode *root )
        
        {
            if ( root == nullptr )
                return 0 ; 
            
            
        int left =  util ( root  -> left ) ;
        
        int right = util ( root -> right ) ;
            
        int current_sum =  left + right + root -> val ; 
            
        int case_1 =  max  (  max ( left + root -> val  ,  right + root -> val ) ,  root -> val )  ; 
        
        sum  = max ( sum  , max ( current_sum , case_1 ) )  ;
            
        return case_1  ;
            
    }
    
};



int main  (  )
{


     
}