#include <stdio.h>
int main(void)
{
    int n1 = 0,n2=1,n3,number;
    for(int i=2;i<10;i++)
    {
        n3 = n1 + n2;
        printf("%d\n",n3);
        n1 = n2;
        n2 = n3;
    }
}