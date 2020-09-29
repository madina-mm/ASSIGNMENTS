// C program to swap two variables
#include <stdio.h>
int main()
{
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    
    int temp = a;
    a = b;
    b = temp;
    
    printf("Swap results: a = %d, b = %d\n" , a, b);
    return 0;
}
