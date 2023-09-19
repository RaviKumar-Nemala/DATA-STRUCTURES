// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



 // } Driver Code Ends
//User function Template for C++



class Solution
{
public:


    // function to construct tree from string
    Node *treeFromString(string str)
    {
        // code here
        
        int idx = 0 ; 
        
        int len   = str.size (  )  ; 
        
        return util (  str , &idx , &len  ) ;    
    }
    
    Node * util ( string s   , int  *idx , int *len )
    {
        
        if (  *idx  >= *len   )        
        {
            return nullptr ; 
        }
        
        bool neg =  false ; 
        
        char ele =  s [ *idx ] ; 
        
        if (  ele == '-' )
        {
            neg =  true ;
            
            idx ++ ;
            
        }
        
        int num = 0 ; 
      
        
        while ( *idx < *len  and  isdigit ( s [ *idx ] ) )
        {
            
            int digit = s [ *idx ] - '0' ; 
            
            num =  num * 10 + digit ; 
            
            *idx = *idx +  1  ; 
            
        }
        
        if ( neg )
        {
            num = - num ;
            
        }
        Node * root = new Node  ( num ) ;
        
        
        if( *idx >= *len )
            return root ; 
            
        
        if ( *idx < *len  and  s [ *idx ] == '(' )
        {
            *idx =  *idx  + 1 ;
            
            root -> left =  util ( s , idx , len  ) ;
        }
        
        if ( *idx < *len and s [ *idx ] == ')')
        {
            *idx  = *idx + 1 ;
            return root ; 
        }
        
        if ( *idx < *len and s[ *idx ] == '(' )
        {
            *idx  = *idx + 1 ;
            root -> right = util ( s , idx , len  );
            
        }
        
        if ( *idx < *len and s[ *idx ] == ')')
        {
            *idx  = *idx + 1 ; 
            
            return root ;
            
        }
        
        return root ;
        
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends