// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

     Node ( int data)
     {
          this ->data = data;
          this->left  = nullptr;
          this->right =  nullptr;
     }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Fuction template for C++

class Solution {

     private :
     bool is_leaf ( Node *root )
     {
          return ( root and !root->left and !root->right) ? true : false;
     }

  public:
  int max_sum =  INT_MIN; 
    //Function to return maximum path sum from any node in a tree.
     void findMaxSumUtil(Node* root , int sum)
    {
          if( root == nullptr)     return;
          if( root and !root->left and !root->right) 
          {
               sum = sum + root->data;
               if ( sum > max_sum )    max_sum = sum;
               return;
          }      

          int temp = root->data;
          findMaxSumUtil( root -> left, sum + temp);
          findMaxSumUtil( root->right , sum + temp);
    }
    
    int findMaxSum (  Node *root )
    {
          findMaxSumUtil (root , 0);
        
        return this->max_sum ; 
    }
};

// { Driver Code Starts.

void inorder ( Node * root )
{
     if ( root == nullptr) return;

     inorder ( root ->left);
     cout << root -> data <<" ";
     inorder( root -> right ) ;
}

int main ()
{
     Node * root = new Node( 10);
     root->left = new Node( 11);
     root-> right  = new Node(12);
     root->left-> left= new Node( 43);
     root->left->right = new Node( 14);
     Solution obj;
    cout<<obj.findMaxSum( root)<<endl;
     inorder( root );
     return 0;
}