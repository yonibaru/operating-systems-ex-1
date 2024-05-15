#include <stdio.h>

int stackOverflow(){
    stackOverflow();
}

int main(){
    stackOverflow();
    return 0;
}