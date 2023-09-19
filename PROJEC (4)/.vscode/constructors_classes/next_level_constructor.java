
class constructor_class_field{
     int height;  //these variables are called instance variables//
     int width;
     int length;
      double volume;
     double volume_finder(){
          volume=height*width*length;
          return volume;
     }
constructor_class_field(int height, int width, int length){
      //the parameters inside this are local variables //
      //if local and instance variables are using same name //
      //then we use this key word to emphasize the instance variables //
          this.height = height;
          this.width = width;
          this.length = length;
}
}
class next_level_constructor{
     public static void main(String[] args){
          int lenght=1;
          int width =2;
          int height =3;
          double volume;
          constructor_class_field obj1=new constructor_class_field(height,width,lenght);
         volume= obj1.volume_finder();
         System.out.println("volume of the first object is  "+volume);
          //another way without using variables////////////////
constructor_class_field obj2=new constructor_class_field(5,5,5);
//in this case we uses hard coded values////////////////
     volume=obj2.volume_finder();
     System.out.println("volume of the 2nd object is  "+volume);
     }
}
