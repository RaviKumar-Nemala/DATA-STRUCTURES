public class second {
    private int c;
    private boolean result(int a,int b) { 
         if(a>b){
             System.out.println("TRUE");
             this.c=44;
             System.out.println(" " +c);
             return true;

         }
         else{
         System.out.println("FALSE");
         return false;
         }
}
public static void main(String[] args){
     second obj1=new second();
     obj1.c=33;
     System.out.println(" " +obj1.c);
     boolean result=obj1.result(2,3) ;
     if(result){
          System.out.println("success");
     }
     else{
          System.out.println("fail");
     }

}
}
