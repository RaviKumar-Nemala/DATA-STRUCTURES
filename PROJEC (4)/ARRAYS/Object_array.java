
class Student{
     String  name ;
     int marks; 
     Student( String name , int marks )
     {
          this.name =  name ; 
          this. marks = marks; 
     }

     void print()
     {
          System.out.println("PRINTING THE STUDENT DATA : " );
          System.out.print("NAME : " + name + " " + "MARKS : " + marks);
          System.out.println();
     }
}



public class Object_array {

     public static void main(String args [] )
     {
          Student student[] =  new Student[4];
          student[0] = new Student("first " ,  1 );
          student[1] = new Student("second person" , 2);
          student[2] =  new Student("third person afajf afjfaj alfj", 3 );
          student[3] =  new Student("fourth ", 4 );
          
          for(int i = 0 ; i < student.length ; i ++)
          {
               student[i].print();
          }
          
          
          //USING STRING ARRAYS //
          String str[] =  new String[5];
          str[0] = "sunday";
          str[1] = "monday";
          str[2]=   "tuesday";
          str[3] = "wednesday";
          str[4] = "thursday";
          int  n = str[0].length();
          String max_string = " ";
          for ( int i =  0  ; i < str.length ; i++)
          {
               if(max_string.length() < str[i].length() ) //IN STRING LENGTH FUNCTION REQUIRES SYNTAX LIKE THIS str[0].length()//
               max_string  =  str[i];
          }
          System.out.println("PRINTING THE MAX STRING   : " + max_string);
     
     //IN STRING LENGTH FUNCTION REQUIRES SYNTAX LIKE THIS str[0].length()//
     
     //in case of norml array it is like this//
     int arr[][] = new int[3][5];
     int row =  arr.length;
     int col = arr[0].length;
     System.out.println("rows : " + row  + "  colms : " + col );
}
}

