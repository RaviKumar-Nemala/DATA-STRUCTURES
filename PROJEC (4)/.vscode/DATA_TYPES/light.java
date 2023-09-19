class light{
     public static void main(String[] args) {
          int no_of_days;
          long time_in_sec;
          long distance;
          long light_speed ;
          no_of_days =1;
          time_in_sec =1*24*60*60;
          light_speed =1860000;
          distance =light_speed*time_in_sec;
          System.out.println("IN "+no_of_days+ " DAY "+" LIGHT TRAVELS " +distance +" meters");
     }
}