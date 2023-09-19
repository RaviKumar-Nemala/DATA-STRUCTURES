 class box {
          int height;
          int width;
          int length;
           double volume;
          void volume_finder(){
               volume=height*width*length;
               System.out.println("  "+volume);
          }
     }
            class Box_obj{
               public static void main(String[] args){
                    box box1=new box();
                    box box2=new box();
                    box1.height =10;
                    box1.length=10;
                    box1.width=10;
                    box1.volume_finder();
                    box2.height =20;
                    box2.length=20;
                    box2.width=20;
                    box2.volume_finder();
               }
          }

