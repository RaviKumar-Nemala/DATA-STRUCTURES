#include<iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
vector<int>ans;
struct node{
     int data;
     node*left;
     node*right;
     node(int dup_data)
     {
          data=dup_data;
          left=NULL;
          right=NULL;
     }
};
void reverse_level_order(node*root){
     if(root==NULL)
     return;
     queue<node*>q;
     stack<node*>st;
     q.push(root);

     while(!q.empty()){
          node* temp=q.front();
          q.pop();
          st.push(temp); //stack lo ki transfer chesukovali
          if(temp->right)
          q.push(temp->right); //first right side node queue loki transfer chesukovali appude manaki left side node stack lo mundu untundi
          if(temp->left)
          q.push(temp->left);
     }
     while(!st.empty()){
          cout<<st.top()->data<<" ";
          st.pop();
     }
}
int main(){
     node *root=new node(1);
     root->left=new node(2);
     root->right= new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     reverse_level_order(root);
}