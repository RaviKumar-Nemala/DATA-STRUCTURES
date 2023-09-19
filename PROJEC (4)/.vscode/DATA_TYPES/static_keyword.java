class static_class{
     static int i;
     static int returner( int static_variable){
          static_variable=i;
          return static_variable++;
     }
}

 class static_keyword {
     public static void main(String[] args){
     static_class tester=new static_class();
     static_class.i=3;
         System.out.println(" "+static_class.i);
         System.out.println(" "+static_class.i);
}
}
