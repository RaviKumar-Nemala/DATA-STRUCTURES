 class sum_upto_n_util{
     private int n=0;
     private int sum=0;
           void sum_of_n_terms(int n){
               this.n=n;
          for(int i=1;i<=n;i++){
               sum+=i;
          }
          System.out.println("sum up to " +n  +" is " + sum);
          for(int i=1;i<n;i++){
               for(int j=1;j<=i;j++){
               System.out.print(" " +j);
          }
          System.out.println();
     }
}
}


public class sum_upto_n {
      public static void main(String[] args) {
          //sum_upto_n_util obj= new sum_upto_n_util();
         // obj.sum_of_n_terms(10);
         sum_of_devisors devisor= new sum_of_devisors();
        devisor.Sum_Of_Devisors_upto_n(10);
     }
}
