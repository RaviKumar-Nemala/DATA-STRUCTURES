 #include<bits/stdc++.h>
 using namespace std ;
long long  fun(  long long arr[]  , int n ){
 long long max_val =0;
        
        stack < long  long > st ;
        
        for( int idx = 0 ; idx < n   ; idx ++ )
        {
            
            while ( !st.empty () and arr [ idx ] < arr [ st.top () ] ) 
            {
                
                int top_idx = st.top ( );
                
                st.pop ();
                
                long  long  val =  arr [ top_idx ] * ( st.empty() ? idx : idx - st.top () -1 );
                
                max_val = max( max_val , val ) ; 
                
            }
            
            st.push ( idx ) ;
        }
        
        
        while ( !st.empty() ) 
        {
            int top_idx = st.top () ;
            
            st.pop ();
            int x = 0 ; 
            if( st.empty () )
            {
                x = n ;
            }
            else
            {
                x =  n -  st.top () -1 ;
                
            }
            
            long long val =  arr [ top_idx ] * x; 
            
            max_val  = max( max_val,  val ) ; 
            
        }
        
        return max_val ; 
 }