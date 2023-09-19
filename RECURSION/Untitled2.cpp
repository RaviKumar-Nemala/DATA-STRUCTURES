#include<iostream>
using namespace std;
//use reference 18.1//
bool is_safe(int **a,int x,int y,int n){  //it is used to check that particlar row and colmn element is safe (1) or not //
	if(x<n&&y<n&&a[x][y]==1){ //if that particular element is safe then it returns true//
		return true;
	}
	return false;//otherwise it returns false///
}
bool ratmaze(int **a,int x,int y,int n,int **solarr){ //importantly we are using dynamic reference bacaz we need to backtrack the values//
                                        //we need to change the values//
   if(x==n-1&&y==n-1)  //if the rat reaches the end of the matrix(destination)then last elemnt is become true//
   {
   	solarr[x][y]=1; //we are storing the correct in this array //
   	return true;
	}
	if(is_safe(a,x,y,n)){  //if the particular row and colmn element is safe then we can do further//
		solarr[x][y]=1;
		if(ratmaze(a,x+1,y,n,solarr)){ //first we are moving one block right side that why the row element is incremented by one//
			return true; //if that element is safe we store 1 in that value//
		}
		if(ratmaze(a,x,y+1,n,solarr)){//second we are moving one block down side that why col elment is incremented by one //
			return true;//if that elemnt is safe we store 1 in that value//
		}
		solarr[x][y]=0;//if both are not safe then we store 0 value  //this is called backtracking //
		//because first we are chiecking the value eventhough it is safe after reaching that block and again checking the next block
	   //if that is not givig the correct results we assign our previoius value to false//
	   //in order to do like that we must use the reference values //
		return false;
	}
	return false;
}


int main(){
	int n=5;
	int **a=new int*[n];//it is the actual array////it is used to allocate the memory for rows in array//
	int i,j;
	int **sol=new int*[n]; //here first we are creating the dynamic initialization//
	for(i=0;i<n;i++){ //it is the array where we store the answer value//
		a[i]=new int[n]; //this is used allocate the memory for colmns in the array//
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	

	for(i=0;i<n;i++){
		sol[i]=new int[n]; //use to allocate dynamic memory to the array//

		for(j=0;j<n;j++){
			sol[i][j]=0; //initializing all the array values to zero//
		}
	}
	if(ratmaze(a,0,0,n,sol)){ //we are pasing the actual array // //then ratmaze functionfinds the path ///
	//here we are using reference so the changes are going to impact here////then we simply print here//
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<sol[i][j]<<" "; 
			}cout<<endl;
		}
	}	
}

