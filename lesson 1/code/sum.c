#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 0;
    for(int i = 0;i<=100;i++){
        sum = sum + i;
    }
    printf("%d\n", sum);
}
