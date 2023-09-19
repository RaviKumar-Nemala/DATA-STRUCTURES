
class vehicle{
      int wheels;
      private String key_decreptor;
      private float fuel_max_range;
      private int vehicle_sitting_capacity;
      private int  no_of_seats;
     int speed=0; 
     float fuel_max_range;
     public void set_fuel_max_range(){
          fuel_max_range = 10;
     }
     public void setspeed() {
          speed=99;
     }
     void current_speed(){
          System.out.println("CURRENT SPEED IS "+speed);
     }
      void is_fuel_empty(float current_fuel){
          if(fuel_max_range==current_fuel){
               System.out.println("CAR IS FULL OF FUEL ");
          }
          else if(current_fuel==0){
               System.out.Println("NO FUEL");
          }
          else{
               System.out.Println("CAR HAS LIMITED FUEL");
          }
     }
     void vehicle_petrol_range(float milage_per_litre,float current_fuel){
          is_fuel_empty(current_fuel);
     }
       void setkey_decreptor() {
          key_decreptor = "PASWORD";
          }
      boolean car_is_locked(){
           if(this.key_decreptor==key_decreptor){
                System.out.println("PASSWORD IS CORRECT ");
                return true;
           }
           else{
                System.out.println("PASSWORD IS IN CORRECT ");
                return false;
           }
      }
  int set_vehicle_sitting_capacity(int capacity){
          vehicle_sitting_capacity=capacity;
          return set_vehicle_sitting_capacity;
      }
      void show_car_properties_main(){
     System.out.println("CAR NO_OF_WHEELS: "+wheels);
     System.out.println("CURRENT SPEED: "+speed);
     System.out.println("NO_OF_SEATS_AVAILABLE: "+vehicle_sitting_capacity);
     System.out.println("CAR STATUS (LOCK OR UNLOCK) : "+obj.car_is_locked());
     System.out.println("");
      }
      vehicle(){
           wheels=4;
      }
 }
 class maruthi_car extends Vehicle {
    private int vehicle_sitting_capacity;
    String engine_name="new_maruth_engine";
    String price="4,50,000_LAKHS";
    private float milage=30.9;
    maruthi_car obj1=new maruthi_car();
    obj1.setkey_decreptor();
    obj1.set_fuel_max_range();
    obj1.current_speed();
    obj1.setspeed();
    void show_car_properties(){
     obj1.show_car_properties_main();
    }
    int set_vehicle_sitting_capacity(int capacity){
         System.out.println("set_vehicle_sitting_capacity  SET TO "+obj1.set_vehicle_sitting_capacity(capacity));
}
}

 public class main_car_runner{
      public static void main(String[] args){
            maruthi_car obj1 = new maruthi_car();
          obj1.show_car_properties();
      }
 }
