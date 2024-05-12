#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

//Support of a Poisson Distribution is strictly Natural numbers therefore 
//factorial() recieves and returns an integer.
int factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

long double poisson(long double lambda,int k){
    return (pow(lambda,k)/factorial(k)) * expf(-lambda);
}

