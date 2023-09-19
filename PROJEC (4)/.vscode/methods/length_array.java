class array_class{
     private int a[]=new int [10]; //uage of the private array//
void set_values(int i,int data){
     a[i]=data;
}
     int array_length(){ 
          return a.length;  //inbulid function // it returns full size of the array that the array can capable of////////////////
     }
     void load_array(int i,int data){
          a[i]=data;
     }
     void print(){   //cannot print without calling this method//
          for(int x: a)
          System.out.println(" "+x);
     }
}
public class length_array {
     public static void main(String[] args){
          var obj1=new array_class();
          obj1.set_values(0,1);
          obj1.set_values(1,2);
          obj1.set_values(2,3);
         obj1.print();
          System.out.println(" "+obj1.array_length());
     }
}
