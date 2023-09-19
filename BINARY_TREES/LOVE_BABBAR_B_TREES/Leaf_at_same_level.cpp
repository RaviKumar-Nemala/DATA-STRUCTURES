// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/




class Solution{
  public:
  
 
 int ans = 1 ;
  
  
  
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        
        int height  = 0 ; 
        
        int leaf_level = -1 ; 
        
        util  ( root , leaf_level , height  ) ;
        
        return ans ;
    }
    
    bool isLeaf (  Node  * root )
    {
        
        if ( root!= nullptr   and root -> left == nullptr and root -> right == nullptr )
        return true ;
        else
        return false ;
        
        
    }
    void util  ( Node  * root , int &leaf_level , int height  )
    {
        
        if  ( root == nullptr )    
            return ; 
            
        if ( isLeaf ( root )   ) 
        {
            
            if ( leaf_level == -1 )
            {
                
                leaf_level  = height ; 
                
            }
            else 
            {
                
                if ( leaf_level !=  height ) //if already leaf node is found and if another leaf node is not in the same height of the before leaf node then we can say  leaf nodes are not at same level
                {
                    ans =  0 ;
                }
                        
                
            }
            return ; 
            
            
        }
        
       
       
        util  ( root -> left , leaf_level   ,  height + 1    );
        
        util ( root -> right,  leaf_level ,  height + 1   ) ;
        
        return;
    }
};

// { Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}
  // } Driver Code Ends