import java.util.*;

class Student{
String name;
     int marks[];
     int average_marks;
     int sum ; 
     int highest_marks;
     int least_marks;
     Student ( String name  , int arr[] )
     {
          marks = arr;
          this.name  = name;
     }
     int get_max_marks()
     {
         // return Math.max(arr);
         int max_val = 0;
          for( int i : marks)
          {
               if( max_val < i )
               max_val = i;
          }
          return max_val;
     }
     float average_marks (  )
     {
          int sum =0;
          for( int i : marks)
          sum+=i;
          return (sum/marks.length);
     }
     
     int least_marks () {
          int max_val = 554544;
          for( int i : marks)
          {
               if( max_val > i )
               max_val = i;
          }
          return max_val;
     }
}
public class array_3
{
     public static void main(String args[])
     {
          int marks[] = { 1,2,3};
        Student student = new Student("ddos" , marks);
        float avg_marks = student.average_marks() ;
        System.out.println("average marks : ");
        System.out.println(avg_marks);

        System.out.println("MAXIMUM MARKS : ");
        int max_marks =  student.get_max_marks();
        System.out.println(max_marks);

        System.out.println("LEAST marks : ");
          System.out.println(student.least_marks());

     }

}