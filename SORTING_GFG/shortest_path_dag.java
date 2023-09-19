import java.util.*;
class shortest_path_dag{
     class pair
     {
          int first;
          int second;
          pair(int f,int s)
          {
               this.first=f;
               this.second=s;
          }
     }
     public static void main(String[] args)
     {
          Scanner sc = new Scanner(System.in);
          System.out.println("Enter the vertices");
          int v= sc.nextInt();
          System.out.println("Enter the edges");
          int e=sc.nextInt();
          ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
          for(int i=0;i<=v;i++)
          {
               adj.add(new ArrayList<>());
          }
          //initiliazing
          adj.get(0).add(new pair(2,1));
          
          
     }
}