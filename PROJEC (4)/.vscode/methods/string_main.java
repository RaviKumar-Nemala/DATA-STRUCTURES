
public class string_main {
     public static void main(String[] args){
         String obj1="ravi kumar";
         String obj2="ravi kumar";
          boolean result=false;
          result =obj1.equals(obj2); //strings inbuild functions//
System.out.println(" "+result);
System.out.println(" "+obj1.charAt(3)+ " " +obj1.length());

//striig array//
String str[]={"ravi ","kumar","nemala"};
boolean i= str[0].equals(str[1]);
System.out.println(" "+i);
 i= str[0]!=str[1];
 System.out.println(" "+i);
 System.out.println(" "+str[0].charAt(2));
     }
}
