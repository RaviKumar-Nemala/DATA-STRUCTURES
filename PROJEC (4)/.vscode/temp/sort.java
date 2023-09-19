 class sort {
     public static void main(String[] args){
          char a[]={'r','a','v','i'};
          int i,j;
          int k;
          char temp;
          char key;
          for( i=1;i<4;i++){
               j=i-1;
               key=a[i];
               while(a[j]>=key&&j>=0){
                    
                    a[j+1]=a[j];
                    j=j-1;
                    }
                    a[j+1]=key;
               }
          for(k=0;k<4;k++){
               System.out.println(" " +a[k]);
          }
     }
}

