#include <stdio.h>
const int undef_add = 0xdeadbeef;
int main(){
    int *ptr = (int*)undef_add;
    printf("%d",*ptr);
    return 0;
}