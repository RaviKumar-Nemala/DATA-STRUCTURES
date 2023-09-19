
public class scope_of_variable {
     public static void main(String[] args) {
          int a=99; //variable is visible to the main method//
          if(a==99){ //if(a) does not work here we need to specify clearly//
               int if_block_variable=88;
               System.out.println("PRINTING if block the varialble " +if_block_variable);
          }
          System.out.println("PRINTING the if bolck variable from out side of the if block throwing the error");
     }
}
