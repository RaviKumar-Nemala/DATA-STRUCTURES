// C++ program to find the height of an N-ary
// tree
#include <bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
struct Node
{
	char key;
	vector<Node *> child;
};

// Utility function to create a new tree node
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	return temp;
}

int diameter(struct Node *ptr,int &diameter_of_tree)
{
	// Base case
	if (!ptr)
		return 0;

	// Find top two highest children
	int max1 = 0, max2 = 0;
	for (vector<Node*>::iterator it = ptr->child.begin();it != ptr->child.end(); it++)
	{
		int h = diameter(*it,diameter_of_tree);
		if (h > max1)
		max2 = max1, max1 = h;
		else if (h > max2)
		max2 = h;
	}

	// Find whether our node can be part of diameter
	diameter_of_tree = max(max1 + max2 + 1,diameter_of_tree);

	return max(max1,max2) + 1;
}

int main()
{
		/* Let us create below tree
		*		 A
		*		 / / \ \
		*	 B F D E
		*	 / \ / /|\
		*	 K J G C H I
		*	 /\		 |
		* N M	 L
		*/
	Node *root = newNode('A');
	(root->child).push_back(newNode('B'));
	(root->child).push_back(newNode('F'));
	(root->child).push_back(newNode('D'));
	(root->child).push_back(newNode('E'));
	(root->child[0]->child).push_back(newNode('K'));
	(root->child[0]->child).push_back(newNode('J'));
	(root->child[2]->child).push_back(newNode('G'));
	(root->child[3]->child).push_back(newNode('C'));
	(root->child[3]->child).push_back(newNode('H'));
	(root->child[3]->child).push_back(newNode('I'));
	(root->child[0]->child[0]->child).push_back(newNode('N'));
	(root->child[0]->child[0]->child).push_back(newNode('M'));
	(root->child[3]->child[2]->child).push_back(newNode('L'));
	
	// for storing diameter
	int diameter_of_tree = 0;
	
	diameter(root,diameter_of_tree);
	
	cout << diameter_of_tree << endl;

	return 0;
}
// This code is improved by bhuvan
