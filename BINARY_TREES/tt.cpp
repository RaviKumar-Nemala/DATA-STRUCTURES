#include<bits/stdc++.h>

using namespace std ; 

static int single_child_count =  0 ; 


struct Node 
{

     int data  ; 
     Node *left , * right ; 
     Node (  int  t )
     {
          this -> data = t ; 

          left = right = nullptr ; 
     }
     
};

bool util ( Node * temp )
{
     if ( temp == nullptr)
     {
          return false ;
     }
     if ( (temp->left  and  !temp->right  ) or ( temp->right and !temp-> left )  ) 
     {
          return true ;
     }
	return false ; 
}
void single_child ( Node * root ,  Node *parent )
{

     if ( root == nullptr )
     return ; 

     
     if ( util ( parent ) )
     {
          cout << parent -> data << " " ;
		single_child_count ++ ; 
     }



     single_child ( root -> left ,root ) ; 

     single_child ( root -> right  , root ) ; 

     return;
}

void print_k_level_down ( Node *root ,  int k , Node *blocked_node  )
{

		if ( root == nullptr or k < 0  or root == blocked_node  )
			return ; 

		if ( k == 0)
		{
			cout << root -> data <<  " " ;
			return ; 
		}

		print_k_level_down ( root -> left , k - 1   , blocked_node );

		print_k_level_down ( root -> right , k  -1  ,  blocked_node ) ; 

}

vector < Node*> path ;  

bool node_to_root ( Node *root ,  int target   )
{
	if ( root == nullptr  )
	return false ; 

	if ( root -> data == target )
	{
		path.push_back ( root  ) ; 	
		return true ;
	}
	
	bool c1   =  node_to_root ( root -> left , target ) ; 
	
	if ( c1 )
	{
		path.push_back (root  ) ; 
		return true ; 
	}
	bool c2 = node_to_root (root -> right , target) ; 

	if  ( c2  )
	{
			path.push_back ( root ) ;
			return true ; 
	}	

	return false ; 

}

void solve (  Node *root , int k  , Node * target_node )
{
	if ( root == nullptr )
	{
		return  ; 

	}

	path.clear () ;

	node_to_root(root ,target_node->data ) ; 

	int n =  path.size() ; 

	for   ( int i = 0  ; i <  n  and i <= k ; i ++ )
	{
		if ( i == 0 )
		{
			print_k_level_down (  path [ i ] , k , nullptr ) ; 
		}
		else 
		print_k_level_down ( path [ i ] , ( k - i ) , path [ i -1 ] )  ; 

	}


}
int main  ( )
{
	Node *root = new Node  ( 1 )  ; 

	root -> left  = new Node ( 2  ) ; 

	root  -> left -> left = new Node  ( 3 ) ; 

	root -> left -> right = new Node ( 4 ) ; 

	//single_child ( root  , nullptr ) ; 
	

	solve ( root , 1 , root -> left ) ; 

	cout << endl ; 
	
	fflush (stdin)  ;

	cout << "SINGLE CHILD NODES COUNT : " << single_child_count  << endl ; 
	
	return 0 ; 


} 