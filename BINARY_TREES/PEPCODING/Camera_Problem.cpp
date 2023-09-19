#include"tree_code.h"

class Solution {
public:
 
    int camera = 0 ; 
    
    
    
    int minCameraCover(Node* root) {
        
      
        return util ( root   ) == -1 ? camera +  1 : camera ;
    }
        
    int util (  Node *root ){
        
        if ( root == nullptr ) return  1;
        
        int left = util  ( root -> left  );
        
        int right =  util  ( root -> right ) ;
        
        if ( left  == -1  or right == -1 )
        {
            
            camera = camera +  1  ; 
            
            return  0 ; //specifies node can have the camera
        
        }
        else if ( left  == 0  or right == 0 )
        {
            
            return 1 ; // node is covered it does not have camera
            
        }
        else 
        return  -1 ; 
        
    }
};


int main (  ) 
{


     return 0 ; 

}