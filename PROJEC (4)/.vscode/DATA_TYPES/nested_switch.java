public class nested_switch {
     public static void main(String[] args) {
     int number=1;
     int range=10;
     switch(number){
          case 1:
          switch (range){
          case 1:
          System.out.println("number is found");
          break;
          }
          default :
          System.out.println("inner switch condition is failed \n executing outer switch  "); 
     }
     System.out.println("USING SWITCH USING ITERATIVE TECHNIQUE");
     for(int i=1;i<=5;i++)
     switch(i){
          case 1:
          System.out.println("i value is one ");
          break;
          case 2:
          System.out.println("i value is two");
          break;
          case 3:
          System.out.println("i value is three");
          break;
          case 4:
          System.out.println("i value is four ");
          break;
          case 5:
          System.out.println("i value is five ");
          break;
     }
}
}
