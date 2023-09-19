
class args{
     //HERE TEST ACTS AS THE VAR ARGS BECAUSE IT TAKES THE ANY NUMBER OF INTEGER ARGUMENTS //
     //IT COLLECTS ALL INTEGER ARGUMENTS IN THE FORM OF ARRAY//
     void sum ( int  ... test) //IT COLLECTS ALL ARGUMENTS IN THE FORM OF THE ARRAY
     {
          int sum = 0 ;
          for ( int value :  test )     //using for each we are accesing all the values//
          sum += value;

          System.out.println("PRINTING THE SUM VALUE : " + sum);
     }

     //HERE WE ARE RECEIVING THE MULTIPLE ARRAYS USING VAR ARGUMENT METHOD
     void arrays_sum ( int [] ... test )
     {    
          int k = 1 ;
          for ( int arr[] : test )
          {
           System.out.println("PRINTING THE " + k  + "ARRAY : " );
               for ( int i  : arr ){
               System.out.print(i + " ");
               }
               System.out.println();
               k++;
          }
     }

//THIS METHOD GIVES THE ERROR BECAUSE VAR_ARGS SHOULD BE THE LAST PARAMETER IN THE FUNCTION //

     //void conditions( int ... test ,  String name) //INVALID//
     
    void conditions ( String name , int ...test) { //VALID
         //VALID
}
}
public class var_args_test{
     public static void main(String args[] )
{
     args obj = new args();
     obj.sum( 1,2,3 );//THESE 3 INTEGER ARGUMENTS CAN BE COLLECTED BY USING VAR ARGUMENT//
     obj.sum(1,2,3,4,5); //WE CAN PASS ANY NUMBER OF INTEGER ARGUMENTS //

     //obj.sum(1,2,3,4,5,5,7.77);//IT RETURNS ERROS BECAUSE VAR ARGUMENT RECEIVER END IS INTEGER HERE WE ARE PASSING THE FLOATING POINT//

     int test1[] = {  1 , 2 , 3 };
     int test2[] = {5 ,4 ,3 };
     //HERE WE ARE PASSING THE MULTIPLE ARRAYS USING VAR ARGS//
     obj.arrays_sum(test1 , test2);
}

}
