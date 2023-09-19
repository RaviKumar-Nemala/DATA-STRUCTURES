class constructor_field_class {
     int height;
          int width;
          int length;
           double volume;
          void volume_finder(){
               volume=height*width*length;
               System.out.println("  "+volume);
          }
          //building own constructor //
     constructor_field_class(){
          height=10;
          width=10;
          length=10;
     }
}
class constructor_main{
     public static void main(String[] args){
         constructor_field_class obj1=new constructor_field_class();
         obj1.volume_finder();          //calling constructor (); //
     }
}


