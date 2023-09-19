#include<bits/stdc++.h>
using namespace std; 

struct Node
{
     int data ; 
     Node *left , *right  ; 

     Node  ( int t )
     {
          this -> data =  t ; 
          left = nullptr ; 
          right = nullptr ; 

     }
};

int find_node ( int inorder  [ ] ,  int target , int start , int end )
{

     for  ( int i = start   ; i  <= end ; i  ++ )
     {
          if  ( inorder [ i  ]  == target ) 
               {
                    return i ; 
                    break; 

               }
     }

     return -1; 

}



Node * buildTree ( int inorder [ ] , int levelorder []  , int start , int end , int n )
{
     if  ( start > end  or n <= 0 )
         return NULL ; 

     Node * root = new Node  ( levelorder [ 0 ] ) ; 

     int index =  find_node  ( inorder , root -> data , start , end  ) ; 

     unordered_set < int >  mp ; 

     for ( int i =  start  ; i <  index   ; i ++ )
     {
               mp.insert( inorder [ i ] )  ; 

     }

     int left_level [  mp.size ()  ] ; 

     int right_level [ end - start - mp.size () ] ; 
     
     int li = 0 ; 
     
     int ri = 0 ; 

     for  ( int i = 1 ; i < n ;  i ++ )
     {

          if ( mp.find ( levelorder [ i ] )!= mp.end () )  
          {
               left_level  [ li  ]  = levelorder [ i ] ;
               
               li ++; 

          }
          else 
          {
               right_level  [ ri ] =  levelorder [  i ] ; 
               
               ri ++ ;
          }

     }

     root -> left =  buildTree  ( inorder ,  left_level  , start ,  index -1 ,  index -  start ) ; 

     root -> right =  buildTree ( inorder ,  right_level , index  + 1 , end , end -  index ) ; 

     return root ;

}

void printInorder(Node* node)
{
	if (node == NULL)
	return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);

}

int main()
{
	int in[] = {4, 8, 10, 12, 14, 20, 22};
	int level[] = {20, 8, 22, 4, 12, 10, 14};
	int n = sizeof(in)/sizeof(in[0]);
	Node *root = buildTree(in, level, 0,
						n - 1, n);

	/* Let us test the built tree by
	printing Inorder traversal */
	cout << "Inorder traversal of the "
			"constructed tree is \n";
	printInorder(root);

	return 0;
}