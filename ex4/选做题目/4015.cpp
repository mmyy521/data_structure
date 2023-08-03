#include<iostream>
using namespace std;
int Half(int a[],int low,int high,int t)
{
	if(low>high)
	return 0;
	else
	{
		int mid=(high+low)/2;
	if(a[mid]==t)
	return 1;
	else if(a[mid]<t)
	Half(a,mid+1,high,t);
	else if(a[mid]>t)
	Half(a,low,mid-1,t);
	else
	return 0;	
	 } 
}
int main()
{
	while(1)
	{
		int a[100];
	int n;
	cin>>n;
	if(n==0)
	return 0;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int t;
	cin>>t;
	int yes=Half(a,0,n-1,t);
	if(yes==1)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	}
	
 } 
