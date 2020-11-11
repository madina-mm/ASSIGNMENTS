#include <stdio.h>


void sort(char *source, char *integers, char *nonIntegers)
{
    
  int i=0;
  int n=0;
  int k=0;
  for( ;source[i]!='\0';i++)
  { 
     if (source[i]>=48 && source[i]<=57)
     {
	     integers[n]=source[i];
	     n++;
     }
     else 
     {
	     nonIntegers[k]=source[i];
	     k++;
     }
  }
  
  integers[n]='\0';
  nonIntegers[k]='\0';

}

int main()
{

char source[] = "abc123def99d#!";
char integers[256];
char nonIntegers[256];

sort(source, integers, nonIntegers);

printf("source: %s\nnonintegers: %s\nintegers: %s\n",source, nonIntegers, integers);

return 0;
}
