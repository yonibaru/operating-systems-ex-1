#include <stdio.h>
#include <stdlib.h>
#include "Poisson.h"

int main(){
    long double p1 = poisson(2,1);
    long double p2 = poisson(2,10);
    long double p3 = poisson(2,2);
    long double p4 = poisson(3,3);
    long double p5 = poisson(100,3);
    printf("%Lf\n",p1);
    printf("%Lf\n",p2);
    printf("%Lf\n",p3);
    printf("%Lf\n",p4);
    printf("%Lf\n",p5);
    return 0;
}