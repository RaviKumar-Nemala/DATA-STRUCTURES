#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

static int idx = 0 ; 

class Solution{
    public:
        
    int findPos (  int in[ ] , int start , int end  , int key ) 
    {
        
        for ( int i = start ; i <= end ; i ++ )
        {
            if  ( in [ i ] == key )
            
            {
                
                
                return i; 
                
            }
            
            
        }
        
        return  -1;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int idx = 0 ; 
        return util ( in  , pre , 0 ,  n -1 ,  &n , &idx  ) ;
        
    }
    

    
    Node * util (  int in [] , int pre []  , int start , int end ,  int *n   , int *idx ) 
    {
            
        if ( *idx >= *n or start > end ) 
        {
            return nullptr ;
        }
        
        int ele =  pre  [ *idx ]  ;
        
        *idx  = *idx +  1  ;
        
        Node * root = new Node ( ele ) ;
        
        if ( start == end )
        return root ; 
        
            
        int pos  = findPos ( in  , start , end  , ele );
        
        root -> left = util  (  in , pre , start , pos -1   , n , idx  ) ;
        
        root -> right = util (  in  , pre , pos + 1 , end , n  , idx ) ;
        
        
        return root ; 
        
     }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends