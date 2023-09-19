#include<iostream>
using namespace std;
bool is_safe(int **a,int x,int y,int n){
	if(x<n&&y<n&&a[x][y]==1)
	return true;
	else
	return false;
}
bool ratmaze(int **a,int x,int y,int n,int**sol){
	if(x==n-1&&y==n-1){
	sol[x][y]==1;
	return true;
}
	if(is_safe(a,x,y,n)){
		sol[x][y]=1;
		if(ratmaze(a,x+1,y,n,sol))
		{
			return true;
		}
		if(ratmaze(a,x,y+1,n,sol))
		return true;
		sol[x][y]=0;
		return false;
	}
	return false ;
}
int main(){
	int n=5;
	int **a=new int*[n];
	int i,j;
	int **sol=new int*[n];
	for(i=0;i<n;i++){
		a[i]=new int[n];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	

	for(i=0;i<n;i++){
		sol[i]=new int[n];
		for(j=0;j<n;j++){
			sol[i][j]=0;
		}
	}
	if(ratmaze(a,0,0,n,sol)){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<sol[i][j]<<" ";
			}cout<<endl;
		}
	}	
}



