#include<iostream>
using namespace std;
//use reference 16.2
int first_occr(int a[],int n,int i,int key)
{
	if(i==n)  //if index is equla to the size is thenreturn -1 the element is not found//
	return -1;   
	if(a[i]==key)
	return i;
	return first_occr(a,n,i+1,key); //here we starting recursion from 0 and checking from the first element 
	//of the array//
}
int last_occr(int a[],int n,int i,int key)
{
	if(i==n)
	return -1;
	int result=last_occr(a,n,i+1,key);  //in this case first we need to go to last postion then we need to chec//
	//that is why the functioncall appera in the first then we are checking the condintions //
	if(result!=-1){ //if result==-1 then then this will terminate//
	return result;  
}
if(a[i]==key)
	return i;   //if element is found then return index value
	
		return -1; //if element is not found then return -1 which is not found during this particulat recursion call//
		
}







int main(){
	
int a[5]={1,2,3,2,5};
int n=2;
cout<<first_occr(a,5,0,n);
cout<<last_occr(a,5,0,n);
/*cout<<"printing the first occurance of : "<<n<<first_occr(a,5,0,n)<<endl;
cout<<"printitn the last occurance of  : "<<n<<last_occr(a,5,0,n)<<endl;*/
}
