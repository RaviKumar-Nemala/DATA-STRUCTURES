class usermode
{

     
     public int sum ( int input1 , int [] input2)
     {

          int max_val = -1000000; 
          int min_val = 1000000;
          for ( int i = 0 ;i < input1 ; i++ )
          {
               int num =  input2[ i ] ; 
               if ( num < min_val )
               {
                    min_val = num ; 
               }
               if ( num > max_val )
                    {
                         max_val = num ;
                    }
          }
          return  ( min_val + max_val );
     }

     public int palindrome( String input1)
{


          int last = input1.length() -1;
          int first = 0 ;
          while ( first < last )
          {
               char  t = input1.charAt(first);

               char t1 = input1.charAt ( last );

               if ( t == t1)
               {
                    first++;
                    last--;
               }
               else
                    return 0;
          }
          return 1;


}




      static  public void main ( String args []) 
     {
          usermode obj  = new usermode();

          int arr [] = new int  [4 ];

          arr [ 0 ] = 9 ; 

          arr[ 1  ] = 5 ;

          arr [ 2 ]= 0 ;

          arr [ 3 ] = 11 ;

          System.out.println ( obj.sum(4 ,  arr) );


          System.out.println (obj.palindrome("heh" ) );

     }
}
