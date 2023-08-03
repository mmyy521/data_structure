#include<iostream>
using namespace std;
void fun(int i){   
   if(i>0) fun(i/2);
   cout<<i<<endl; 
}
int main( ){ fun(10); return 0;}

