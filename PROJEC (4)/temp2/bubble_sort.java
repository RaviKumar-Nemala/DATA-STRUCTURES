class sort_the_list{
     public void elements_sort(int arr[])
     {
          int i,j;
          for(i=0;i<arr.length ; i++)
          {
               for(j=0;j<arr.length ;j++)
               {
                    if(arr[j] > arr[i])
                    {
                         int temp=arr[j];
                         arr[j]=arr[i];
                         arr[i]=temp;
                    }
               }
          }
          for(int k=0; k< arr.length ;k++)
          {
          System.out.println(arr[k]);
          }

         // print(arr);
     }
/*
     public void print(int arr[])
     {
          for(int i=0; i< arr.length ;i++)
          {
          System.out.println(arr[i]);
          }
     }
}
*/
}


class merge_sort
{
     int i,j;
     int mid;
     int n1,n2;
     void merge_elements(int arr[], int low, int high)
     {
          while(low < high)
          {
               mid=(low+high)/2;
               merge_elements(arr, low , mid);
               merge_elements(arr,mid+1,high);
               merge(arr,low,mid,high);
          }
     }

     void merge(int arr[] , int low ,int mid , int high )
     {
          i=low;
          j=high;
          n1=(mid-low +1);
          n2=(high-mid);
          
     }
}
class bubble_sort {
     public static void main(String args[])
     {
          int arr[]={5,4,3,2,1};
          sort_the_list obj= new sort_the_list();
          obj.elements_sort(arr);
     }

}
