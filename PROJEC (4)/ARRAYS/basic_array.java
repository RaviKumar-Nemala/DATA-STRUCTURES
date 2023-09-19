import java.util.*;
public class basic_array {
     public static void main(String args[])
     {
          //BASIC ARRAY INITIALIZATION//
          int arr[] = new int[3];
          arr[0] = 1 ;
          arr[1] = 2 ;
          arr[2] = 3;
          for ( int i : arr )
          System.out.println(i);


          //ANOTHER WAY OF INITIALIZATION //
          int ddos[] = { 1,2,3,4,5};

          for ( int i : arr )
          System.out.println(i);


          //WHEN WE WANT OT ACCESS THE ARRAY ELEMENT WHICH IS IN OUT OF INDEX IT THROWS THE ARRAY INDEX OUT OF BOUND EXCEPTION//
          /*
          int test[] = {1,2,3};
          
          int result =  test[3];
          System.out.println(result);
          */
         // Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 3 out of bounds for length 3
          

         //INSTEAD OF USING FOR EACH FOR PRINTING THE ARRAY ELEMENT WE SIMPLY USE TO STRING METHOD DIRECTLY //

         int test_2[] = {1,2,3};
         System.out.println(test_2);//it gives the memory address of the array 
         System.out.println(Arrays.toString(test_2)); //IT USED TO PRINT THE ARRAY VALUES //

     }

}
