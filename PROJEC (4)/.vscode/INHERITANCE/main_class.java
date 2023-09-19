  
  class super_class{
     private float salary;
     private float bonus;
     private String employee_name;
     void set_employee_name(String employee_name){
          this.employee_name = employee_name;
     }
     super_class(){
          salary=400;
          bonus=0;
     }
     void  set_salary_and_bonus(float salary, float bonus){
          this.salary = salary;
          this.bonus = bonus;
     }
     super_class(float salary){
          this.salary=salary;
     }
     super_class(float salary,float bonus){
          this.bonus=bonus;
          this.salary = salary;
     }
     void employee_status(){
          System.out.println("\t NAME:  " +employee_name +" \tSALARY : "+salary + "\tBONUS : "+bonus+ " ");
     }
      void get_salary(){
           System.out.println("\n SALARY : "+salary);
     }
}
      class inheritance1 extends super_class{
     
   private  String student_name;
  void  set_student_name(String student_name){
        this.student_name = student_name;
   }
   String get_student_name(){
     return student_name;
   }
        super_class obj1= new super_class();
     void get_salary(){
     super.get_salary();
     }
     inheritance1(){
         super();
     }
          inheritance1(float salary){
          super(salary);
     }
     inheritance1(float salary,float bonus){
          super(salary, bonus);
     }
    void  employee_name(String employee_name){
          super.set_employee_name(employee_name);
     }
     void details(){
          super.employee_status();
     }
     void set_salary(float salary,float bonus){
     super.set_salary_and_bonus(salary, bonus);
      }
     }
 class inheritance2 extends inheritance1 {
      
     void send_student_name(String name){
          super.set_student_name(name);
     }
    String  receive_student_name(){
         String temp=super.get_student_name();
         return temp;
     }
}
public class main_class{
     public static void main(String[] args){
         inheritance1 obj=new inheritance1(5,4);
         inheritance1 obj2=new inheritance1();
         obj2.set_salary_and_bonus(22,44);
         obj2.employee_name("RAVI KUMAR");
         obj.employee_name("KUMAR");
        obj.set_student_name("CSE STUDENT");
        String temp=obj.get_student_name();
        System.out.println(temp);
         obj.details();
         obj2.details();
         obj2.get_salary();
         inheritance2 new_obj= new inheritance2();
         new_obj.send_student_name("NO NAME");
         System.out.println(" "+new_obj.receive_student_name());
         new_obj.set_employee_name("NO EMPLOYEE");
         new_obj.details();
     }
}
