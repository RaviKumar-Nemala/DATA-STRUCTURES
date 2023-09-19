
public class bitwise_operators {
     public static void main(String[] args) {
          short a=0b1000; //a=8//
          short shifts_right=2;
          //perfoming a>>2//2
          short result =(short)(a>>(shifts_right));
          //result = 0b10; = 2//
          System.out.println("a>>2 = "+result);
          short left_shift=2;
          short left_shift_result=(short)(a<<(left_shift));
          //a=1000//
         // a<<2= 1000_00-> 100000->2^5=32//
          System.out.println("a<<2= "+left_shift_result);
          //performing bitwise and and or and xor operations //////////////////
          byte t=0b1001; //t=9//
          byte u=0b1000 ;//u=8//
           byte bitwise_result=(byte)(t&u);
          System.out.println("9&8= "+bitwise_result);
          bitwise_result=(byte)(t|u);
          //in OR any one becomes true the o/p = true //
          System.out.println("9|8= "+bitwise_result);
          bitwise_result =(byte)(t^u);
          //in xor only on value has to be true /////
          System.out.println("9^8= "+bitwise_result);
     }
}
