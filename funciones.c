/*

Resolver en c y en ASM 

r = - ( (a * b + c + 3) * (d - e/2) );

    r1 = (4, 1, 3, 10, 5);
    r2 = (6, 4, 3, 5, 20);

*/




#include <stdio.h>

int func1 (int, int, int, int, int);
int func2 (int, int, int, int, int);

void main()
{
    int r1, r2;

    r1 = func1(4, 1, 3, 10, 5);
    r2 = func1(6, 4, 3, 5, 20);

    printf("\nEn C");
    printf("\n-> r1 = %d \n-> r2 = %d", r1, r2);

    r1 = func2(4, 1, 3, 10, 5);
    r2 = func2(6, 4, 3, 5, 20);

    printf("\n\nEn ASM - Func2");
    printf("\n-> r1 = %d \n-> r2 = %d", r1, r2);

}

int func1 (int a, int b, int c, int d, int e)
{
    int r = 0;

    r = - ( (a * b + c + 3) * (d - e/2) );

    return r;
}

int func2 (int a, int b, int c, int d, int e)
{
    int r = 0;
    
    __asm {
        

    }


    return r;
}
