#include<bits/stdc++.h>
using namespace std; 

struct Node
{
    int data;
    Node *left  ; 
    Node *right ;

    Node ( int data ) 
    {
         this -> data = data ; 

         this -> left = nullptr ;

         this -> right = nullptr ;
    }

};


void level_order ( Node * root )
{
        queue< Node * >  q   ;
        q.push  ( root ) ;

        while ( !q.empty () ) 
        {
            int size = q.size () ;

            while ( size -- )
            {
                Node *curr_node  = q.front ();
                q.pop ();
                if( curr_node -> left )
                {
                        q.push ( curr_node  -> left ) ;
                }
                if( curr_node -> right )
                {
                        q.push ( curr_node -> right );    
                }

               cout << curr_node -> data << "  " ; 
            }
            cout << endl;
        } 


}

void inorder ( Node *root )
{
     if ( root == nullptr )
     {
         return;
     }

     inorder( root -> left );
     cout << root -> data<< " " ; 

     inorder ( root-> right );
}


Node  * build_tree ( vector < int > arr ) 
{
    int idx  = 0 ;

    int n  = arr.size() ; 

    int curr_ele = arr [ idx ] ;


    Node * head = new Node( curr_ele ) ;

    queue< Node * > q ;

    q.push ( head ) ; 

    while ( !q.empty() )
    {

         Node *curr_node = q.front ( ) ;

         q.pop () ;

         idx ++;
         if ( idx  < n )
         { 
             int left = arr  [ idx ] ;
            Node * left_node =  nullptr;
             if( left == INT_MAX)
             {
                 curr_node  -> left  = nullptr;
             }
            else
            {
                left_node =  new Node ( left ) ;

                curr_node  -> left = left_node;

                q.push ( left_node ) ;
            }
         }

         idx ++;

         if ( idx < n  ) 
         {
            int right = arr [ idx ] ; 
            Node  * right_node  = nullptr;
            if ( right == INT_MAX)
            {
                 curr_node -> right = nullptr;
            }
            else 
            {
                right_node  = new Node ( right ) ;

                curr_node-> right = right_node;

                q.push  ( right_node);                 
            }
         }

    }
    
    return head;
}

bool is_leaf( Node * node )
{
    if ( node and !node -> left and !node -> right )
    {
            return true;
    }
    else 
        return false;
}

void inorder_iterative( Node *root )
{
    stack < Node * > st ;

    while ( true )
    {
        if ( root )
        {
            st.push ( root ) ;
            root = root  -> left ;     
        }
        else 
        {
            if ( st.empty () ) 
            {
                 break;
            }
            else 
            { 
                root = st.top () ;

                st.pop () ;

                cout << root -> data ; 

                root = root -> right ;

            }

        }
    }   



}


void mirror ( Node * root )
{
    if ( !root )
    {
         return ;
    }

    if  ( is_leaf ( root ) ) 
    {
        return ; 
    }   
    
    mirror ( root -> left ) ;

    mirror ( root -> right ) ; 
    
    if( root -> left and  root -> right ) 
    {   
        Node * temp   = root -> left ;

        root -> left = root -> right ;

        root -> right = temp ; 
    }
    
    else if ( root -> left  and !root -> right )
    { 
        root -> right = root -> left;

        root -> left = nullptr;
    }
    
    else if ( !root -> left and root -> right )
    {
         root -> left  = root -> right ;

         root -> right = nullptr;
    }
    
    return;

}
void reverse_level_order  ( Node *root )
{    
     queue< Node * > q  ;

     q.push ( root ) ; 

     stack < int > st ;

    while ( !q.empty () ) 
    {
        Node * curr_node = q.front () ;
        q.pop() ;

        st.push (  curr_node -> data ) ; 
        if( curr_node -> right )   
        {
             q.push ( curr_node -> right );
        }
        if ( curr_node -> left ) 
        {
            q.push ( curr_node -> left ); 
        }    
    }

    while ( !st.empty () ) 
    {
         cout << st.top() << " " ; 
         st.pop( ) ;
    }

}
void post_opder_iterative( Node * root )
{   
    stack <Node * > st1 ;
    stack < Node * > st2 ;

    st1.push ( root ) ;

    while ( !st1.empty () ) 
    {   
        Node* curr_node =  st1 .top () ;

        st1.pop () ; 

        st2.push ( curr_node ) ;
    
        if ( curr_node -> left ) 
        {
            st1.push ( curr_node -> left ) ; 
        }
        if( curr_node -> right )
        { 
            st1.push( curr_node -> right );
        }
    }

    while ( !st2.empty ()  ) 
    {
        cout << st2.top () -> data << " " ;
        
        st2.pop () ; 

    }

    return ;

}


void preorder_recursive( Node *root ) 
{
    stack < Node * > st ;

    // st.push ( root ); 

    while ( true ) 
    {   
        if( root  == nullptr )
        {
            if ( st.empty () ) 
            { 
                break;
            }
            else{
                root = st.top () ;
                st.pop () ;
            }
        }

        cout << root -> data <<" " ;

        if( root -> right )
        {
            st.push ( root-> right ) ; 
        }   

         root  = root -> left ;
    }

}
void bottom_view  ( Node * root ) 
{   
    map < int , int  > mp ; 

    queue < pair < int , Node*  > >  q ;

    q.push( { 0 , root }  ) ;

    while ( !q.empty () ) 
    {   
        auto it  = q.front () ; 

        int hd = it.first ;
        
        Node * curr_node = it.second ;

        q.pop () ;

        mp [ hd ] =  curr_node -> data ; 
             
        if( curr_node -> left ) 
        {   
            q.push ( {  hd - 1 , curr_node -> left } ) ; 
        }
        if( curr_node -> right ) 
        {
             q.push ( { hd+1  , curr_node -> right } ) ; 
        }
    }

    for ( auto it :  mp ) 
    {
        cout << it.second << " " ; 
    }
    cout << endl;
}

void diagonal_traversal ( Node * root ) 
{   
    Node * temp  = root ; 

     queue < Node * > q ;

     q.push ( root ) ;

     while ( !q.empty () )
     {  
        root =  q.front () ;
        q.pop () ; 

        while ( root != nullptr )
        { 
            if ( root -> left )
            {
                q.push ( root -> left ) ; 
            }
            cout << root -> data  << " " ;

            root = root -> right ;
        }    
     }

}

vector< int >  left_boundary ( Node  * root )
{
    vector< int > ans ;

    while ( root != nullptr and is_leaf ( root ) == false ) 
    {
        ans.push_back (  root  -> data ) ;

        root = root -> left; 
    }

    return ans ;

}

vector< int > right_boundary ( Node * root ) 
{ 
    vector  < int > ans ;

    while ( root != nullptr and is_leaf ( root ) == false )
    { 
        ans.push_back ( root -> data ) ;

        root = root -> right ;
    }
    
    reverse ( ans.begin () , ans.end() ) ;

    return ans;

}

void leaf_nodes (   Node * root , vector< int > &arr ) 
{ 
    if( !root )
        return ;

    if( root and  !root -> left and !root -> right )
    {
        arr.push_back ( root -> data ) ;

        return ;
    }

    leaf_nodes ( root -> left , arr );

    leaf_nodes ( root -> right , arr ) ; 

}
 
void boundary_traversal ( Node * root ) 
{   
    vector< int > left_val = left_boundary ( root ) ;

    vector< int > right_val = right_boundary  ( root  -> right) ;

    vector< int > leaf_val  ; 
    
    leaf_nodes ( root  , leaf_val ) ; 

    vector< int > ans = left_val ;

    for (  auto  it  : leaf_val )
    {
         ans.push_back ( it ) ; 
    }
    for ( auto  it : right_val ) 
    { 
        ans.push_back ( it ) ; 
    }

    for( auto   it : ans )
    {
        cout <<  it << " " ; 
    }
    cout << endl;



}

Node * _prev = nullptr ; 

Node * head = nullptr ; 

void dll ( Node * root )
{
    if( !root ) return ;

    dll ( root -> left ) ; 

    if( _prev == nullptr )
    {
        _prev = root ;
        head = root ;
    }
    else 
    {
        _prev  -> right = root ;

        root -> left = _prev ;
        _prev   = root ; 
    }

    dll ( root -> right ); 

}

void iterate ( Node * head )
{
    while ( head  != nullptr )
    {
         cout << head -> data << " " ;
         head = head ->right;
    }
    cout << endl;
}

int  sum_tree ( Node * root )
{
    if ( root == nullptr)
        return  0; 

    if( is_leaf ( root ) ) 
    {  
        int x = root -> data ;
        return x;
    }

    int left = sum_tree ( root -> left ) ;

    int right = sum_tree (  root -> right ) ;

    int y  = left + right  + root -> data ;

    root -> data = left + right ; 

    return y ; 

}

int get_mid ( vector< int > inorder , int  target , int low, int high )
{
    for ( int idx = low ; idx <= high ; idx ++ )
    {
        if ( inorder [ idx ]  == target )
        {
             return idx ; 
        }
    }
    return -1;

}

Node * build_tree (  vector < int > &inorder , vector< int > &preorder ,  int start , int end )  
{
    static int idx  = 0 ;

    if ( start > end  || idx >=  inorder.size () ) 
    {
         return nullptr;
    }

    int ele = preorder [ idx++ ] ;

    Node * root    = new Node(ele );

    if ( start == end  )
    {
         return   root ;
    }

    int mid_idx  =  get_mid ( inorder  , ele, start , end ) ;

    root -> left = build_tree  ( inorder , preorder ,start   , mid_idx-1  ) ; 

    root -> right = build_tree ( inorder  ,  preorder ,   mid_idx + 1 ,  end ) ; 

    return root ; 
    
}

void inorder( Node * root, vector < int > &res )
{
    if ( !root )    return ;

    inorder( root -> left , res) ; 

    res.push_back ( root -> data) ;

    inorder (  root -> right,  res ) ; 

}
bool comp (  pair <int , int > p1 , pair< int, int >  p2 ) 
{
    return p1.second < p2.second ;
}

void min_swap ( Node *root ) 
{
    vector < int > arr  ; 

    inorder ( root,  arr ) ; 
    
    vector < pair<int , int >  > srt_arr ; 

    for ( int idx = 0 ;  idx < arr.size () ;  idx ++ )
    {
        pair <int , int > p = { idx , arr [ idx ] } ;

        srt_arr.push_back ( p ) ; 
    }   
    
    sort (  srt_arr.begin () , srt_arr.end() , comp ) ; 

    int idx = 0 ;
    int swaps = 0 ;
    while ( idx < arr.size () ) 
    {
         auto  it  =  srt_arr [ idx ];
        
        int srt_idx = it.first ;

        int srt_val  = it.second ; 

        if ( srt_val == arr [ idx ] ) 
        {
            idx ++;
             continue;
        }
        
        swaps ++;
        
        swap ( srt_arr [ idx ] , srt_arr [ srt_idx ] ) ;        

    }
    cout << swaps << endl;
}

Node * lca(  Node * root , int a , int b )
{
     if ( !root )   return nullptr;

     if( root -> data == a  or root -> data == b )
     {
         return root;
     }

     Node *left = lca ( root -> left , a , b ) ;

     Node * right = lca ( root -> right , a , b ) ;

     if( left and right )
     {
        return root;   
     }
    
     if ( !left )
     {
         return right ;
     }
     else 
        return left;
}

void  get_distance( Node * root , int key , int lvl  , int &dis)
{ 
        if ( !root )    return  ;

        if ( root -> data == key )  
        {
             dis  = lvl;
             return;
        }
        get_distance(  root -> left , key , lvl  + 1 , dis ) ;

        get_distance ( root -> right , key , lvl + 1,  dis );


}
int find_distance ( Node * root,  int  a , int b ) 
{

    Node * parent = lca  ( root , a , b);

    int l1  = 0 ;

    get_distance(  root , a , 0 ,  l1 ) ;

    int l2 = 0 ; 

    get_distance  ( root , b , 0 , l2 );

    cout << l1 + l2  << endl;

}








bool cycle_status =  false  ; 
void dfs( int src  , vector < vector < int > > &arr  , vector < bool > &visited  ,  int parent )
{
     visited  [ src ] = true ;

    for( auto it :  arr [ src ] )
    {
         if ( visited [ it ] == false )
         {
            dfs( it ,  arr , visited   , src ) ;
         }
         else if ( it != parent )
         {
             cycle_status = true;
         }
    }

}


bool check_for_tree ( vector< vector< int >  > arr,  int n  )
{
    vector < bool > visited ( n , false ) ;

    visited [ 0 ] =  true ;

    dfs (  0 ,  arr , visited , -1 ) ;

    for( int i  = 0 ; i < n ; i ++ )
    {
        if ( visited [i] == false || cycle_status == true)
        {
            cout <<"GIVEN GRAPH CANNOT BE CONVERTED INTO TREE"<< endl;
             return false ; 
        }
    }

    cout <<"GRAPH IS A TREE " << endl;

}

Node * get_left_max ( Node * root  )
{
    while ( root -> right != nullptr )  
    {
         root  = root -> right;
    }

    return root ; 

}
 

Node * delete_node( Node *root , int key )
{   
    if ( root == nullptr)
    {
         return  nullptr;
    }

    if( root -> data >  key )
    {
     root -> left = delete_node ( root -> left ,  key );
    }
    else if( root -> data <  key )
    {
        root -> right = delete_node ( root -> right , key ) ;
    }
    else 
    {  
        if( !root -> left and !root -> right )
        {
            delete root ;
            return nullptr;
        } 
        else if (!root -> left and root ->right )
        {
            Node *temp = root -> right ;

            delete  root ;

            return temp ;
        }

        else if ( root -> left and !root ->  right )
        {
            Node * temp = root -> left ;
            delete  root;
            return temp;
        }
        else 
        {   
            Node * left_max = get_left_max (  root -> left) ;
            
            swap ( root ->data  , left_max -> data );

            root -> left = delete_node ( root -> left  , key ) ;

        }
    }


}





int main()
{
    vector < int > arr = { 1 , 2 , 3 , 4,  5,  6 , 7 , INT_MAX, INT_MAX ,INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};

    // vector< int > arr = { 5, 6, 7, 8, 9, 10, 11 , INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};

    Node * root = build_tree  ( arr ) ;

    // inorder (root ) ;
    // level_order ( root ) ; 
    // reverse_level_order( root ) ;

    // mirror ( root ) ; 
    
    // inorder ( root ) ; 

    //  inorder_iterative (  root ) ;

    // preorder_recursive ( root ) ; 

    // post_opder_iterative ( root ) ; 

    // bottom_view  ( root ) ;  
    
    // diagonal_traversal ( root ) ; 

    // boundary_traversal ( root ) ; 

    // dll ( root );
    // iterate ( head ) ; 

    // vector< int> in = {1, 6 ,8, 7};

    // vector<int > pre = {1  , 6  , 7 ,  8 };

    // sum_tree ( root ) ;

    // inorder( root ) ; 

    // root = build_tree ( in, pre , 0 , 3 ) ; 

    // cout << root -> data <<  endl; 

    // inorder ( root ) ; 

    // min_swap ( root ) ; 

    // int  V  = 5 , e =  5 ;
    // vector < vector < int > > arr ( V ); 
    // for ( int i = 0 ; i < e ; i ++ )
    // {
    //     int u , v ;

    //     cin >>u >> v ;

    //     arr[u].push_back ( v ) ;

    //     arr[v].push_back ( u );

    // }

    // check_for_tree ( arr ,  V ) ; 

    // find_distance ( root ,  4 , 6 );


    return 0 ; 
}    