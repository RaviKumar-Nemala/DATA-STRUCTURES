class stack_class{
     char names[]=new char [5];
     int top;
     char item;
     stack_class(){
          top=-1;
     }
     boolean is_full(){
          if(top==4)
          return true;
          else
          return false;
     }
     boolean is_empty(){
          if(top==-1)
          return true;
          else return false;
     }
     void push(char item){
          if(is_full()){
               System.out.println("STACK IS FULL");
          }
          else{
               names[++top]=item;
          }
     }
     char pop(){
          if(is_empty()){
               System.out.println("STACK IS EMPTY");
          }
          else {
          item=names[top--];
          }
          return item;
     }
}
 class stack {
     public static void main(String[] args){
          int i;
          char j;
          stack_class stack1=new stack_class();
          for(j=67;j<71;j++){
               stack1.push(j);
          }
          for(i=0;i<4;i++){
               char item=stack1.pop();
               System.out.println("  "+item);
          }
     }
}
