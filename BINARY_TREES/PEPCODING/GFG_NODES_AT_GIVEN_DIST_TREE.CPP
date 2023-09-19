// { Driver Code Starts
#include<bits/stdc++.h>
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
vector < Node * > path ;

vector < int > ans;

    void print_k_down ( Node *root , int k  , Node* blocked_node  ,  vector < int > &ans )
    {
        
        if   ( root == nullptr or k < 0 or  root == blocked_node )
        {
            
                return ; 
            
        }
        
        if (  k == 0 )
        {
            
                ans.push_back ( root -> data ) ; 
                
                return ;
                
        }
        
        print_k_down ( root -> left , k -1 , blocked_node  , ans  ) ;
        
        print_k_down ( root -> right , k -1 , blocked_node   , ans ) ;

    }
    
    
    bool node_to_root ( Node *root ,int key )
    
    {
        
            if ( root == nullptr )
            return false; 
            
            if ( root -> data == key )
            {
                    
                    path.push_back ( root ) ; 
                    
                    return true ; 
                    
            }
            
            bool left =  node_to_root ( root -> left , key ) ;
            
            if( left )
            {
                path.push_back ( root ) ;
                return true ;
                
            }
            
            bool right = node_to_root ( root -> right , key ) ;
            
            if ( right )
            {
                path.push_back ( root ) ;
                
                return true ;
                
            }
            
            return false ;
        
    }
    
    
    

public:




    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        
        path.clear()  ;
        
        ans.clear() ; 
        
        node_to_root ( root , target ) ;
        
        int n =  path.size() ; 
        
        for ( int i = 0 ; i < n  ; i ++)
        {
            
            print_k_down (  path[ i ] ,  k - i  , i == 0 ? nullptr : path [ i - 1] ,  ans  ); 
            
        }
        
        sort ( ans.begin () ,  ans.end()) ; 
        
         return ans ; 
            
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends