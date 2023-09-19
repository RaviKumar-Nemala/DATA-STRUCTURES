class variables{
     static final int constant_value_pi =3;
     static final char colour='c';
     static void manupulate(int a){
          //constant_value_pi =a; //it throws error cannot assing value to constant final variable //
     System.out.println(" "+ constant_value_pi);
     }
}

public class final_variables {
     public static void main(String[] args){
variables obj1=new variables();
System.out.println(" " +variables.constant_value_pi);
}
}



