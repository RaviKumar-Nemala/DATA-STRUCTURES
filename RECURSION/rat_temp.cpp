#include<iostream>
#include<vector>
using namespace std;

bool is_safe(int **a,int row,int col,int n){
	for(int i=0;i<row;i++){
	if(a[i][col]==1){
		return false;
	}
}
int x=row;
int y=col;
while(x>=0 and y>=0){
	if(a[x][y]==1){
		return false;
	}
	x--;
	y--;
}
x=row;
 y=col;
 while(x>=0&&y<col){
	 if(a[x][y]==1){
		return false;
	}
	x--;
	y++;
 }
 return true;
}

bool nqueen(int **a,int row,int n){
	if(row>=n){
		return true;
	}
	for(int i=0;i<n;i++){
	if(is_safe(a,row,i,n)){
		a[row][i]=1;
		if(nqueen(a,row+1,n)){
			return true;
		}
          a[row][i]=0;
	}
	}

return false;
}

int main(){
int n=8;
int **a=new int*[n];
int i,j;
for(i=0;i<n;i++){
	a[i]=new int[n];
	for(j=0;j<n;j++){
		a[i][j]=0;
	}
}
  if(nqueen(a,0,n)){
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		cout<<a[i][j]<<" ";
	}cout<<endl;
}
}
}