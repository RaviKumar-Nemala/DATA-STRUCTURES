#include<iostream>
using namespace std;

struct node{
int data;
node*left;
node*right;
node(int dup_data){
     data=dup_data;
     left=NULL;
     right=NULL;
}
};
typedef struct node node;
int cal_dia(node *root,int *height){
     if(root==NULL){
          *height=0;
          return 0;
     }
     int lh=0;
     int rh=0;
     int ldia=cal_dia(root->left,&lh);  //if the diameter is not passing through the root node then we need to find the max height of the left side
     int rdia=cal_dia(root->right,&rh);//similary we need to find the max height of the right side//then we need to find max of (left ,right diameters)//
      *height=max(lh,rh)+1;//here we are using findingthe the height of the binary tree becaz without knowing the height of the binary tree we can't decide the max dia meter we are using the reference becaz if we declare height function then it takes  some more extrat time(O(n))but in this case we are calculating both height and diameter on a single loop//
      int current_dia=lh+rh+1;//if the dia meter is passing through the root node then this condition should be enough//
     return max(current_dia,max(ldia,rdia));//this is essentially tells the max diameter of a function//
}//NOTE:we are passing the references of lh,rh and collecting with height pointer becaz to modify the values it is necessary//
int main(){
     system("cls");
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->left->left->left= new node(6);
     root->left->left->right=new node(7);

     int heigth=0;
     cout<<cal_dia(root,&heigth)<<" ";
     //cout<<cal_dia(root)<<" ";
          /* 1
          /    \
         2      3
        /        \
        4         5   
       /           
       6            
      /
     7
    /
   8
*/
}