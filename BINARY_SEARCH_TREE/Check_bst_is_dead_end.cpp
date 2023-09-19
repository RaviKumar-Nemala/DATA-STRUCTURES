#include"tree_config.h"

/*Given a Binary search Tree that contains positive integer values greater then
 0. The task is to complete the function 
 isDeadEnd which returns true if the BST 
 contains a dead end else returns false. 

 Here Dead End means, we are not able to insert any element 
 after that node.

Examples:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
              we cant insert any element.  

*/


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */


bool solve ( int min , int max  , Node * root )
{
    if ( !root )
    return false;
    
    if  ( max == min )
        return true ;
        
    bool left = solve  ( min , root -> data - 1 , root -> left   );
    
    bool right = solve ( root -> data + 1 , max , root-> right ) ;
    
    if ( left  or right )
        return true ;
    else
        return false;

}
bool isDeadEnd(Node *root)
{
    //Your code here
    
    return solve ( 1, INT_MAX  , root  );
    
    
}

