#include<bits/stdc++.h>
using namespace std ;

void post_fix_evalution (string temp) 
{
     stack<int>st;

     int n = temp.size () ;
     int idx  = 0 ;
     while ( idx < n )
     {
          char curr_char = temp [ idx ] ; 

          if( curr_char == ' '){ idx ++; continue;};
     if ( curr_char >= '0' and curr_char <= '9'){
          string str = "";
          while( idx < n and  temp[ idx ] >= '0' and temp[idx] <= '9')
          {
               str += temp[idx];
               idx++;
          }    
          stringstream  stream( str );
          int value ;
          stream >> value ;
          st.push ( value );
          continue;
     }
     else 
     {
               int first_val = st.top  () ;

               st.pop ();

               int second_val = st.top ();

               st.pop();

               switch( curr_char )
               {
                    case '+':
                         st.push ( first_val + second_val) ; 
                         break;

                    case '-':
                         st.push ( first_val - second_val);
                         break;

                    case '*':
                         st.push(first_val * second_val);
                         break;                     

                    case '/':
                         st.push ( first_val / second_val);
                         break;
               }
          
          idx ++;
     }
}
     cout << st.top() << endl;
}


int main ()
{
     string str = "10 2 * 3 +";
     post_fix_evalution( str );
     return 0;
}