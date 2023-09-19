public class switch_cases {
  public static void main(String[] args) {
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

       int number=2;
       switch(number){
            case 1:
            case 2:
            System.out.println("number may be 2 or lesser than 2");
            break;
            default:
            System.out.println("number is greater than 2");
            break;
       }
       //using arrays with switch //
       int a[]={1,2,3};
       switch(a[2]){
          case 1:
          case 2:
          System.out.println("number may be 2 or lesser than 2");
          break;
          default:
          System.out.println("number is greater than 2");
          break;
       }
  }   
}
