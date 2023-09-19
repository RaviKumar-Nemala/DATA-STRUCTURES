 class first{
     public int name=5;   
     void runner(){
          System.out.println("method is called");
     }
            public static void main(String[] arg){
          short t=99;
          int r=t;
          var k=66.5;
          boolean result=(t<k);
          if(result)
          System.out.println("t: " + t + "\t r: " +r + " " +result);
          var array=new int [3];
          array[0]=1;array[1]=2;array[2]=3;
          for(int var:array){
               if(var==3){
                    continue;
               }
               
               System.out.printf("%d ",var);
          }
          first obj_1=new first();          obj_1.name=0;
          obj_1.runner();
          System.out.printf("%d ",obj_1.name);
     }
}
