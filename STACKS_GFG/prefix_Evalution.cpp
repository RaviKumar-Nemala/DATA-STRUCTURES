#include<bits/stdc++.h>
using namespace std  ; 
 

int get_eval_val ( string str ) 
{ 
     stack < int  > st;       
     int idx = str.size () -1 ; 
     string temp ="";
     while( idx >=0)
     {
          char curr_char =  str[ idx] ; 

          if ( curr_char >= '0' and curr_char <= '9'){
               temp ="";
          while ( idx >=  0  and str[ idx ] >='0' and str [ idx ] <= '9' )
          {
               temp = str[ idx ] + temp;
               idx --;
          }
               stringstream stream (temp);
               int value ; 
               stream >> value;
               // cout << " val  = " << value << endl; 
               st.push ( value ) ; 
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

               idx --;

          }
          idx --;
          
          // cout << st.top () << endl;

     }

     cout << st.top()<< endl;
}


int main ()
{
     string str  ="* / 2 2 4";
     get_eval_val( str ) ;
     return 0 ;
}