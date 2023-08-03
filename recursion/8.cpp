#include<stdio.h>
#include<iostream>
using namespace std;
int fact( )
{ static int i=5;
   if(i==0)      return 1;
   else
    { i--;
       return(fact( )*(i+1)); }
}
int main( )
{  
printf("factor of 5!=%d\n",fact());
   return 0;} 

