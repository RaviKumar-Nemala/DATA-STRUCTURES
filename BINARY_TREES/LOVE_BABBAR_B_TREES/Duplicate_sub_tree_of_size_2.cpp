// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
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

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


 // } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
  
  map < string , int > mp ; 
  
 
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         // code here
         
         
        string temp = util ( root  , mp );
        
        for ( auto it : mp)
        {
            if ( it.second >= 2 )
            {
                return 1 ; 
                break ;
            }
        }
        
        return 0 ;
        
    }
    
    string util ( Node * root , map < string , int  > &mp )
    {
            
        if ( root == nullptr )
        return "$"; 
     // HERE WE SHOULD USE "$" ( ANY SPECIAL SYMBOL ) BECUASE OF 
// SUPPOSE 
/*

     2                  2
   4   5                    4
                              5

     BELOW THESE ARE BECOME "245" IN THE STRING IF WE DON'T USE ANY SPECIAL SYMBOL
BUT THESE TWO ARE NOT SAME SUB TREES 
SECOND REPRESENTATION DOES NOT HAVE LEFT IF IT DOES NOT HAVE LEFT THEN WE NEED TO ADD ONE SPECIAL SYMBOL TO 
GET THE CORRECT RESULT WHILE CALCULATING THE RESULT 


*/


       if ( !root -> left and !root -> right ) 
       
       // THIS IS USED BECAUSE WE DON'T WANT TO CONSIDER THE HASES OR THE SUBTREES FOR THE LEAF NODES 
// IF TWO LEAF NODES ARE EQUAL THEN WE CAN'T SAY THOSE ARE TWO IDENTICAL SUBTREES 
// SO WHEN EVER THE LEAF NODE IS ENCOUNTER THEN WE RETURN ITS VALUE 

       {
            return to_string ( root -> data ) ;

       }
        
        string s = "";
        
        s += util ( root -> left , mp ) ;
        
        s +=  to_string ( root -> data ) ; 
        
        s += util ( root -> right , mp );
        
        mp [ s ] ++ ;
        
        return s ;
    
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends