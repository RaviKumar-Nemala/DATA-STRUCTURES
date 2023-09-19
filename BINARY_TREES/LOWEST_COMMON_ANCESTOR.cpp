#include<iostream>
using namespace std;
#include<vector>
struct node{
     int data;
     node*left;
     node*right;
     node(int dup_data){
          data = dup_data;
          left=NULL;
          right=NULL;
     }
};
typedef struct node node;
bool is_exist(node*root,int key,vector<int>&path){
     if(root==NULL){
          return false;
     }
      path.push_back(root->data);
     if(root->data==key) return true;
     if(is_exist(root->left,key,path) || is_exist(root->right,key,path)) 
     return true;
     else{
          path.pop_back();
          return false;
     }
}
int lowest_common_ancestor(node*root,int n1,int n2){
     vector<int>path1,path2;
     if(is_exist(root,n1,path1)&&is_exist(root,n2,path2)){
     int pc;
     for(pc=0;pc<path1.size()and path2.size();pc++){
          if(path1[pc]!=path2[pc]){
              break;
          }

         
     }
     return path1[pc-1];
     }
     else{
     return -1;
     }
}
int main(){
node *root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->right->right=new node(5);
root->left->left=new node(4);
root->left->right=new node(99);
root->right->left=new node(6);
cout<<"flfjkf"<<" ";
int result=lowest_common_ancestor(root,2,3); 
if(result!=-1){
     cout<<"test 1 has passed"<<endl;
     cout<<"PRINTING THE ANCESTOR"<<": ";
     cout<<result<<endl;
}
else

{

     cout<<"NO PATH HAS BEEN FOUND"<<" ";
     
}
  /*        1
          /    \  
         2      3
        /  \     \
        4   6     5 

*/

}