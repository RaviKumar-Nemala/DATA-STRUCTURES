#include<bits/stdc++.h>
using namespace std ;

int prec( char chr) 
{
     if( chr == '^') return 3 ;

     if ( chr=='*' or chr == '/')   return 2 ;

     if ( chr == '+' or chr == '-')  return 1 ;

     return -1;

}


void infix_to_prefix ( string str ){

     string res ; 

     stack < char > st ;

     for ( int idx = str.size ()  -1 ;  idx >= 0 ; idx -- )
     {
          char curr_char = str [ idx ] ; 

          char temp  = tolower( curr_char ) ;

          if( temp >= 'a' and temp <= 'z')
          {
               res += temp;
          }
          else if ( curr_char == ')')
          {
               st.push ( curr_char) ;
          }
          else if ( curr_char == '(')
          {
               while ( !st.empty() and st.top() != ')')
               {
                    res += st.top( ) ; 
                    st.pop();
               }
               st.pop();
          }
          else 
          {
               while( !st.empty() and prec( st.top()) >  prec(  curr_char) ) 
               {
                    res += st.top();
                    st.pop();
               }
               st.push ( curr_char );
          }

     }

     reverse( res.begin () , res.end () ) ;

     cout << res << endl;

}


int main ()
{
     string str =   "(x+(y*(z/w)))";

     infix_to_prefix ( str ) ; 

     return  0 ;
}