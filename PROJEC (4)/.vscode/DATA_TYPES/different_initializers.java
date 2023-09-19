
public class different_initializers {
     //initializing values the variables using binary digits//
     /**
      *
      */
      public static void main(String[] args){
      int a = 0B1000;//binary 4 digit representation//
      System.out.println("a = "+a);
      int b=0B1000;
      int d=07;//declaring ocatl value we need to specify a zero before it//
      //OCATL VALUE RANGE -00 - 07 // 
      int e=0x23;
      //declaring the hexa decimal value //
      System.out.println("d = "+d +"e= "+e);
      System.out.println("b = "+b);
      System.out.println("(a+b) value: "+ (a+b));
     int c=444_554_889; //this representation is also valid //
     System.out.println("c = "+c);

}
}
