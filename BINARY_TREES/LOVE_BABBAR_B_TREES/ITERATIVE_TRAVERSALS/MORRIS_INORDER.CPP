#include<iostream>
using namespace std ; 
#include <vector>


struct TreeNode 
{
    int val;

    TreeNode *left;
    TreeNode *right;
    TreeNode ( int data )
    {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }  
};

class Solution {
public:
    vector < int > ans ;
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        if (root == nullptr )
            return { }; 
        
            
        util ( root );
        
        return ans  ; 
        
        
    }
    
    
    void util  ( TreeNode *root ) 
    {
        
            TreeNode *curr = root ; 
            
        
        
            while ( curr != nullptr )
            {
                // go to the complete left and print that node 
                if ( curr -> left  == nullptr )
                {
                    ans.push_back ( curr -> val ) ;
                    
                    curr = curr -> right ; // this is used to back track to the parent node or the next processed node 
                    
                }
                    
                else 
                {
                    
                    TreeNode * predec  =  curr -> left ;
                    //find the predec ( right most element on the //curr -> left side  then store the curr address on that node )
                    
                    while ( predec -> right != curr  && predec-> right != nullptr  )
                    {
                        
                      predec = predec -> right  ;
                        
                    }
                
                    //if the predec -> right = null when this is  // node is not processed then store the predec-> right to the // // curr( node ) address after processing of this then we can //simply go the  next processed node 
                    
                    if ( predec -> right ==  nullptr )
                    {
                        
                        predec -> right  = curr  ; 
                        
                        curr = curr -> left ; 
                        
                    }
        //if the node is already means we printed the inorder of //that element then  make that node -> right = nullptr then go  // to the next node                   
                    else 
                    {
                        predec -> right =  nullptr ; 
                        
                        ans.push_back ( curr -> val  ) ;
                        
                        curr = curr -> right ; 
                    }
                }
                
                
            }
        
    }
    
};




//  TIME COMPLEXITY = O( n ) ;

// SPACE COMPLEXITY = O ( 1 ) ;
