#include<bits/stdc++.h>
using namespace std ;

bool is_valiid_paranthesis( string str )
{
     stack<char > st ;

     for ( int idx = 0 ; idx < str.size () ; idx ++ )
     {
          char curr_ele = str [ idx ] ; 

          if( curr_ele == ')' or curr_ele == '}'  or curr_ele == ']' )
          {    
                    if ( st.empty ()) 
                    {
                         return false;
                    }
                                       
                    char top_ele = st.top (); 

               if ( curr_ele == ')'  and top_ele == '(')
               {
                    st.pop();
               }
               else if ( curr_ele ==  ']' and top_ele == '[')
               {
                    st.pop();
               }
               else if ( curr_ele == '}' and top_ele == '{')
               {
                    st.pop();
               }
               else 
               {
                    return false;
               }
          }

          else 
          {
               st.push ( curr_ele);
          }
     }
     return true;
}


int main ()
{

string str = "([])";
str = "(([}))";
str = "(([)])";
str = "][";
cout <<is_valiid_paranthesis ( str )<< endl;
return 0;
}