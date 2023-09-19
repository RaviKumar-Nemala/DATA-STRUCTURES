
    class sum_of_devisors{
          void Sum_Of_Devisors_upto_n(int n){
               int i;
               int sum=0;
               for(i=1;i<=n;i++){
                    if(n%i==0)
                    sum+=i;
               }
               System.out.println(" " +sum);          
          }
     }

