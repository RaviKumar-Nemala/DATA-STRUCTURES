
public class char_demo {
     public static void main(String[] args) {
          char a='A';
          char b='B';
          int c=a;  //ALL CHAR AND SHORT ARE PROMOTED TO INT DURING THE EVALUTION TIME//
          int d=b;
          short e=(short)d;//converting int to short //
          int  range=65538;
          short convert=(short)range;
          double double_value=44.4;
          System.out.println(" ACTUAL DOUBLE VALUE : " +double_value);
          short double_to_short_converter=(short)double_value;
          System.out.println("AFTER CASTING DOUBLE FORM SHORT "); 
         System.out.println("double_value: " +double_to_short_converter);
          System.out.println("range: " + range + " short value : " +convert);
          System.out.printf("a= %d \t b=%d ",c,d);
         System.out.println("a= " +a + " b= " +b);
          System.out.println("e= "+e);
     }
}
