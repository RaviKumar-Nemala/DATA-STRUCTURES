public class for_each_loop {
     public static void main(String[] args) {
          int  a[]={1,2,3,4,5};
          // syntax of for each is /
          //datatype variable name : array varaible name//
          for(int  x:a){
               System.out.printf("\t "+x);
          }
          //using local variable inference in for-each is valid//
          for(var y:a){
               if(y==1){
                    System.out.println("\nfor each is working properly");
               }
          }
     }
}
