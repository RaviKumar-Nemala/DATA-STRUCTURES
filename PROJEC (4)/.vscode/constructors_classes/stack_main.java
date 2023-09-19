 class stack_class {
     private int a[]=new int[10];
     private int top;

     void set_top(){
          top=-1;
     }
     boolean is_full(){
          if(top==9)
          return true;
          else
          return false;
     }
     boolean is_empty(){
          if(top==-1)
          return true;
          else return false;
     }
     void push(int data){
          if(is_full()){
               System.out.println("STACK IS FULL");
          }
          else{
               a[++top]=data;
          }
     }
     int  pop(){
          if(is_empty()){
               System.out.println("STACK IS EMPTY");
               return 0;
          }
          else {
          return a[top--];
     }
}
 }
class stack_main{
     public static void main(String[] args){
          int item;
          stack_class obj_1 =new stack_class();
          //obj_1.top=5;
          for(int i=0;i<5;i++){
               obj_1.push(i);
          }
          for(int i=0;i<5;i++){
                item=obj_1.pop();
                System.out.print(" " +item);
     }
     
}
}
