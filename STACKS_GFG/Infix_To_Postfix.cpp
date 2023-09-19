#include<bits/stdc++.h>
using namespace std ;

int prec( char ch ) 
{
     if ( ch == '^')     return 3;

     if ( ch == '/' or ch == '*') return 2 ;

     if ( ch == '+' or ch =='-') return 1 ;

     return -1;
}

bool is_operand( char ch ) 
{
     ch = tolower(ch);
     if(ch >= 'a' and ch <= 'z')   return true;

     return false ;
}

void infix_to_postfix ( string str ) 
{
     string res;

     stack<char > st  ;

     for ( int idx = 0 ; idx < str.size() ; idx ++ ) 
     {
          char curr_char = str[ idx ] ;
          
          if( curr_char == ' ' )  continue; 

          if ( is_operand ( curr_char ))
               res += curr_char ;

          else if ( curr_char == '(')
          {
               st.push ( curr_char );
          }     
          else if ( curr_char == ')' )
          {
               while( !st.empty() and st.top () != '(')
               {
                    res += st.top ();
                    st.pop();
               }
               st.pop();
          }
          else 
          {
               while ( !st.empty() and prec( st.top() ) >  prec( curr_char ) )
               {
                    res += st.top ();
                    st.pop();
               }
               st.push ( curr_char);
          }
     }

     while ( !st.empty())     
     {
          res += st.top ();
          st.pop();
     }

     cout <<"POST FIX = " << res<< endl;

}

string make_brackets( string str)
{    
    stack <char > st;
     string res ; 
     int idx = 0 ;
     bool op_status = false; 
     for ( idx = 0 ; idx < str.size () ; idx ++){
          char curr_char = str [ idx ] ; 

          if( curr_char == '+'  or curr_char =='-' or curr_char =='/'  or curr_char == '*')
          {
               if( st.empty() ) {
                    res += curr_char; 
               }
               else if( op_status) 
               {
                    string str2  = "";
                    while ( !st.empty() ) 
                    {    
                         str2 = st.top() + str2;
                         st.pop(); 
                    }
                    str2 ='(' + str2 + ')';
                    // cout << str2 << endl ;
                    op_status  = false ;

                    res += str2 ;  
                    res += curr_char;
               }
               else{
                    st.push( curr_char );
                    op_status  = true;
               }
               
          }
          else {
          char temp  = tolower( curr_char );

          if ( temp >= 'a' and temp <='z')
          {
               st.push ( curr_char ) ;
          }
          }
}

     string str2 = "";
     while ( !st.empty( ) ) 
     {
          str2  = st.top () + str2 ;
          st.pop();
     }
     str2 = '(' + str2 + ')';
     res += str2;
     cout<< endl << res << endl;
     // cout << str2 << endl;

}

int main ()
{
     // string str = "(a/b)+(b*c)"; 

     string str = "a+b*(c^d-e)^(f+g*h)-i";

     infix_to_postfix ( str) ;
     // str = "a/b+b*c";
     //make_brackets(str);

 
 
     return 0 ;
}