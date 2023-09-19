class static_demo{
     static int i=99;
     static int j; //if we need to assign a computed value to the static 
     int main;      //block then we need to use static block //
     static {
          j=i*2;
          System.out.println(" "+j);
     }
     static void computer(int main){
          this.main=main;
          System.out.println("PRINTING THE I AND J VALUE :  "+main);
          System.out.println("PRINTING THE I AND J VALUE :  "+(i+j));
     }
}
public class static_method {
     public static void main(String[] args) {
          int a=99;
          static_demo.i=99;
          System.out.println(" " +static_demo.j);
          static_demo.computer(55); //we can call static methonds using the classname.//
           static_demo obj1=new static_demo(); //we can also use objects//
           obj1.computer(5);
     }
}
