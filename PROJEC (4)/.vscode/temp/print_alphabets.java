
class print_alpha_util
{
     void  alphabets_Printing(){
          char ch;
          for( ch='A';ch<='Z';ch++){
               System.out.println(" " + (int)ch);
          }
     }
}


public class print_alphabets {
   public static void main(String[] args) {
          print_alpha_util obj = new print_alpha_util();
          obj.alphabets_Printing();
          
  }
     

}
