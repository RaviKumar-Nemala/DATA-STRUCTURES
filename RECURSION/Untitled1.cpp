#include<iostream>
using namespace std;

void print_total_sub_arrays(int a[],int n){
 int i,j,k;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			for(k=i;k<=j;k++){
				printf("%d ",a[k]);
			}
			printf("\n");
		}
	}
}











int main(){
	int a[4]={-1,4,7,2};
	print_total_sub_arrays(a,4);
	
	
	
}
