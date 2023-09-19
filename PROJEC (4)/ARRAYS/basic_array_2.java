import java.lang.reflect.Array;
import java.util.*;
public class basic_array_2 {
     
public static void main(String args[] )
{
     int arr[] = new int [5];//default initialization is 0 in the array//
     //assigning the array values to 100 using FILL FUNCTION//
     Arrays.fill(arr ,  100 );
     System.out.println(Arrays.toString(arr));

     //assinging the 50 to all array values//
     Arrays.fill(arr,  50);

     System.out.println(Arrays.toString(arr));

     //COMPARE FUNCTIO IS USED TO COMPARE TWO ARRAYS//
     int test_1 [] = {1,2,3};
     int test_2 [] = {1,2,3};

     if(Arrays.equals(test_1, test_2))
     System.out.println("true");

     else
     System.out.println("true");

     
     //SORT FUNCTION IS USED TO SORT THE ARRAY//
     int sort_test[] = { 5,4,3,2,1 };
     System.out.println("printing the before the sorting : " + Arrays.toString(sort_test));
     Arrays.sort(sort_test);
     System.out.println("printing after the sort : ");
     System.out.println(Arrays.toString(sort_test));

}    

}

