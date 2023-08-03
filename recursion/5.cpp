#include<iostream>
using namespace std;
float f(int A[],int i){
	int m;
    if (i==0)  return A[0];
    else{  
	   m=f(A,i-1);
	   if (m>A[i])  return A[i];
	   else return m;}
} 
int main()
{ int A[5]={5,3,1,4,2};
  cout<<f(A,4);
  return 0;}

