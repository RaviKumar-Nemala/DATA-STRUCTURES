import java.math.BigDecimal;
class total_calculator {
     BigDecimal number1;
     BigDecimal number2 ;
     BigDecimal number3 ;
total_calculator(){
          number1= new BigDecimal("1.656");
          number2 = new BigDecimal("2.665");
          number3=new BigDecimal("3");
          
     }
     void total(){
          BigDecimal total = number1.add(number2).add(number3);
          //1+2+3//
          System.out.println("PRINTING TOTAL SECTION : "+total);
     }
     void multiply(){
          BigDecimal multiplier=number1.multiply(number2).add(number3);
          //1*2+3//
          System.out.println("PRINTING multiplier SECTION " + multiplier);
     }
}
public class big_data_types{
     public static void main(String[] args){
     total_calculator obj1= new total_calculator();
     obj1.total();
     obj1.multiply();
     }
     
}
