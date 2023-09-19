#include<bits/stdc++.h>
using namespace std ;

 

struct  node
{

     int val ; 

     struct node *left ;

     struct node *right ;

     node ( int data )
     {
          this -> val = data ;

          this -> left = nullptr ;

          this -> right = nullptr ;
     }

};

stack< node * > st; 

void inorder_util ( node * root )
{

    

     while ( true )
     
     {

          if  ( root != nullptr )
          {
               st.push ( root  ) ;

               root = root  -> left ;

          }
          
          else{

               if ( st.empty () )
               {

                    break;

               }

               root = st.top () ;

               st.pop ( ) ;

               cout << root -> val << " " ;

               root = root -> right;

          }



     }



}


void inorder( node * root )
{

     if ( !root)
          return ;

     inorder ( root -> left ) ;

     cout << root -> val << endl;

     inorder( root-> right ) ;


}

void print_val ( stack < node *>  st )
{

     while ( !st.empty() )
     {

          cout << st.top() -> val << " ";

          st.pop ();

     }


}
void postorder_util ( node *root )
{

     st.push ( root );
     
     stack< node *> st2; 

     while ( !st.empty() )
     {

          node * root = st.top  () ;

          st.pop() ;

          st2.push ( root );

          if ( root -> left)
          {
               st.push ( root -> left );

          }

          if ( root -> right )
          {

               st.push ( root-> right ) ;
          }    

     }

     print_val( st2);

}

void preorder_util ( node * root )
{

     st.push ( root );

     while ( !st.empty() )
     {

          root =  st.top();

           cout << root -> val <<" ";

          st.pop();

          if( root -> right)
          {
               st.push ( root-> right) ;

          }

          if( root->left)
          {
               st.push ( root-> left );
          }

     }

     return;

}



void util ( string str )
{

     unordered_map < char , int > mp ;

     for ( auto it : str ) 
     {
          if ( it == ' '){
               continue;
          }
          if ( mp.find ( it ) != mp.end () )
          {
          
               cout << it << endl ;

               break;
          
          }

          else
          {

               mp [ it  ]++;

          }

     }


}


void print_map ( unordered_map < int  , node * >  ) ;

void bottom_view ( node * root)
{


     unordered_map <  int , node * > mp ;


     queue < pair < int, node  * > >   q ;

     q.push (  { 0 , root } ) ;


     while( !q.empty ( ) )

     {

          

          int hd = q.front() .first ;

          node* curr_node = q.front().second ;

          q.pop() ;

          mp [ hd ] = curr_node ;

          if( curr_node -> left )
          {

               int left_node_hd = hd -1 ;

               q.push (  { left_node_hd , curr_node-> left} ) ;

          }

          if( curr_node-> right ) 
          {

               int right_node_hd  = hd + 1 ;

               q.push (  { right_node_hd , curr_node -> right} ) ;

          }

     }


     print_map ( mp );



}



void top_view ( node * root )
{



unordered_map < int , node* >  mp ;

queue< pair < int ,  node *>  > q ;



q.push ( make_pair(  root -> val , root));


while (!q.empty () )
{

     node *curr_node = q.front ().second  ;

     int node_val = curr_node -> val ;

     int hd = q.front().first ;

     q.pop ();

     if  ( mp.find ( hd )  == mp.end () )
     {
     
          mp[  hd ] =  curr_node ;

     }
    

     if ( curr_node -> left )
     {
          int left_node_hd = hd - 1;

          q.push ( make_pair ( left_node_hd  , curr_node->left ) ) ;
     
     }

     if ( curr_node -> right)
     {

          int right_node_hd = hd + 1 ;

          q.push ( make_pair ( right_node_hd  , curr_node -> right ) ) ;

     }

}

print_map ( mp );

}


void print_map (  unordered_map < int ,  node  * >  mp )
{

     for ( auto it: mp )
     {    
          int hd = it.first  ;

          cout << it.second->val << " ";

     }



}


bool is_odd ( int val )
{

     return ( val % 2 != 1 )? true :  false;

}

void print_val ( vector < int > nodes )
{

     for ( auto it: nodes )
     {
          cout  << it << "  ";
     }

     return ;

}

void zig_zag ( node * root )
{


     vector < int > res ; 

     queue< node  * > q ;

     q.push  ( root );

     int odd_level = false; 

     while (  !q.empty ()  )
     {

          int n = q.size() ;

          vector < int > nodes ;

          for ( int i  = 0 ; i < n ; i ++ )
          {


          node  * curr_node = q.front ()  ;

          nodes.push_back ( curr_node ->val ) ;
          
          q.pop ( ) ;

          if ( curr_node -> left )
          {

               q.push ( curr_node -> left ) ;

          }

          if( curr_node -> right )
          {
               
               q.push ( curr_node -> right ) ;

          }


     }


     if  ( odd_level )
     {
          
          reverse  ( nodes.begin () ,  nodes.end() ) ;

     }

     odd_level = !odd_level ;

     for ( auto it : nodes )
     {
          
          res.push_back ( it ) ;

     }

}

print_val ( res ) ;

}


void  diagonal ( node * root )
{

     if ( !root ) 
     {

          return ; 

     }

     queue < node  * > q ;

     q.push ( root ) ;

     while ( !q.empty () )
     {

          node *curr_node = q.front ()  ;

          q.pop ( );

          while ( curr_node ){

               cout << curr_node -> val << " " ;

          if ( curr_node -> left ) 
          {
               
               q.push ( curr_node -> left ) ;

          }

          curr_node = curr_node -> right ;

     }
     }

}


vector < int > nodes ; 


vector < int >  res ;


bool isLeaf ( node  *root )
{    

          if ( root and !root-> left and !root-> right )
               return true;
          else
               return false;
}  
void addLeaves ( node * root)
{

     if (!root )
     {
          return;
     }

     if ( isLeaf ( root ) )
     {
          
          res.push_back ( root -> val ) ; 

          return ;

     }

     addLeaves   ( root -> left ) ;

     addLeaves ( root -> right ) ;


}

void left_boundary   ( node * root )
{


     if (!root )
          return ;  

     node *curr_node = root ; 
     
     while( curr_node )
     {

     if ( !isLeaf ( curr_node ) ) 
     {
          res.push_back (     root-> val ) ;

     }

     if( curr_node -> left )
     {
          
          curr_node = curr_node -> left ;

     }
     else
     {
          curr_node = curr_node ->right;
     }


}

}


void right_boundary ( node  * root )
{

     if ( !root )
     {

          return ;

     }

     node *curr_node = root ;

     while( curr_node )
     {

          if( !isLeaf ( curr_node) ) 
          {
               res.push_back  ( curr_node -> val ) ;
          }
          if ( curr_node -> right )
          {
               curr_node = curr_node -> right;

          }

          
          else{
          curr_node = curr_node-> left;
           }
     }

}


node * buildTree (  string s ,  int *start_idx )
{

     if ( *start_idx >= s.length() )
     {
          return nullptr;
     }
     
     bool negative = false;

     if ( s [  *start_idx ]  == '-' )
     
     {
          
          negative = true ;

     }
     
     *start_idx  = *start_idx + 1 ;



     int total =   0;

     int  t =  s [ *start_idx ] - '0' ;

     while  ( *start_idx < s.length() and  isdigit ( t ) )
     {
     
          char ch = s [ *start_idx ] ;

          int digit = ch - 97;

          cout << digit <<"  " ;
          total = (total * 10) + digit ;     

          *start_idx  =  *start_idx +  1 ;


     }

     int node_val = total ;

     if ( negative ){
          node_val = -node_val ;
     }

     cout << node_val << "  " ;

     node * root = new node  ( node_val ) ;

     if ( *start_idx >= s.length() )
     {
          return root;
     }
     if( *start_idx < s.length ()  and  s [ *start_idx ] =='(')
     {
          
         *start_idx   = *start_idx + 1 ;

          root -> left =  buildTree (  s , start_idx ) ;

     }

     if ( *start_idx < s.length () and s [  *start_idx ] == ')' )
     {

          *start_idx  = *start_idx + 1 ;

          return root;

     }    

     if ( *start_idx < s.length () and s [ *start_idx ] == '(')
     {
          
          *start_idx  = *start_idx + 1 ;

          root -> right = buildTree ( s , start_idx ) ;

     } 

     if ( *start_idx < s.length () and s [ *start_idx ] == ')')
     {

         * start_idx  = *start_idx + 1 ;

          return root;

     }

}


int main () 

{

     node * root = new node ( 1  ) ;


     root -> left = new node ( 2 );

     root -> right =  new node ( 3 );

     root -> left -> right = new node ( 4 ) ;

     root -> left -> left = new node ( 5 ) ;

     root -> right -> left = new node ( 6 );
     
     root -> right -> right = new  node( 7 );


     //inorder_util ( root ) ;

    // preorder_util(root);

   // postorder_util ( root );
    // util ( "geek for geeks ");

    //top_view ( root ) ;

    // bottom_view ( root );

    // zig_zag ( root ) ;

    // diagonal ( root );

   //  res.push_back ( root -> val ) ;

     //left_boundary ( root -> left ) ;

     //addLeaves  ( root );
     
     //right_boundary ( root -> right );
     
    

     //print_val  (  res ) ;

     string t = "4(2(3)(1))(6(5))";
     
     int idx = 0  ;

     node* temp = buildTree ( t   , &idx ) ;

     inorder ( temp );

     return 0 ; 

}